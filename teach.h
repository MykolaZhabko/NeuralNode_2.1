/**
 * @file teach.h
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Declaration of the functions related to teaching process of neurone.
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

void selectTD(double td[][3], double *to);
void printTD(double td[][3], double *to);
void readTDFile(double td[][3], double *to, char *fileName);

double dotProduct(double *td_var, double *to, int size);
void transposeTD(double td[][3], double transpose[][4]);
void thinkTrain(double *sw, double td[][3], double *temp_output);
void train(double *sw, double td[][3], double *to, double transpose[][4], char *file_name, int iterations);
