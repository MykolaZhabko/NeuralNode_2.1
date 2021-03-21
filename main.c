/**
 * @file main.c
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Main function of the project.
 * @version 0.1
 * @date 2021-03-21
 * 
 * @warning This project contains functionality which uses SDL2 library. First you need to instal SDL2 to your machine.
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "teach.h"
#include "sw.h"
#include "menu.h"
#include "analyse.h"
#include "node.h"
#include "image_analyse.h"
#include <stdio.h>
#include <stdlib.h>
#include "sdl_test.h"
#include <time.h>

int main(int argc, char const *argv[])
{
  srand(time(NULL)); ///< initialisation of random sead
  node redNode;
  nodeInit(&redNode);

  do
  {
    system("clear");
    actionMenu(&redNode.menu, redNode.sw, redNode.td, redNode.to, redNode.transpose);
  } while (redNode.menu != 'q');

  system("clear");
  printf("DONE.\n\n");
  return 0;
}
