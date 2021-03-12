#include "bmp_generator.h"
#include "analyse.h"
#include "image_analyse.h"
#include "menu.h"
#include "sw.h"
#include <stdlib.h>
#include <stdio.h>

void aboutImgAnalyse()
{
  printf(ANSI_COLOR_YELLOW);
  printf("\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e\n");

  printf("\u2503  The NEURON will analyse an image     \u2503\n");
  printf("\u2503  you selected and it will detect      \u2503\n");
  printf("\u2503  the RED color pixels with precision  \u2503\n");
  printf("\u2503  from 20%% to 100%% and save  the       \u2503\n");
  printf("\u2503  resulting image in local repository. \u2503\n");
  printf("\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f\n");
  printf(ANSI_COLOR_RESET);
}

void selectAnalyseSettings(double *sw, char *file_name)
{
  float pros = -1;
  int r = 255, g = 255, b = 255;    //for threshold
  uint8_t rgb[3] = {255, 255, 255}; //for replacement color
  char selection = 0;
  while (selection != 'b')
  {
    system("clear");
    printf("\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e\n");

    printf("\u2503          SETTINGS                  \u2503\n");
    printf("\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f\n");
    printf(" ------------------------------------\n");
    printf("| '1' - SET ACCEPTION THRESHOLD IN %% |\n");
    printf("|       FOR RED COLOR.(Default 20%%)  |\n");
    printf("| '2' - SELECT COLOR TO REPLASE NOT  |\n");
    printf("|       RED COLOR.(Defaulr - WHITE)  |\n");
    printf("| 'S' - START!                       |\n");
    printf(" ------------------------------------\n");
    printf("| 'b' - BACK                         |\n");
    printf(" ------------------------------------\n");
    scanf("%c", &selection);
    switch (selection)
    {
    case '1':
      system("clear");
      printf("Enter threshold: ");
      scanf("%f", &pros);
      break;
    case '2':
      system("clear");
      printf("Enter RED\t(0..255) : ");
      scanf("%d", &r);
      printf("Enter GREEN\t(0..255) : ");
      scanf("%d", &g);
      printf("Enter BLUE\t(0..255) : ");
      scanf("%d", &b);
      break;
    case 'S':
      system("clear");
      if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
      {
        printf("WRONG SETTINGS OF RGB COLOR!\n");
        printf("DEFAULT SETTINGS FOR RGB IS WHITE COLOR:\n");
        printf("R = 255.\n");
        printf("G = 255.\n");
        printf("B = 255.\n\n");
      }
      else
      {
        rgb[0] = (uint8_t)r;
        rgb[1] = (uint8_t)g;
        rgb[2] = (uint8_t)b;
      }
      if (pros < 0 || pros > 100)
      {
        printf("WRONG SETTINGS FOR THRESHOLD!\n");
        printf("DEFAULT SETTINGS FOR THRESHOLD IS 20%%:\n\n");
        pros = 0.2;
      }
      else
      {
        pros = pros / 100.0;
      }

      readPicture(sw, file_name, rgb, &pros);
      printf(ANSI_COLOR_RED);
      printf("\nThe picture is saved in local repository: \"boat_result.bmp\"\n");
      printf(ANSI_COLOR_RESET);
      printf("Press [Enter] to continue . . .\n");
      selection = 'q';
      pause();
      pause();
      break;
    default:
      break;
    }
  }
}

