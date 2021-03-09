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

  do
  {
    system("clear");
    printMenu(&menu);
    // pause();
    actionMenu(&menu, sw);
  } while (menu != 'q');

  // randomizeSW(sw);
  // printSW(sw);

  return 0;
}
