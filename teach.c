#include "sw.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void loadTD(double td[][3], double *to)
{
  FILE *in;
  in = fopen("lesson_1.txt", "r");
  fseek(in, 0, SEEK_SET);
  fscanf(in, "%lf %lf %lf , %lf", &td[0][0], &td[0][1], &td[0][2], &to[0]);
  fscanf(in, "%lf %lf %lf , %lf", &td[1][0], &td[1][1], &td[1][2], &to[1]);
  fscanf(in, "%lf %lf %lf , %lf", &td[2][0], &td[2][1], &td[2][2], &to[2]);
  fclose(in);
}

void printTD(double td[][3], double *to)
{
  printf("\tR\tG\tB\t Output\n");
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("\t%.2lf", td[i][j]);
    }
    printf("\t ->| %.1lf\n", to[i]);
  }
}