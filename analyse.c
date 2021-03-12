#include "sw.h"
#include "menu.h"
#include "teach.h"
#include "sigmoid.h"
#include "analyse.h"
#include "bmp_generator.h"
#include <stdlib.h>
#include <stdio.h>

double analyseRGB(double *sw, double *rgb)
{
  double result;
  result = dotProduct(rgb, sw, 3);
  return sigmoid(result);
}

void isRGBRed(double *sw)
{
  double rgb[3] = {0};
  int r, g, b;
  printf("RED\t :");
  scanf("%d", &r);
  printf("GREEN\t :");
  scanf("%d", &g);
  printf("BLUE\t :");
  scanf("%d", &b);

  rgb[0] = (double)r / 255;
  rgb[1] = (double)g / 255;
  rgb[2] = (double)b / 255;

  int prob = (int)(analyseRGB(sw, rgb) * 100);
  printf("\nPROBABILITY: %d%%\n", prob);
  if (prob < 80)
  {
    printf("NOT A RED COLOR\n");
  }
  else
  {
    printf("RED COLOR\n\n");
  }
}

void generateRGB(double *sw)
{
  double rgb[3] = {0};
  double stop = 0;

  while (stop < 0.78)
  {
    rgb[0] = (double)(rand() % 255) / 255;
    rgb[1] = (double)(rand() % 255) / 255;
    rgb[2] = (double)(rand() % 255) / 255;
    stop = analyseRGB(sw, rgb);
    // printf("%lf\n", stop);
  }
  system("clear");
  printf("R = %3.0lf. G = %3.0lf. B = %3.0lf\n", rgb[0] = rgb[0] * 255, rgb[1] = rgb[1] * 255, rgb[2] = rgb[2] * 255);
  stop = 0;

  printf("\nYour color can be checked here: " ANSI_COLOR_RED "https://colorpicker.me/#%02x%02x%02x" ANSI_COLOR_RESET "\n\n", (int)rgb[0], (int)rgb[1], (int)rgb[2]);
}

void obtainRandomRGB(double *sw, double *rgb)
{
  double stop = 0;
  while (stop < 0.9)
  {
    rgb[0] = (double)(rand() % 255) / 255;
    rgb[1] = (double)(rand() % 255) / 255;
    rgb[2] = (double)(rand() % 255) / 255;
    stop = analyseRGB(sw, rgb);
  }
  rgb[0] = rgb[0] * 255;
  rgb[1] = rgb[1] * 255;
  rgb[2] = rgb[2] * 255;
}