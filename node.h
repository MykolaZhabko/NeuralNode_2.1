/**
 * @file node.h
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Header file for NODE instance 
 * @version 0.1
 * @date 2021-03-20
 * 
 * @copyright Copyright (c) 2021ss
 * 
 */

typedef struct node
{
  char menu;              //< character for flow control of the menu
  double sw[3];           //< synaptic weights of the neurone
  double td[4][3];        //< teaching data for neurone (RGB values)
  double to[4];           //< output of the teaching data (determined by user)
  double transpose[3][4]; //< Transpose of the teaching data matrix
} node;

/**
 * @brief Initialization of the node 
 * 
 * @param[in] core - Pointer of the node datatype  
 */
void nodeInit(node *core);
