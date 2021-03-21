/**
 * @file bmp_generator.c
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Fuctions for dealing with BMP files are defined here.
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "bmp_generator.h"
#include "analyse.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * @brief This function is writing BMP File header to the file.
 * 
 * @param[in] out - pointer to FILE.  
 * @param[in] header - pointer to bmpHeader variable which will be writen to the file
 */
void writeBmpHeader(FILE *out, bmpHeader *header)
{
  fwrite(&header->type, sizeof(header->type), 1, out);
  fwrite(&header->size, sizeof(header->size), 1, out);
  fwrite(&header->reserved1, sizeof(header->reserved1), 1, out);
  fwrite(&header->reserved2, sizeof(header->reserved2), 1, out);
  fwrite(&header->offset, sizeof(header->offset), 1, out);
  fwrite(&header->dib_header_size, sizeof(header->dib_header_size), 1, out);
  fwrite(&header->width_px, sizeof(header->width_px), 1, out);
  fwrite(&header->height_px, sizeof(header->height_px), 1, out);
  fwrite(&header->num_planes, sizeof(header->num_planes), 1, out);
  fwrite(&header->bits_per_pixel, sizeof(header->bits_per_pixel), 1, out);
  fwrite(&header->compression, sizeof(header->compression), 1, out);
  fwrite(&header->image_size_bytes, sizeof(header->image_size_bytes), 1, out);
  fwrite(&header->x_resolution_ppm, sizeof(header->x_resolution_ppm), 1, out);
  fwrite(&header->y_resolution_ppm, sizeof(header->y_resolution_ppm), 1, out);
  fwrite(&header->num_colors, sizeof(header->num_colors), 1, out);
  fwrite(&header->important_colors, sizeof(header->important_colors), 1, out);
}

/**
 * @brief Get the Bmp Header object with the height of 'y' and width of 'x' pixels.
 * @warning The maximum resolution is 1200 x 1200 pixels. If you want higher resolution, you need to change data types of inner variables.
 * 
 * @param[in] x - int value. Width of the image 
 * @param[in] y - int value. Hight of the picture 
 * @param[in] padding - pointer to int. Padding requaired for each row of pixels in the bit map, it is calculated with respect to the resolution of the image. This value will be used in another function of rendering the picture.  
 * @return bmpHeader* - the return value is an address of the BMP header
 */
bmpHeader *getBmpHeader(int x, int y, int *padding)
{
  int padding_local = 0; //(((x * 3) % 4) - 4) * (-1);
  if ((x * 3) % 4 != 0)
  {
    padding_local = 4 - ((x * 3) % 4);
  }
  *padding = padding_local;
  if (padding_local != 0)
  {
    padding_local = y * padding_local;
  }
  // *padding = padding_local;
  bmpHeader *picture_header;
  picture_header = malloc(sizeof(bmpHeader) * 1);
  picture_header->type = 0x4d42;                           // Magic identifier: 0x4d42
  picture_header->size = 54 + (x * y * 3) + padding_local; // File size in bytes - 134 bytes
  picture_header->reserved1 = 0;                           // Not used
  picture_header->reserved2 = 0;                           // Not used
  picture_header->offset = 0x36;                           // Offset to image data  (54 bytes)
  picture_header->dib_header_size = 0x28;                  // DIB Header size in bytes (40 bytes)
  picture_header->width_px = x;                            // Width of the image
  picture_header->height_px = y;                           // Height of image
  picture_header->num_planes = 0x01;                       // Number of color planes
  picture_header->bits_per_pixel = 0x18;                   // Bits per pixel
  picture_header->compression = 0x0;                       // Compression type
  picture_header->image_size_bytes = 0x50;                 // Image size in bytes
  picture_header->x_resolution_ppm = 0x0EC4;               // Pixels per meter
  picture_header->y_resolution_ppm = 0x0EC4;               // Pixels per meter
  picture_header->num_colors = 0x0;                        // Number of colors
  picture_header->important_colors = 0x0;                  // Important colors

  return picture_header;
}

/**
 * @brief Create a Bmp Picture object. The function will ask user to enter resolution of the image to create, and it will generate an image filled with a random RED colore pixels using neurones function obtainRandomRGB(sw, rgb).
 * 
 * @param[in] sw - pointer to double (double array). Synaptic weights. 
 */
void createBmpPicture(double *sw)
{
  FILE *out;
  int padding_bit = 0;
  bmpHeader *header;
  double stop = 0;
  int y, x;
  double rgb[3] = {0};

  system("clear");
  printf("Enter HIGHT of the picture: ");
  scanf("%d", &y);
  printf("Enter WIDTH of the picture: ");
  scanf("%d", &x);
  printf("\n");

  header = getBmpHeader(x, y, &padding_bit);

  y = header->height_px;
  x = header->width_px;

  Pixel img_arr[y][x];
  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {
      obtainRandomRGB(sw, rgb);

      img_arr[i][j].red = (uint8_t)rgb[0];
      img_arr[i][j].green = (uint8_t)rgb[1];
      img_arr[i][j].blue = (uint8_t)rgb[2];
    }
  }

  printf("Number of RGB pixels = %lu\n", sizeof(img_arr) / 3);
  printf("Number of padding bits addet to each row = %d\n", padding_bit);

  out = fopen("img.bmp", "wb");
  writeBmpHeader(out, header);

  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {
      fwrite(&img_arr[i][j].blue, sizeof(img_arr[i][j].blue), 1, out);
      fwrite(&img_arr[i][j].green, sizeof(img_arr[i][j].green), 1, out);
      fwrite(&img_arr[i][j].red, sizeof(img_arr[i][j].red), 1, out);
    }
    for (int p = 0; p < padding_bit; p++)
    {
      fwrite(&padding_bit, 1, 1, out);
    }
  }
  fclose(out);
}

/**
 * @brief This function will read BMP File header.
 * @warning The header have to be exactly 54 bytes format. The format of the header can be checked from bmp_generator.h
 * 
 * @param[in] header - pointer to bmpHeader data type. The readed header will be stored here. 
 * @param[in] file_name - FILE pointer. Pointer to the file you want to read header from. 
 */
void readBmpHeader(bmpHeader *header, char *file_name)
{
  printf("Start reading\n");
  FILE *fp;
  fp = fopen(file_name, "rb");

  fseek(fp, 0, SEEK_SET);
  fread(&header->type, sizeof(uint16_t), 1, fp);
  fread(&header->size, sizeof(uint32_t), 1, fp);
  fread(&header->reserved1, sizeof(uint16_t), 1, fp);
  fread(&header->reserved2, sizeof(uint16_t), 1, fp);
  fread(&header->offset, sizeof(uint32_t), 1, fp);
  fread(&header->dib_header_size, sizeof(uint32_t), 1, fp);
  fread(&header->width_px, sizeof(uint32_t), 1, fp);
  fread(&header->height_px, sizeof(uint32_t), 1, fp);
  fread(&header->num_planes, sizeof(uint16_t), 1, fp);
  fread(&header->bits_per_pixel, sizeof(uint16_t), 1, fp);
  fread(&header->compression, sizeof(uint32_t), 1, fp);
  fread(&header->image_size_bytes, sizeof(uint32_t), 1, fp);
  fread(&header->x_resolution_ppm, sizeof(uint32_t), 1, fp);
  fread(&header->y_resolution_ppm, sizeof(uint32_t), 1, fp);
  fread(&header->num_colors, sizeof(uint32_t), 1, fp);
  fread(&header->important_colors, sizeof(uint32_t), 1, fp);
  printf("END of reading\n");
}