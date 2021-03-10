#include "node.h"

void nodeInit(node *core)
{
  core->menu = 0;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      core->td[i][j] = 0;
      core->transpose[i][j] = 0;
    }
    core->sw[i] = 0;
    core->to[i] = 0;
  }
}