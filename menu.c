#include "sw.h"
#include "math.h"
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
  printf("| 'q' - QUIT                         |\n");
  printf(" ------------------------------------\n");
  scanf("%c", menu);
}

void actionMenu(char *menu, double *sw)
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

  default:
    break;
  }
}