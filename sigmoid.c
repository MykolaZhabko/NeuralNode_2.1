/**
 * @file sigmoid.c
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Definitions of the Sigmoid and Sigmoid derivative functions
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "sigmoid.h"
#include <math.h>

/**
 * @brief Sigmoid function. It will compress any number in range from 0 to 1. This function is the main function in this project.
 * 
 * @param[in] x - double. The number to compress 
 * @return double - The result of sigmoid function 
 */
double sigmoid(double x)
{
	return 1 / (1 + expf(-x));
}

/**
 * @brief Sigmoid derivative function. Used to calculate an error during teaching process.
 * 
 * @param[in] x - double. The result of the Sigmoid function 
 * @return double - result of the Sigmoid derivative function
 */
double sigmoid_derivative(double x)
{
	return x * (1 - x);
}
