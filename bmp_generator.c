#include "bmp_generator.h"
#include "analyse.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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