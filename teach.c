#include "sw.h"
#include "menu.h"
#include "teach.h"
#include "sigmoid.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void readTDFile(double td[][3], double *to, char *fileName)
{
  FILE *in;
  in = fopen(fileName, "r");
  fseek(in, 0, SEEK_SET);
  fscanf(in, "%lf %lf %lf , %lf", &td[0][0], &td[0][1], &td[0][2], &to[0]);
  fscanf(in, "%lf %lf %lf , %lf", &td[1][0], &td[1][1], &td[1][2], &to[1]);
  fscanf(in, "%lf %lf %lf , %lf", &td[2][0], &td[2][1], &td[2][2], &to[2]);
  fscanf(in, "%lf %lf %lf , %lf", &td[3][0], &td[3][1], &td[3][2], &to[3]);
  fclose(in);
}

void selectTD(double td[][3], double *to)
{
  char selection;
  while (selection != 'b')
  {
    system("clear");
    printf("           SELECTION MENU\n");
    printf(" ------------------------------------\n");
    printf("| '1' - lesson_1.txt                 |\n");
    printf("| '2' - lesson_2.txt                 |\n");
    printf("| '3' - lesson_3.txt                 |\n");
    printf("| 'b' - BACK                         |\n");
    printf(" ------------------------------------\n");
    scanf("%c", &selection);
    switch (selection)
    {
    case '1':
      system("clear");
      readTDFile(td, to, "lesson_1.txt");
      printTD(td, to);
      printf("\nThe TRAINING DATA is loaded from current directory: \"lesson_1.txt\"\n");
      printf("Press [Enter] to continue . . .\n");
      pause();
      pause();
      break;
    case '2':
      system("clear");
      readTDFile(td, to, "lesson_2.txt");
      printTD(td, to);
      printf("\nThe TRAINING DATA is loaded from current directory: \"lesson_2.txt\"\n");
      printf("Press [Enter] to continue . . .\n");
      pause();
      pause();
      break;
    case '3':
      system("clear");
      readTDFile(td, to, "lesson_3.txt");
      printTD(td, to);
      printf("\nThe TRAINING DATA is loaded from current directory: \"lesson_3.txt\"\n");
      printf("Press [Enter] to continue . . .\n");
      pause();
      pause();
      break;
    default:
      break;
    }
  }
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

void transposeTD(double td[][3], double transpose[][4])
{

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j <= 3; j++)
    {
      transpose[j][i] = td[i][j];
    }
  }
}

double dotProduct(double *td_var, double *to, int size)
{
  double result = 0;
  for (int i = 0; i < size; i++)
  {
    result += td_var[i] * to[i];
  }
  return result;
}

void thinkTrain(double *sw, double td[][3], double *temp_output)
{
  temp_output[0] = sigmoid(dotProduct(&td[0][0], sw, 3));
  temp_output[1] = sigmoid(dotProduct(&td[1][0], sw, 3));
  temp_output[2] = sigmoid(dotProduct(&td[2][0], sw, 3));
  temp_output[3] = sigmoid(dotProduct(&td[3][0], sw, 3));
}

void train(double *sw, double td[][3], double *to, double transpose[][4], char *file_name, int iterations)
{
  double error[4] = {0};
  double adjustments[3] = {0};
  double temp_output[4] = {0};
  readTDFile(td, to, file_name);
  // printTD(td, to);
  transposeTD(td, transpose);

  // printf("%s\n", file_name);
  // for (int i = 0; i < 3; i++)
  // {
  //   for (int j = 0; j < 4; j++)
  //   {
  //     printf("%lf ", transpose[i][j]);
  //   }
  //   printf("\n");
  // }

  for (int k = 0; k < iterations; k++)
  {
    thinkTrain(sw, td, temp_output);

    //sigmoid(input dot product wheits)
    for (int i = 0; i < 4; i++)
    {
      error[i] = (to[i] - temp_output[i]) * sigmoid_derivative(temp_output[i]);
    }

    //The adjustments to WEIGHTS is calculated here
    adjustments[0] = dotProduct(&transpose[0][0], error, 4);
    adjustments[1] = dotProduct(&transpose[1][0], error, 4);
    adjustments[2] = dotProduct(&transpose[2][0], error, 4);

    //Here we add the ADJUSTMENTS to the WEIGHTS
    sw[0] = sw[0] + adjustments[0];
    sw[1] = sw[1] + adjustments[1];
    sw[2] = sw[2] + adjustments[2];
  }
}