#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_
#include<SDL.h>
#include<map>
#include<vector>

struct Point
{
    int x;
    int y;
};

class GameState
{
    Point tmpPiece[4],piece[4];
    Point nextPieces[4];
    Point currentTetrads[4];
    Point next1Tetrads[4];
    Point next2Tetrads[4];
    const int figures[7][4] =
    {
        {1,3,5,7},
        {2,4,5,7},
        {3,5,4,6},
        {3,5,4,7},
        {2,3,5,7},
        {3,5,7,6},
        {2,3,4,5},
    };
    int board[24][10],countPiece,tmpBoard[24][10];
    const int PIECE_SIZE = 30.5;
    bool mark[25][10];
    bool canMove;
    std::map<std::pair<int,int>,int> mp;
    const int BOARD_WIDTH = 10;
    const int BOARD_HEIGHT = 24;

public:

    void moveLeftRight(int dx);
    void generatePiece(int randomPiece);
    void moveDown();
    void rotate_();
    bool isCollision() const;
    void initBoard();
    void restorePieces();
    void getColorLanded(int randomColor);
    bool checkGameOver() const;
    void initPiece();
    void deleteStatusPiece(int randomColor);
    void showIdlePiece(SDL_Renderer* gRenderer);
    void showActivePiece(SDL_Renderer* gRenderer,int randomColor);
    void checkAndClearFilledRows(int& score, int& target,int& level);
    bool isBoardFull();
    void draw_falling_piece(SDL_Renderer *gRenderer);
    int findLastEmptyRowInColumn(int col) const;
    Point generateNewPiece();
    void updateNextPieces();
    void renderNextPieces(SDL_Renderer* gRenderer,int randomColor);
};
#endif // _GAMEMOVEMENT_H_


