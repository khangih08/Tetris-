#include "GameState.h"
#include "utils.h"
#include "Data.h"
#include "iostream"
using namespace std;
void GameState::moveLeftRight(int dx)
{
    for(int i = 0; i < 4;i++)
    {
        tmpPiece[i] = piece[i];
        piece[i].x += dx;
   }

}
void GameState::generatePiece(int randomPiece)
{
    for (int i = 0; i < 4 ; i++)
    {
        piece[i].x = figures[randomPiece][i] % 2 + 4;
        piece[i].y = figures[randomPiece][i] / 2 ;

    }

}
 void GameState::moveDown()
 {
     for(int i = 0; i < 4; i++)
        {
            tmpPiece[i] = piece[i];
            piece[i].y++;
        }
}
void GameState:: rotate_()
{
    Point pivot = piece[1];
    for(int i = 0 ; i < 4; i++)
    {
        int xNewRotate = -piece[i].y;
        int yNewRotate = piece[i].x;
        piece[i].x = xNewRotate +(pivot.x + pivot.y);
        piece[i].y = yNewRotate +(pivot.y - pivot.x);
    }

}
bool GameState::isCollision() const{

    for(int i = 0; i < 4; i++){

        if(piece[i].x < 0 || piece[i].x >= BOARD_WIDTH || piece[i].y >= BOARD_HEIGHT -1)
            return true;
        else{

            if(board[piece[i].y + 1][piece[i].x]!=0)
                return true;
            }
        }
    return false;
}
void GameState::initBoard()
{
    for(int i = 0; i < BOARD_HEIGHT; i++)
        for(int j = 0; j < BOARD_WIDTH; j++)
            board[i][j] = 0;
}
void GameState::deleteStatusPiece(int randomColor)
{
    if (!isCollision()) {
        for (int i = 0; i < 4; i++) {
            board[piece[i].y][piece[i].x] = 0;
        }
        for (int i = 0; i < 4; i++) {
            tmpPiece[i] = piece[i];
            piece[i].y++;
        }
        for (int i = 0; i < 4; i++) {
            board[piece[i].y][piece[i].x] = randomColor;
        }
    }
}
void GameState::restorePieces()
{
    for(int i = 0; i < 4; i++){
        piece[i] = tmpPiece[i];
        }
}

void GameState::getColorLanded(int randomColor)
{
    for(int i = 0; i < 4; i++){
        board[tmpPiece[i].y + 1][tmpPiece[i].x] = randomColor;
        }
}

bool GameState::checkGameOver() const{
    for(int i = 0; i < 10; i++)
        if(board[4][i] != 0)
            return true;
    return false;
}

void GameState::initPiece(){
    for(int i = 0; i < 4 ; i++)
    {
        piece[i].x = piece[i].y = 0;
        tmpPiece[i].x = tmpPiece[i].y = 0;
    }
}

void GameState::showIdlePiece(SDL_Renderer* gRenderer)
{
    for(int i = 4;i <= 23;i++)
        for(int j = 0; j < 10;j++)
            {
                SDL_Rect idlePiece;
                if(board[i][j] == 0) continue;
                int centerX = SCREEN_WIDTH / 2 - (PIECE_SIZE * 10) / 2;
                int centerY = SCREEN_HEIGHT / 2 - (PIECE_SIZE * 20) / 2;
                int pieceX = 490 + j * PIECE_SIZE;
                int pieceY = 31 + (i - 4) * PIECE_SIZE;
                createRect(idlePiece, pieceX, pieceY, PIECE_SIZE, PIECE_SIZE);
                colorSelect(gRenderer,board[i][j]);
                SDL_RenderFillRect(gRenderer,&idlePiece);
            }
}

