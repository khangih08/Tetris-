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

        if(piece[i].x < 0 || piece[i].x >= BOARD_WIDTH || piece[i].y >= BOARD_HEIGHT -


            1)
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
        // Xóa các vị trí của các khối hiện tại trên bảng
        for (int i = 0; i < 4; i++) {
            board[piece[i].y][piece[i].x] = 0;
        }

        // Cập nhật vị trí mới của các khối trong mảng tmpPiece
        for (int i = 0; i < 4; i++) {
            tmpPiece[i] = piece[i];
            piece[i].y++;
        }

        // Đặt các vị trí mới của các khối trên bảng
        for (int i = 0; i < 4; i++) {
            board[piece[i].y][piece[i].x] = randomColor; // Bạn cần thay đổi randomColor bằng màu thích hợp
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
  //              createRect(activePiece,25 + piece[i].x*25,(piece[i].y-3)*25,PIECE_SIZE,PIECE_SIZE);
                colorSelect(gRenderer,randomColor);
                SDL_RenderFillRect(gRenderer,&activePiece);
            }
}
}
void GameState::checkAndClearFilledRows(int& score, int& target, int& level) {
    // Duyệt qua từng hàng từ dưới lên trên
    for (int y = BOARD_HEIGHT - 1; y >= 0; --y) {
        bool rowFilled = true;
        // Kiểm tra xem hàng có đầy đủ các mảnh block không
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            if (board[y][x] == 0) {
                rowFilled = false;
                break;
            }
        }
        // Nếu hàng đã đầy đủ các mảnh block
        if (rowFilled) {
            // Di chuyển các hàng phía trên xuống một hàng
            for (int yy = y; yy > 0; --yy) {
                for (int x = 0; x < BOARD_WIDTH; ++x) {
                    board[yy][x] = board[yy - 1][x];
                }
            }
            // Đặt hàng trống ở hàng đầu tiên
            for (int x = 0; x < BOARD_WIDTH; ++x) {
                board[0][x] = 0;
            }
            // Cập nhật điểm số của người chơi
            target++;
            score += 100; // Ví dụ: cộng 100 điểm mỗi khi xóa một hàng
            if (score >= 1000) {
                level++;
                score = 0; // Đặt lại điểm về 0
            }
            // Kiểm tra các hàng tiếp theo, bởi vì có thể có nhiều hàng đã được xóa
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

void GameState::renderNextPieces(SDL_Renderer* gRenderer, int randomColor, int randomPiece) {
    // Lấy màu để vẽ các khối
    int colors[3] = {randomColor, randomColor, randomColor}; // Điều chỉnh cho phù hợp với logic của bạn

    // Vị trí ban đầu để vẽ các khối tiếp theo
    int startX = 490; // Điều chỉnh vị trí xuất hiện trên màn hình
    int startY = 31; // Điều chỉnh vị trí xuất hiện trên màn hình

    // Khoảng cách giữa các khối tiếp theo
    int spacing = PIECE_SIZE * 2; // Điều chỉnh khoảng cách giữa các khối

    // Vẽ các khối tiếp theo lên màn hình
    for (int i = 0; i < 3; ++i) {
        // Tạo ra khối tiếp theo
//        generatePiece(randomPiece); // randomPiece là chỉ số của loại khối tùy thuộc vào logic của bạn

        // Vẽ khối tiếp theo lên màn hình
        for (int j = 0; j < 4; ++j) {
            SDL_Rect nextPieceRect;
            nextPieceRect.x = startX + j * 10.5; // Điều chỉnh vị trí xuất hiện trên màn hình
            nextPieceRect.y = startY + i * spacing; // Điều chỉnh vị trí xuất hiện trên màn hình
            nextPieceRect.w = 10.5;
            nextPieceRect.h = 10.5;

            // Vẽ khối với màu tương ứng
            SDL_SetRenderDrawColor(gRenderer, colors[i], colors[i], colors[i], 0);
            SDL_RenderFillRect(gRenderer, &nextPieceRect);
        }
    }
}
