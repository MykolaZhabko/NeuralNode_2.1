/**
 * @file sdl_test.c
 * @author Zhabko Mykola (mykola.zhabko@gmail.com)
 * @brief Definition of the functions related to SDL2 library use.
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include "analyse.h"
#include "sdl_test.h"
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

///< Utility macros
#define CHECK_ERROR(test, message)              \
    do                                          \
    {                                           \
        if ((test))                             \
        {                                       \
            fprintf(stderr, "%s\n", (message)); \
            exit(1);                            \
        }                                       \
    } while (0)

///< Window dimensions
static const int width = 500;
static const int height = 300;

/**
 * @brief Function is Initialising SDL, creating window and render the random Red color using function obtainRandomRGB(sw, rgb). Whith each click of the mouse it will render new red color which is selected by our neurone.
 * @warning Before creating window the 'sw' synaptic weights have to be teached to recognise RED color.
 * 
 * @param[in] sw - 1D array of double. Synaptic weights 
 */
void startWindow(double *sw)
{
    double rgb[3] = {0};
    obtainRandomRGB(sw, rgb);

    ///< Initialize SDL
    CHECK_ERROR(SDL_Init(SDL_INIT_VIDEO) != 0, SDL_GetError());

    ///< Create an SDL window
    SDL_Window *window = SDL_CreateWindow("Rundom RED color", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    CHECK_ERROR(window == NULL, SDL_GetError());

    ///< Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    CHECK_ERROR(renderer == NULL, SDL_GetError());

    ///< Initial renderer color

    SDL_SetRenderDrawColor(renderer, (int)rgb[0], (int)rgb[1], (int)rgb[2], 255);
    system("clear");
    printf("R:%d  G:%d  B:%d\n", (int)rgb[0], (int)rgb[1], (int)rgb[2]);
    bool running = true;
    SDL_Event event;
    while (running)
    {
        ///< Process events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                obtainRandomRGB(sw, rgb);
                SDL_SetRenderDrawColor(renderer, (int)rgb[0], (int)rgb[1], (int)rgb[2], 255);
                system("clear");
                printf("R:%d  G:%d  B:%d\n", (int)rgb[0], (int)rgb[1], (int)rgb[2]);
            }
        }

        ///< Clear screen
        SDL_RenderClear(renderer);

        ///< Draw
        ///< Show what was drawn
        SDL_RenderPresent(renderer);
    }

    ///< Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
