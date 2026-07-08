
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "MinesweeperBoard.h"
MinesweeperBoard::MinesweeperBoard(){
    width = 5;
    height = 7;
    board.resize(7, 5);
    for(int row = 0; row<height; row++){
        for(int col = 0; col<width; col++){
            board[row][col].isRevealed = false;
            board[row][col].hasMine = false;
            board[row][col].hasFlag = false;
        }
    }
    board[0][0].hasMine = true;
    board[1][1].isRevealed = true;
    board[0][2].hasMine = true;
    board[0][2].hasFlag = true;
}
MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode tryb){
    this->width = width;
    this->height = height;
    srand( time( NULL ) );
    int iloscMin;
    if(tryb == HARD){
        board.resize(height, width);
        iloscMin = 0.3*width*height;
        setMines(iloscMin);

    }
    if(tryb == NORMAL){
        board.resize(height, width);
        iloscMin = 0.2*width*height;
        setMines(iloscMin);

    }
    if(tryb == EASY){
        board.resize(height, width);
        iloscMin = 0.1*width*height;
        setMines(iloscMin);
        }
      if(tryb == DEBUG){
          board.resize(height, width);
          for(int i = 0; i <height;i++){
              if(i%2==0) {
                  board[i][0].hasMine = true;
              }
          }
          if(height>width){
              for(int i = 0; i< width; i++){
                  board[i][i].hasMine = true;
              }
          }else{
              for(int i = 0; i< height; i++){
                  board[i][i].hasMine = true;
              }
          }
          for(int i = 0; i <width;i++){
              board[0][i].hasMine = true;
          }

      }
}
void MinesweeperBoard::setMines(int mines) {
    int i = 0;
    while(i<mines) {
        int row = rand()%(height);
        int col = rand()%(width);
        if(board[row][col].hasMine == false){
            board[row][col].hasMine = true;
            i++;
        }
    }
}
void MinesweeperBoard::debug_display() const {
    for(int row = 0; row<height; row++){
        for(int col = 0; col<width; col++){
            cout<<"[";
            if(board[row][col].hasMine == true)cout<<"M";else cout<<".";
            if(board[row][col].isRevealed == true)cout<<"o";else cout<<".";
            if(board[row][col].hasFlag == true)cout<<"f";else cout<<".";
            cout<<"]";
        }
        cout<<endl;
    }
}

int MinesweeperBoard::getBoardWidth() const{
    return width;
}
int MinesweeperBoard::getBoardHeight() const{
    return height;
}
int MinesweeperBoard::getMineCount() const{
    int count = 0;
    for(int row = 0; row<height; row++){
        for(int col = 0; col<width; col++){
            if(board[row][col].hasMine == true){
                count ++;
            }
        }
    }
    return count;
}
bool MinesweeperBoard::outOfRange(int row, int col) const{
    if(row +1>height or row<0 or col+ 1>width or col<0){
        return true;
    }
    return false;
}
int MinesweeperBoard::countMines(int row, int col) const{
    int counter = 0;
    if(row > height or col > width){
        return -1;
    }
    if(board[row][col].isRevealed == false){
        return -1;
    }
    if(board[row][col].hasMine == false){
        for(int i = row-1; i<=row+1;i++){
            for(int j = col-1;j<=col+1;j++){
                if(j>=0 and j<=width-1 and i>=0 and i<=height-1){
                    if(board[i][j].hasMine == true) {
                        counter++;
                    }
                }
            }
        }
    }
    return counter;
}
bool MinesweeperBoard::hasFlag(int row, int col) const{
    if(outOfRange(row,col)){
        return false;
    }
    if(board[row][col].hasFlag == true){
        return true;
    }
    if(board[row][col].hasFlag == false){
        return false;
    }
    if(board[row][col].isRevealed == true){
        return false;
    }

    return false;
}
void MinesweeperBoard::toggleFlag(int row, int col){
    if(outOfRange(row,col)){
        return;
    }
    if(board[row][col].isRevealed == true){
        return;
    }

    if(state == FINISHED_WIN or state == FINISHED_LOSS){
        return;
    }
    if(board[row][col].isRevealed == false){
        if(board[row][col].hasFlag == true){
            board[row][col].hasFlag = false;
        }else{
            board[row][col].hasFlag = true;
        }
    }

}
void MinesweeperBoard::checkFieldsAround(int row, int col) {
    for(int x = row - 1; x<row+2; x++){
        for(int y = col-1; y<col+2; y++){
            revealField(x, y);
        }
    }
}
void MinesweeperBoard::revealField(int row, int col) {
    if (outOfRange(row, col)) {
        return;
    }
    if (board[row][col].hasFlag == true) {
        return;
    }
    if (board[row][col].isRevealed == true) {
        return;
    }
    if (firstMove == true and board[row][col].hasMine == true) {
        board[row][col].hasMine = false;
        bool Place = false;
        while (Place == false) { //szukanie miejsca dla nowej miny
            int x = rand() % (height -1);
            int y = rand() % (width -1);
            if (board[x][y].hasMine == false) {
                board[x][y].hasMine = true;
                Place = true;
            }
        }
    }
    if (firstMove == false and board[row][col].hasMine == true) {
        board[row][col].isRevealed = true;
        state = FINISHED_LOSS;
    }
    if (board[row][col].hasMine == false) {
        board[row][col].isRevealed = true;
        if(countMines(row,col)==0){
            checkFieldsAround(row,col);
        }
        updateState();
    }
    if(firstMove == true){
        firstMove = false;
    }
    if(state == FINISHED_WIN or state == FINISHED_LOSS){
        return;
    }
}
void MinesweeperBoard::FirstMove(int row, int col) {
    if(outOfRange(row, col )==0) {
        revealField(row, col);
        if (countMines(row, col) == 0) {
            for (int i = row - 1; i <= row + 1; i++) {
                for (int j = col - 1; j <= col + 1; j++) {
                    FirstMove(i, j);
                }
            }
        }
    }
}


bool MinesweeperBoard::isRevealed(int row, int col) const {
        if(board[row][col].isRevealed == true){
            return true;
        }else{
            return false;
        }
}
GameState MinesweeperBoard::getGameState() const {
    return state;
}
void MinesweeperBoard::updateState(){
    int clear = 0;
    for(int row = 0; row<height; row++) {
        for (int col = 0; col < width; col++) {
            if(board[row][col].isRevealed == true and board[row][col].hasMine == false){
                clear++;
            }
        }
    }
    if(clear == ((height*width) - getMineCount())){
        state = FINISHED_WIN;
    }else{
        state = RUNNING;
    }
}
char MinesweeperBoard::getFieldInfo(int row, int col) const{
    if (outOfRange(row, col)) {
        return '#';
    }
    if(board[row][col].isRevealed == false && board[row][col].hasFlag == true){
        return 'F';
    }
    if(board[row][col].isRevealed == false && board[row][col].hasFlag == false){
        return '_';
    }
    if(board[row][col].isRevealed == true && board[row][col].hasMine == true){
        return 'x';
    }
    if(board[row][col].isRevealed == true && countMines(row,col) == 0){
        return ' ';
    }
    if(board[row][col].isRevealed == true && countMines(row,col) != 0) {
        return countMines(row, col) + '0';
    }
    return 0;
}