void GameState::showActivePiece(SDL_Renderer* gRenderer,int randomColor){
    for(int i = 0; i < 4; i++)
    {
        if(piece[i].y > 3)
            {
            board[piece[i].y-1][piece[i].x] = 0;
            SDL_Rect activePiece;
            int centerX = SCREEN_WIDTH / 2 - (PIECE_SIZE * 10) / 2;
            int centerY = SCREEN_HEIGHT / 2 - (PIECE_SIZE * 20) / 2;
            int pieceX = 490 + piece[i].x * PIECE_SIZE;
            int pieceY = 31 + (piece[i].y - 3) * PIECE_SIZE;
            createRect(activePiece, pieceX, pieceY, PIECE_SIZE, PIECE_SIZE);
                colorSelect(gRenderer,randomColor);
                SDL_RenderFillRect(gRenderer,&activePiece);
            }
}
}
void GameState::checkAndClearFilledRows(int& score, int& target, int& level) {
    for (int y = BOARD_HEIGHT - 1; y >= 0; --y) {
        bool rowFilled = true;
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            if (board[y][x] == 0) {
                rowFilled = false;
                break;
            }
        }
        if (rowFilled) {
            for (int yy = y; yy > 0; --yy) {
                for (int x = 0; x < BOARD_WIDTH; ++x) {
                    board[yy][x] = board[yy - 1][x];
                }
            }

            for (int x = 0; x < BOARD_WIDTH; ++x) {
                board[0][x] = 0;
            }
            target++;
            score += 100;
            if (score >= 1000) {
                level++;
                score = 0;
            }
            ++y;
        }
    }
}
bool GameState::isBoardFull() {
    for (int i = 0; i < 4; ++i) {
        if (piece[i].y < 0) {
            return true;
        }
    }
    return false;
}
int GameState::findLastEmptyRowInColumn(int col) const {
    for (int row = BOARD_HEIGHT - 1; row >= 0; --row) {
        if (board[row][col] == 0 || (board[row][col] != 0 && row == BOARD_HEIGHT - 1)) {
            return row;
        }
    }
    return -1;
}
void GameState::draw_falling_piece(SDL_Renderer *gRenderer) {
    int cellWidth = PIECE_SIZE;
    int cellHeight = PIECE_SIZE;
    // board[i][j]
    int minY = piece[0].y;
    for (int i = 1; i < 4; ++i) {
        if (piece[i].y < minY) {
            minY = piece[i].y;
        }
    }
//    int stop = 100;
//    for(int i = 0; i < 4; i++){
//        int tmp = piece[i].y/cellHeight;
//        while(tmp < 23 && board[tmp+1][piece[i].x] == 0){
//            tmp++;
//        }
//        stop = std::min(stop, tmp-piece[i].y);
//    }
    for (int i = 0; i < 4; ++i) {
        int x = piece[i].x * cellWidth;
        int y = (piece[i].y - minY ) * cellHeight;
//        std::cout << piece[i].x << " " << piece[i].y << '\n';
        int lastEmptyRow = findLastEmptyRowInColumn(piece[i].x);
//        std::cout << lastEmptyRow << '\n';
        int posY = (BOARD_HEIGHT - lastEmptyRow - 1) + y + 540;
        int posX = (SCREEN_WIDTH - BOARD_WIDTH * cellWidth) / 2 + x;
        SDL_Rect cellRect = {posX, posY, cellWidth, cellHeight};
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
        SDL_RenderFillRect(gRenderer, &cellRect);
    }
}
Point GameState::generateNewPiece() {
    Point nextPiece[4];
    int randomPiece = rand() % 7;

    for (int i = 0; i < 4; ++i) {
        nextPiece[i].x = figures[randomPiece][i] % 2 + 2;
        nextPiece[i].y = figures[randomPiece][i] / 2;
    }

    return nextPiece[4];
}
void GameState::updateNextPieces() {
    for (int i = 0; i < 4; ++i) {
    currentTetrads[i] = next1Tetrads[i];
    next1Tetrads[i] = next2Tetrads[i];
}
}

void GameState::renderNextPieces(SDL_Renderer* gRenderer, int randomColor) {
    int startX = 800;
    int startY = 380;
    int spacing = 65;

    for (int i = 0; i < 3; ++i)
      {
        for (int j = 0; j < 4; j++)
         {
           SDL_Rect nextPieceRect;
           int pieceX = startX + piece[j].x *PIECE_SIZE;
           int pieceY = startY + piece[j].y *PIECE_SIZE + i*spacing;

//           createRect(nextPieceRect, pieceX, pieceY, PIECE_SIZE, PIECE_SIZE);
           colorSelect(gRenderer,randomColor);
           SDL_RenderFillRect(gRenderer, &nextPieceRect);
         }
    }


}
