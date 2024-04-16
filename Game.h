#ifndef _GAME_H
#define _GAME_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include "utils.h"

class Game
{
private:
      bool isRunning;
      int dx = 0;
      bool rotate_,fast;
      bool done = false;
      bool pause = false,isPressed,beginGame,chooseSpeed;
      int randomColor = 0;
      int point;
      int target;
      int level;
      int speed = 0,randomPiece = -1,gameSpeed = 1000;
      Uint32 moveTime = 0;
      SDL_Event event;
      Mix_Music* playingMusic;
      SDL_Texture* backGround = NULL;
      SDL_Texture* blocks = NULL;
      LTexture Score;
      LTexture Line;
      LTexture LevelTexture;
//      LTexture InstructionTexture;
//      LTexture QuitTexture;
//      LTexture textTexture;
      SDL_Window *gWindow = NULL;
      SDL_Renderer *gRenderer = NULL;
      TTF_Font* gFont = NULL;
      TTF_Font* gFont1 = NULL;


public:
        Game();
        ~Game();
        void init(const char* title, int xPos, int yPos, int SCREEN_WIDTH, int SCREEN_HEIGHT);
        void loadMedia();
        void playGame();
        void handleEvents(SDL_Event event);
        void nextTetromino();
        bool collision();
        void updateRenderer();
        void updateField(SDL_Rect &rect, const int x, const int y);
        void clean();
        void init();
        bool running()
        {
            return isRunning;
        }

};
#endif // _GAME_H
