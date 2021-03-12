#include <stdio.h>
#include <stdint.h>

typedef struct Pixel
{
  uint8_t red, green, blue;
} Pixel;

int main(int argc, char const *argv[])
{
  FILE *fp;

  uint16_t type = 0x4d42;            // Magic identifier: 0x4d42
  uint32_t size = 0x249F36;          // File size in bytes - 134 bytes
  uint16_t reserved1 = 0;            // Not used
  uint16_t reserved2 = 0;            // Not used
  uint32_t offset = 0x36;            // Offset to image data  (54 bytes)
  uint32_t dib_header_size = 0x28;   // DIB Header size in bytes (40 bytes)
  int32_t width_px = 800;            // Width of the image
  int32_t height_px = 1000;          // Height of image
  uint16_t num_planes = 0x01;        // Number of color planes
  uint16_t bits_per_pixel = 0x18;    // Bits per pixel
  uint32_t compression = 0x0;        // Compression type
  uint32_t image_size_bytes = 0x50;  // Image size in bytes
  int32_t x_resolution_ppm = 0x0EC4; // Pixels per meter
  int32_t y_resolution_ppm = 0x0EC4; // Pixels per meter
  uint32_t num_colors = 0x0;         // Number of colors
  uint32_t important_colors = 0x0;   // Important colors

  Pixel img[800000];
  uint8_t one_byte;

  fp = fopen("boat_cut.bmp", "rb");
  long int counter = 0;

  // fseek(fp, 0L, SEEK_END);
  // counter = ftell(fp);

  fseek(fp, 0, SEEK_SET);
  for (int i = 0; i < 800000; i++)
  {

    fread(&one_byte, sizeof(uint8_t), 1, fp);
    img[i].red = one_byte;
    fread(&one_byte, sizeof(uint8_t), 1, fp);
    img[i].green = one_byte;
    fread(&one_byte, sizeof(uint8_t), 1, fp);
    img[i].blue = one_byte;
    fread(&one_byte, sizeof(uint8_t), 1, fp);
  }

  printf("%02x %02x %02x\n", img[0].blue, img[0].green, img[0].red);
  printf("%02x %02x %02x\n", img[1].blue, img[1].green, img[1].red);
  printf("%02x %02x %02x\n", img[799999].blue, img[799999].green, img[799999].red);
  // printf("\n ZISE = %ld\n", counter);
  fclose(fp);

  FILE *out;
  out = fopen("remake.bmp", "wb");
  fwrite(&type, sizeof(uint16_t), 1, out);
  fwrite(&size, sizeof(uint32_t), 1, out);
  fwrite(&reserved1, sizeof(uint16_t), 1, out);
  fwrite(&reserved2, sizeof(uint16_t), 1, out);
  fwrite(&offset, sizeof(uint32_t), 1, out);
  fwrite(&dib_header_size, sizeof(uint32_t), 1, out);
  fwrite(&width_px, sizeof(uint32_t), 1, out);
  fwrite(&height_px, sizeof(uint32_t), 1, out);
  fwrite(&num_planes, sizeof(uint16_t), 1, out);
  fwrite(&bits_per_pixel, sizeof(uint16_t), 1, out);
  fwrite(&compression, sizeof(uint32_t), 1, out);
  fwrite(&image_size_bytes, sizeof(uint32_t), 1, out);
  fwrite(&x_resolution_ppm, sizeof(uint32_t), 1, out);
  fwrite(&y_resolution_ppm, sizeof(uint32_t), 1, out);
  fwrite(&num_colors, sizeof(uint32_t), 1, out);
  fwrite(&important_colors, sizeof(uint32_t), 1, out);

  //here we write picture bytes in file. I our case we have 80 bytes
  fwrite(&img, sizeof(Pixel) * 800000, 1, out);

  fclose(out);

  return 0;
}