void readPicture(double *sw, char *file_name, uint8_t *rgb_user, float *threshold)
{
  printf("R:%d  G:%d  B:%d\n", rgb_user[0], rgb_user[1], rgb_user[2]);
  printf("TRESHOLD: %f\n", *threshold);
  bmpHeader header;
  FILE *fp;
  uint8_t one_byte = 0;
  double rgb[3] = {0};

  int image_size = 0;

  fp = fopen(file_name, "rb");
  fseek(fp, 0L, SEEK_END);
  image_size = ftell(fp);

  fclose(fp);

  printf("Size of file is: %d bytes\n", image_size);

  readBmpHeader(&header, file_name);
  int x = header.width_px;
  int y = header.height_px;

  int padding_bytes = 0; //(((x * 3) % 4) - 4) * (-1);
  if ((x * 3) % 4 != 0)
  {
    padding_bytes = 4 - ((x * 3) % 4);
  }

  if (padding_bytes != 0)
  {
    padding_bytes = y * padding_bytes;
  }

  Pixel img[x * y];

  // Reading color pixels with padding
  fp = fopen(file_name, "rb");
  fseek(fp, 54, SEEK_SET);

  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {
      fread(&img[i * x + j].blue, sizeof(uint8_t), 1, fp);
      fread(&img[i * x + j].green, sizeof(uint8_t), 1, fp);
      fread(&img[i * x + j].red, sizeof(uint8_t), 1, fp);
    }
  }

  fclose(fp);

  fp = fopen("boat_result.bmp", "wb");
  writeBmpHeader(fp, &header);
  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {
      rgb[0] = (double)img[i * x + j].red / 255;
      rgb[1] = (double)img[i * x + j].green / 255;
      rgb[2] = (double)img[i * x + j].blue / 255;

      if (analyseRGB(sw, rgb) > *threshold)
      {
        fwrite(&img[i * x + j].blue, sizeof(img[i * x + j].blue), 1, fp);
        fwrite(&img[i * x + j].green, sizeof(img[i * x + j].green), 1, fp);
        fwrite(&img[i * x + j].red, sizeof(img[i * x + j].red), 1, fp);
      }
      else
      {
        img[i * x + j].red = rgb_user[0];
        img[i * x + j].green = rgb_user[1];
        img[i * x + j].blue = rgb_user[2];
        // fwrite(&one_byte, sizeof(img[i * x + j].blue), 1, fp);
        // fwrite(&one_byte, sizeof(img[i * x + j].green), 1, fp);
        // fwrite(&one_byte, sizeof(img[i * x + j].red), 1, fp);
        fwrite(&img[i * x + j].blue, sizeof(img[i * x + j].blue), 1, fp);
        fwrite(&img[i * x + j].green, sizeof(img[i * x + j].green), 1, fp);
        fwrite(&img[i * x + j].red, sizeof(img[i * x + j].red), 1, fp);
      }
    }
    for (int p = 0; p < padding_bytes; p++)
    {
      fwrite(&one_byte, 1, 1, fp);
    }
  }
  fclose(fp);

  printf("Pixel number: %d\n", x * y);
  printf("Padding bytes added to eash row: %d\n", padding_bytes);
  *threshold = -1;
  // printf("= %02x\n", b);
}

void selectPicture(double *sw)
{
  char selection;
  while (selection != 'b')
  {
    system("clear");
    printSW(sw);
    if (sw[0] == 0 && (sw[1]) == 0 && (sw[2]) == 0)
    {
      printf(ANSI_COLOR_YELLOW);
      printf("\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e\n");

      printf("\u2503        THE SYNAPTIC WEIGHTS        \u2503\n");
      printf("\u2503   OF THE NEURONE ARE NOT TRAINED !!\u2503\n");
      printf("\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f\n");
      printf(ANSI_COLOR_RESET);
    }

    printf("\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e\n");

    printf("\u2503          SELECTION MENU            \u2503\n");
    printf("\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f\n");
    printf(" ------------------------------------\n");
    printf("| '1' - boat.bmp                     |\n");
    printf("| '2' -                              |\n");
    printf("| '3' -                              |\n");
    printf(" ------------------------------------\n");
    printf("| '4' - READ ABOUT THIS ANALYSE      |\n");
    printf(" ------------------------------------\n");
    printf("| 'b' - BACK                         |\n");
    printf(" ------------------------------------\n");
    scanf("%c", &selection);
    switch (selection)
    {
    case '1':
      system("clear");
      selectAnalyseSettings(sw, "boat.bmp");
      pause();
      break;
    case '4':
      system("clear");
      aboutImgAnalyse();
      printf("Press [Enter] to continue . . .\n");
      pause();
      pause();
      break;
    default:
      break;
    }
  }
}