/**
 * @file image_analyse.h
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Declaration of the functions to analyse the BMP images
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdint.h>
void readPicture(double *sw, char *file_name, uint8_t *rgb_user, float *threshold);
void selectPicture(double *sw);
void aboutImgAnalyse();
void selectAnalyseSettings(double *sw, char *file_name);