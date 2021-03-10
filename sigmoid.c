/*File containce Sigmoid function implementation*/
#include "sigmoid.h"
#include <math.h>

double sigmoid(double x)
{
	return 1 / (1 + expf(-x));
}

/* argument x is a result of sigmoid(arg) function*/
double sigmoid_derivative(double x)
{
	return x * (1 - x);
}
