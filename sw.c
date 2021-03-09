#include "sw.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void randomizeSW(double *sw)
{
  sw[0] = ((float)(rand() % 20000) / 10000) - 1;
  sw[1] = ((float)(rand() % 20000) / 10000) - 1;
  sw[2] = ((float)(rand() % 20000) / 10000) - 1;
}

void saveSW(double *sw)
{
  FILE *out;
  out = fopen("weights.txt", "w");
  fprintf(out, "%lf %lf %lf", sw[0], sw[1], sw[2]);
  fclose(out);
}
void loadSW(double *sw)
{
  FILE *in;
  in = fopen("weights.txt", "r");
  fseek(in, 0, SEEK_SET);
  fscanf(in, "%lf %lf %lf", &sw[0], &sw[1], &sw[2]);
  fclose(in);
}
void clearSW(double *sw)
{
  sw[0] = 0;
  sw[1] = 0;
  sw[2] = 0;
}

void printSW(double *sw)
{
  printf("          Synaptic Weights\n");
  printf(" ------------------------------------\n");
  printf("| " ANSI_COLOR_RED); //start red color
  printf("Red\t -\t%lf", sw[0]);
  printf(ANSI_COLOR_RESET "\t     | \n"); // set color to default

  printf("| " ANSI_COLOR_GREEN); //start red color
  printf("Green\t -\t%lf", sw[1]);
  printf(ANSI_COLOR_RESET "\t     | \n"); // set color to default

  printf("| " ANSI_COLOR_BLUE); //start red color
  printf("Bblue\t - \t%lf", sw[2]);
  printf(ANSI_COLOR_RESET "\t     | \n"); // set color to default

  printf(" ------------------------------------\n");
}