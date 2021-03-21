/**
 * @file bmp_generator.h
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief The functions which are dealing with BMP file format is declared here, and two data types for Pixel and bmpHeader
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdint.h>
#include <stdio.h>
/**
 * @brief The structure for RGB value which is a pixel in bit map image.
 * 
 */
typedef struct Pixel
{
  uint8_t red, green, blue;
} Pixel;

/**
 * @brief Structure for BMP File header. 54 bytes of data
 * 
 */
typedef struct bmpHeader
{
  uint16_t type;             ///< Magic identifier: 0x4d42
  uint32_t size;             ///< File size in bytes
  uint16_t reserved1;        ///< Not used
  uint16_t reserved2;        ///< Not used
  uint32_t offset;           ///< Offset to image data  (54 bytes)
  uint32_t dib_header_size;  ///< DIB Header size in bytes (40 bytes)
  int32_t width_px;          ///< Width of the image
  int32_t height_px;         ///< Height of image
  uint16_t num_planes;       ///< Number of color planes
  uint16_t bits_per_pixel;   ///< Bits per pixel
  uint32_t compression;      ///< Compression type
  uint32_t image_size_bytes; ///< Image size in bytes
  int32_t x_resolution_ppm;  ///< Pixels per meter
  int32_t y_resolution_ppm;  ///< Pixels per meter
  uint32_t num_colors;       ///< Number of colors
  uint32_t important_colors; ///< Important colors
} bmpHeader;

bmpHeader *getBmpHeader(int x, int y, int *padding);
void createBmpPicture(double *sw);
void readBmpHeader(bmpHeader *header, char *file_name);
void writeBmpHeader(FILE *fp, bmpHeader *header);