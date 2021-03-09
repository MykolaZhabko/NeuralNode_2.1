#include "sw.h"
#include <time.h>
#include <stdlib.h>

void randomizeSW(double *sw)
{
  sw[0] = ((float)(rand() % 20000) / 10000) - 1;
  sw[1] = ((float)(rand() % 20000) / 10000) - 1;
  sw[2] = ((float)(rand() % 20000) / 10000) - 1;
}

void saveSW()
{
}
void loadSW(double *sw)
{
}
void clearSW(double *sw)
{
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