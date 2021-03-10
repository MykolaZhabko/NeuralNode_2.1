#include "teach.h"
#include "sw.h"
#include "menu.h"
#include "analyse.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
  srand(time(NULL));
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
