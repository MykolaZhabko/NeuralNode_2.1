/**
 * @file teach.c
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Definition of the functions related to teaching process of the neurone.
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
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Reading file containing teaching data. 
 * Format: R G B , Output
 *         1 0 0 , 1
 *         0 1 0 , 0
 * 
 * 
 * @param[in] td - 2D array of double. Teaching data array
 * @param[in] to - 1D array of double. Output  
 * @param[in] fileName - String constant. File name or path to the file with teaching data.
 */
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

/**
 * @brief Selection of the three available files with teaching data. The files can be modified by user using any text editor.
 * 
 * @param[in] td - 2D array of double. Teaching data array
 * @param[in] to - 1D array of double. Output  
 */
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

/**
 * @brief Printing the information about selected teaching data to the console.
 * 
 * @param[in] td - 2D array of double. Teaching data array
 * @param[in] to - 1D array of double. Output  
 */
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

/**
 * @brief Transpose of the matrix.
 * 
 * @param[in] td - 2D array of double. Teaching data array 
 * @param[in] transpose - 2D array of double. Transpose of teaching data array 
 */
void transposeTD(double td[][3], double transpose[][4])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      transpose[j][i] = td[i][j];
    }
  }
}

/**
 * @brief Dot product of the vectors with similar amount of components.
 * 
 * @param[in] td - 1D array of double. Vector 1
 * @param[in] sw - 1D array of double. Vector 2
 * @param[in] size - int value. Size of the vector 
 * @return double  - The result of dot product.
 */
double dotProduct(double *td, double *sw, int size)
{
  double result = 0;
  for (int i = 0; i < size; i++)
  {
    result += td[i] * sw[i];
  }
  return result;
}

/**
 * @brief Calculation of the temporary output result which is compared in future with real result from user.
 * 
 * @param[in] sw - 1D array of double. Current synaptic weights.
 * @param[in] td - 1D array of double. Teaching data from user.
 * @param[in] temp_output - 1D array of double. Temparary result for red color.
 */
void thinkTrain(double *sw, double td[][3], double *temp_output)
{

  temp_output[0] = sigmoid(dotProduct(&td[0][0], sw, 3));
  temp_output[1] = sigmoid(dotProduct(&td[1][0], sw, 3));
  temp_output[2] = sigmoid(dotProduct(&td[2][0], sw, 3));
  temp_output[3] = sigmoid(dotProduct(&td[3][0], sw, 3));
}

/**
 * @brief Main training function.
 * 
 * @param[in] sw - 1D array of double. Current synaptic weights.
 * @param[in] td - 1D array of double. Teaching data from user.
 * @param[in] to - 1D array of double. Output.  
 * @param[in] transpose - 2D array of double. Transpose of teaching data array.
 * @param[in] file_name - path to the file with teaching data
 * @param[in] iterations - number of lessons for the node.
 */
void train(double *sw, double td[][3], double *to, double transpose[][4], char *file_name, int iterations)
{
  double error[4] = {0};
  double adjustments[3] = {0};
  double temp_output[4] = {0};
  readTDFile(td, to, file_name);
  printTD(td, to);
  transposeTD(td, transpose);

  printf("%s\n", file_name);
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      printf("%lf ", transpose[i][j]);
    }
    printf("\n");
  }

  for (int k = 0; k < iterations; k++)
  {
    thinkTrain(sw, td, temp_output);

    for (int i = 0; i < 4; i++)
    {
      error[i] = (to[i] - temp_output[i]) * sigmoid_derivative(temp_output[i]);
    }

    adjustments[0] = dotProduct(&transpose[0][0], error, 4);
    adjustments[1] = dotProduct(&transpose[1][0], error, 4);
    adjustments[2] = dotProduct(&transpose[2][0], error, 4);

    sw[0] = sw[0] + adjustments[0];
    sw[1] = sw[1] + adjustments[1];
    sw[2] = sw[2] + adjustments[2];
  }
}