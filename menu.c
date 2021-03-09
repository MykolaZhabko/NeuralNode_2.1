#include "sw.h"
#include "teach.h"
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
  printf("| '1' - Show synaptic weights        |\n");
  printf("| '2' - RANDOMIZE synaptic weights   |\n");
  printf("| '3' - CLEAR synaptic weights       |\n");
  printf("| '4' - SAVE synaptic weights        |\n");
  printf("| '5' - LOAD synaptic weights        |\n");
  printf("| '6' - LOAD and SHOW TEACHING DATA  |\n");
  printf("| 'q' - QUIT                         |\n");
  printf(" ------------------------------------\n");
  scanf("%c", menu);
}

void actionMenu(char *menu, double *sw, double td[][3], double *to)
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
    loadTD(td, to);
    printTD(td, to);
    printf("The TRAINING DATA is loaded from current directory: \"lesson_1.txt\"\n");
    printf("Press [Enter] to continue . . .\n");
    pause();
    pause();
    break;
  default:
    break;
  }
}