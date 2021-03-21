/**
 * @file menu.c
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Definitions of the MENU functions  
 * @version 0.1
 * @date 2021-03-20
 * 
 * @copyright Copyright (c) 2021
 */
#include "node.h"
#include "sw.h"
#include "teach.h"
#include "sigmoid.h"
#include "analyse.h"
#include "image_analyse.h"
#include "bmp_generator.h"
#include "sdl_test.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief This function is just for fun! It creates a downloading or processing animation 0%....100% ..Ready
 * 
 * @param[in] prosent - integer number which is equal the percent value you want to visualise 10% or 20%
 */
void progress(int prosent)
{
  printf("PROGRESS:");
  for (int i = 0; i < prosent / 2; i++)
  {
    printf("\u2593");
  }
  for (int i = 0; i < 50 - prosent / 2; i++)
  {
    printf("\u2519");
  }
  printf(":%d%%\n", prosent);
}

/**
 * @brief The function is used to create a pause in the UI of the app and simply require to press return to continue
 * 
 */
void pause(void)
{
  char pause;
  // printf("Press [Enter] to continue . . .\n");
  scanf("%c", &pause);
}

/**
 * @brief For printing the menu (User interface). It prints the text and graphical elements with determined layout for main menu.
 * 
 * @param[in] char* menu  - the character for state machine '1','2','3'... 'q'
 */
void printMenu(char *menu)
{
  printf(ANSI_COLOR_CYAN);
  printf("\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e\n");
  printf("\u2503            M   E   N   U           \u2503 \n");
  printf("\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f\n");
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
  printf("| 'I' - Image analyse                |\n");
  printf("| 'W' - Show window rundom color(SDL)|\n");
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

/**
 * @brief This function is for representing main menu of the application.
 * @param[in] char* menu - User input '1', '2' ... and so on
 * @param[in] double* sw - synaptic weights of the neurone
 * @param[in] double[4][3] td - teaching data for neurone, set of RGB values in the form of 4x3 array
 * @param[in] double* to - predetermined by user output to the teachibg data '0' if not red and '1' if red
 * @param[in] double[3][4] transpose - the transpose of the teching data
 */
void actionMenu(char *menu, double *sw, double td[][3], double *to, double transpose[][4])
{
  printMenu(menu);
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
  case 'I':
    system("clear");
    selectPicture(sw);
    break;
  case 'W':
    system("clear");
    if (sw[0] == 0 && (sw[1]) == 0 && (sw[2]) == 0)
    {
      printSW(sw);
      printf(ANSI_COLOR_YELLOW);
      printf("\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e\n");

      printf("\u2503        THE SYNAPTIC WEIGHTS        \u2503\n");
      printf("\u2503   OF THE NEURONE ARE NOT TRAINED !!\u2503\n");
      printf("\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f\n");
      printf(ANSI_COLOR_RESET);
      printf("Press [Enter] to continue . . .\n");
      pause();
      pause();
    }
    else
    {
      startWindow(sw);
    }
    break;
  default:
    break;
  }
}