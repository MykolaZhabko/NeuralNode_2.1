/**
 * @file analyse.c
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Definitions of the analysing functions of the neurone
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "sw.h"
#include "menu.h"
#include "teach.h"
#include "sigmoid.h"
#include "analyse.h"
#include "bmp_generator.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief One of the most important functions in this project. The function require trained synaptic weights and RGB value to analyse. It will return the result from 0 to 1 which coresponds to 0% ... to 100% of probability that inputing RGB is red color.
 * 
 * @param[in] sw - pointer to double (double array). Sunaptic weights.
 * @param[in] rgb - pointer to double (double array). The RGB value to analyse. 
 * @return double - output result of the analyse. 
 */
double analyseRGB(double *sw, double *rgb)
{
  double result;
  result = dotProduct(rgb, sw, 3);
  return sigmoid(result);
}

/**
 * @brief This function will ask user to input RGB value and it will be analysed by neurone, and finally will print in console the result of the analysed in percent of probability that color is red.  
 * 
 * @param[in] sw - pointer to double (double array). Synaptic weights. 
 */
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

/**
 * @brief Function will generate a random colors and neurone will analyse it until it finds a color with probability to be RED 78% or higher. Than it will create a URL to the web resourse where you can check the result.
 * 
 * @param[in] sw - pointer to double (double array). Synaptic weights. 
 */
void generateRGB(double *sw)
{
  double rgb[3] = {0};
  double stop = 0;

  while (stop <= 0.78) //<Threshold is 78% of red color probability
  {
    rgb[0] = (double)(rand() % 255) / 255;
    rgb[1] = (double)(rand() % 255) / 255;
    rgb[2] = (double)(rand() % 255) / 255;
    stop = analyseRGB(sw, rgb);
  }
  system("clear");
  printf("R = %3.0lf. G = %3.0lf. B = %3.0lf\n", rgb[0] = rgb[0] * 255, rgb[1] = rgb[1] * 255, rgb[2] = rgb[2] * 255);
  stop = 0;

  printf("\nYour color can be checked here: " ANSI_COLOR_RED "https://colorpicker.me/#%02x%02x%02x" ANSI_COLOR_RESET "\n\n", (int)rgb[0], (int)rgb[1], (int)rgb[2]);
}

/**
 * @brief The function will generate random RGB value with 90%..100% probability of the red color.
 * 
 * @param[in] sw - pointer to double (double array). Synaptic weights. 
 * @param[in] rgb - pointer to double (double array). The result will be stored in this array (RGB value) 
 */
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