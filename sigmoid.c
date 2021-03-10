/*File containce Sigmoid function implementation*/
#include "sigmoid.h"
#include <math.h>

float sigmoid(float x)
{
	return 1 / (1 + expf(-x));
}

/* argument x is a result of sigmoid(arg) function*/
float sigmoid_derivative(float x)
{
	return x * (1 - x);
}
