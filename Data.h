#ifndef Data_h
#define Data_h
#include<iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#define SDL_ERROR 1
#define IMG_ERROR 2
#define MIX_ERROR 3
#define TTF_ERROR 4
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const std::string gBackGroundPicture = "img/background.png";
const std::string grid_frame = "img/background.png";
const std::string playingM = "music/playing.wav";
const int BlockW = 36;
const int BlockH = 36;
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 24;
void LogError(std::string msg, int error_code = SDL_ERROR);
#endif // Data_h

