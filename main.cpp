#include "Data.h"
#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "Game.h"
using namespace std;
int main(int argc, char *args[])
{
    srand(time(0));
    Game* game = new Game;
    game -> init("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);


while (game->running())
    {
    game -> loadMedia();
    game -> playGame();
    }

     game -> clean();
}
