/**
 * @file node.c
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Definition of the functions declared int node.h
 * @version 0.1
 * @date 2021-03-20
 * 
 * @copyright Copyright (c) 2021s
 * 
 */
#include "node.h"

/**
 * @brief Initialization of the fields of the node.
 * 
 * @param core - pointer of the 'node' type
 */
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