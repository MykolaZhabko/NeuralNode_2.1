#include "sw.h"
#include "teach.h"
#include "sigmoid.h"
#include "analyse.h"
#include "bmp_generator.h"
#include <stdio.h>
#include <stdlib.h>
void progress(int prosent)
{
  printf("PROGRESS:");
  for (int i = 0; i < prosent / 2; i++)
  {
    // printf("\u2500\u2501\n");
    printf("\u2593");
  }
  for (int i = 0; i < 50 - prosent / 2; i++)
  {
    printf("\u2591");
  }
  printf(":%d%%\n", prosent);
}

void pause(void)
{
  char pause;
  // printf("Press [Enter] to continue . . .\n");
  scanf("%c", &pause);
}

void printMenu(char *menu)
{
  printf(ANSI_COLOR_CYAN);
  printf("             M   E   N   U \n");
  printf(ANSI_COLOR_RESET);
  printf(ANSI_COLOR_MAGENTA);
  printf(" ------------------------------------\n");
  printf("|     WEIGHTS AND REVIEW OPTION      |\n");
  printf("|     -------------------------      |\n");
  printf("| '1' - Show synaptic weights        |\n");
  printf("| '2' - RANDOMIZE synaptic weights   |\n");
  printf("| '3' - CLEAR synaptic weights       |\n");
  printf("| '4' - SAVE synaptic weights        |\n");
  printf("| '5' - LOAD synaptic weights        |\n");
  printf("| '6' - SHOW TEACHING DATA (-> LOAD) |\n");
  printf(" ------------------------------------ \n");
  printf(ANSI_COLOR_RESET);
  printf(ANSI_COLOR_YELLOW);
  printf(" ------------------------------------ \n");
  printf("|         TEACHING OPTIONS           |\n");
  printf("|     -------------------------      |\n");
  printf("| '7' - START TEACHING (3 tr. sets)  |\n");
  printf(" ------------------------------------ \n");
  printf(ANSI_COLOR_RESET);
  printf(ANSI_COLOR_GREEN);
  printf(" ------------------------------------ \n");
  printf("|          TESTING OPTIONS           |\n");
  printf("|     -------------------------      |\n");
  printf("| '8' - Enter RGB for testing        |\n");
  printf("| '9' - Generate random RED color    |\n");
  printf("| 'B' - Generate random BMP Picture  |\n");
  printf("|       with RED color               |\n");
  //  printf("\"2\" - Enter RGB for testing\n");
  //   printf("\"3\" - Generate random RED color\n");
  //   printf("\"4\" - Generate random BMP Picture with RED color\n");
  printf(" ------------------------------------ \n");
  printf(ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED);
  printf(" ------------------------------------ \n");
  printf("|           'q' - QUIT               |\n");
  printf(" ------------------------------------\n");
  printf(ANSI_COLOR_RESET);
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
    system("clear");
    progress(10);
    train(sw, td, to, transpose, "lesson_1.txt", 10000);
    system("clear");
    progress(33);
    train(sw, td, to, transpose, "lesson_2.txt", 10000);
    system("clear");
    progress(66);
    train(sw, td, to, transpose, "lesson_3.txt", 10000);
    system("clear");
    progress(100);
    printf("\n");
    printSW(sw);
    printf("Press [Enter] to continue . . .\n");
    pause();
    pause();
    break;
  case '8':
    system("clear");
    isRGBRed(sw);
    printf("Press [Enter] to continue . . .\n");
    pause();
    pause();
    break;
  case '9':
    system("clear");
    generateRGB(sw);
    printf("Press [Enter] to continue . . .\n");
    pause();
    pause();
    break;
  case 'B':
    system("clear");
    createBmpPicture(sw);
    printf("Press [Enter] to continue . . .\n");
    pause();
    pause();
    break;
  default:
    break;
  }
}