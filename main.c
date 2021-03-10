#include "teach.h"
#include "sw.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
  system("clear");
  srand(time(NULL));
  char menu;
  double sw[3] = {0};
  double td[4][3] = {0};
  double to[4] = {0};
  double transpose[3][4] = {0};
  do
  {
    system("clear");
    printMenu(&menu);
    actionMenu(&menu, sw, td, to, transpose);
  } while (menu != 'q');

  system("clear");
  printf("DONE.\n\n");
  return 0;
}
