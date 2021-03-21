/**
 * @file sw.h
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Definitions of functions related to Synaptic weights data. 
 * 
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "sw.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Randomise synaptic weights in range -1..1.
 * 
 * @param[in] sw -  pointer to double (double array). Synaptic weights
 */
void randomizeSW(double *sw)
{
  sw[0] = ((float)(rand() % 20000) / 10000) - 1;
  sw[1] = ((float)(rand() % 20000) / 10000) - 1;
  sw[2] = ((float)(rand() % 20000) / 10000) - 1;
}

/**
 * @brief Saving the synaptic weights current stage to the file "weights.txt" in current repository. 
 * 
 * @param[in] sw -  pointer to double (double array). Synaptic weights
 */
void saveSW(double *sw)
{
  FILE *out;
  out = fopen("weights.txt", "w");
  fprintf(out, "%lf %lf %lf", sw[0], sw[1], sw[2]);
  fclose(out);
}

/**
 * @brief Loading the data for synaptic weights from file in R - w1, G - w2, B - w3  
 * 
 * @param[in] sw -  pointer to double (double array). Synaptic weights
 */
void loadSW(double *sw)
{
  FILE *in;
  in = fopen("weights.txt", "r");
  fseek(in, 0, SEEK_SET);
  fscanf(in, "%lf %lf %lf", &sw[0], &sw[1], &sw[2]);
  fclose(in);
}

/**
 * @brief Resets synaptic weights to zero
 * 
* @param[in] sw -  pointer to double (double array). Synaptic weights
 */
void clearSW(double *sw)
{
  sw[0] = 0;
  sw[1] = 0;
  sw[2] = 0;
}

/**
 * @brief Printing te information about current synaptic weights.
 * 
 * @param[in] sw -  pointer to double (double array). Synaptic weights
 */
void printSW(double *sw)
{
  printf("          Synaptic Weights\n");
  printf(" ------------------------------------\n");
  printf("| " ANSI_COLOR_RED);
  printf("Red\t -\t%lf", sw[0]);
  printf(ANSI_COLOR_RESET "\t     | \n");

  printf("| " ANSI_COLOR_GREEN);
  printf("Green\t -\t%lf", sw[1]);
  printf(ANSI_COLOR_RESET "\t     | \n");

  printf("| " ANSI_COLOR_BLUE);
  printf("Bblue\t - \t%lf", sw[2]);
  printf(ANSI_COLOR_RESET "\t     | \n");

  printf(" ------------------------------------\n");
}