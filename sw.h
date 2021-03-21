/**
 * @file sw.h
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Declaration of functions related to Synaptic weights data. And definitions of text color macroses.
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void randomizeSW(double *sw);
void saveSW(double *sw);
void loadSW(double *sw);
void clearSW(double *sw);
void printSW(double *sw);
