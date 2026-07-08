#include "Array2D.h"
#ifndef MINESWEEPER_H_
#define MINESWEEPER_H_

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};
class MinesweeperBoard
{
    Array2D<Field> board {10, 10};
    int width;
    int height;
    bool firstMove = true;
    GameState state = RUNNING;
    void updateState();
    void setMines(int mines) ;
    bool outOfRange(int row, int col) const;
    void FirstMove(int row, int col);
    void checkFieldsAround(int row, int col);
public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    bool isRevealed(int row, int col) const;
    GameState getGameState() const;
    char getFieldInfo(int row, int col) const;
    void debug_display() const;
};
#endif