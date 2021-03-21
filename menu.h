/**
 * @file menu.h
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Header file for MENU functions declarations.
 * @version 0.1
 * @date 2021-03-20
 * 
 * @copyright Copyright (c) 2021ss
 * 
 */

void printMenu(char *menu);
void actionMenu(char *menu, double *sw, double td[][3], double *to, double transpose[][4]);
void pause(void);
void progress(int prosent);
