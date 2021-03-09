#include <stdio.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

void randomizeSW(double *sw);
void saveSW(double *sw);
void loadSW(double *sw);
void clearSW(double *sw);
void printSW(double *sw);
