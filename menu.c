#include "sw.h"
#include "teach.h"
#include "sigmoid.h"
#include <stdio.h>
#include <stdlib.h>

void pause(void)
{
  char pause;
  // printf("Press [Enter] to continue . . .\n");
  scanf("%c", &pause);
}

void printMenu(char *menu)
{
  printf("               MENU\n");
  printf(" ------------------------------------\n");
  printf("|     WEIGHTS AND REVIEW OPTION      |\n");
  printf("|     -------------------------      |\n");
  printf("| '1' - Show synaptic weights        |\n");
  printf("| '2' - RANDOMIZE synaptic weights   |\n");
  printf("| '3' - CLEAR synaptic weights       |\n");
  printf("| '4' - SAVE synaptic weights        |\n");
  printf("| '5' - LOAD synaptic weights        |\n");
  printf("| '6' - SHOW TEACHING DATA (-> LOAD) |\n");
  printf("|------------------------------------|\n");
  printf("|         TEACHING OPTIONS           |\n");
  printf("|     -------------------------      |\n");
  printf("| '7' - START TEACHING (3 tr. sets)  |\n");
  printf("|------------------------------------|\n");
  printf("|           'q' - QUIT               |\n");
  printf(" ------------------------------------\n");
  scanf("%c", menu);
}

void actionMenu(char *menu, double *sw, double td[][3], double *to, double transpose[][4])
{
  switch (*menu)
  {
  case '1':
    system("clear");
    printSW(sw);
    printf("Press [Enter] to continue . . .\n");
    pause();
    pause();
    break;
  case '2':
    system("clear");
    randomizeSW(sw);
    printSW(sw);
    printf("Press [Enter] to continue . . .\n");
    pause();
    pause();
    break;
  case '3':
    system("clear");
    clearSW(sw);
    printSW(sw);
    printf("Press [Enter] to continue . . .\n");
    pause();
    pause();
    break;
  case '4':
    system("clear");
    saveSW(sw);
    printf("The SYNAPTIC WEIGHTS are saved in current directory: \"weights.txt\"\n");
    printf("Press [Enter] to continue . . .\n");
    pause();
    pause();
    break;
  case '5':
    system("clear");
    loadSW(sw);
    printSW(sw);
    printf("The SYNAPTIC WEIGHTS is loaded from current directory: \"weights.txt\"\n");
    printf("Press [Enter] to continue . . .\n");
    pause();
    pause();
    break;
  case '6':
    system("clear");
    selectTD(td, to);
    // printTD(td, to);
    break;
  case '7':
    system("clear");
    // void train(double *sw, double td[][3], double *to, double transpose[][4], char *file_name, int iterations)
    train(sw, td, to, transpose, "lesson_1.txt", 10000);
    train(sw, td, to, transpose, "lesson_2.txt", 10000);
    train(sw, td, to, transpose, "lesson_3.txt", 10000);
    printf("Press [Enter] to continue . . .\n");
    pause();
    pause();
    break;
  default:
    break;
  }
}