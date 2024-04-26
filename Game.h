#ifndef _GAME_H
#define _GAME_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include "utils.h"
#include <vector>
class Game
{
private:
      bool replay = false;
      int check = 1;
      bool isRunning;
      int dx = 0;
      bool rotate_;
      bool fast;
      bool done = true;
      bool pause = false,isPressed,beginGame,chooseSpeed;
      int randomColor = 0;
      int point;
      int target;
      int level;
      int speed = 0,randomPiece = -1,gameSpeed = 1000;
      Uint32 moveTime = 0;
      std::vector<int> highestScore;
      SDL_Event event;
 //     Mix_Music* playingMusic;
      SDL_Texture* menuBackGround = NULL;
      SDL_Texture* backGround = NULL;
      LTexture HIGHScore;
      LTexture Start;
      LTexture Exit;
      LTexture Score;
      LTexture Line;
      LTexture LevelTexture;
      LTexture scoreTexture;
      LTexture replayTexture;
      LTexture exitTexture;
      SDL_Window *gWindow = NULL;
      SDL_Renderer *gRenderer = NULL;
      TTF_Font* gFont = NULL;
      TTF_Font* gFont1 = NULL;
      TTF_Font* gFont2 = NULL;

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

