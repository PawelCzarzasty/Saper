//
// Created by c on 4/4/24.
//
#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController {
private:
    int height;
    int width;
    MinesweeperBoard &plansza;
    MSBoardTextView &widok;
public:
    MSTextController(MinesweeperBoard &plansza, MSBoardTextView &widok);
    void play();
};


#endif //SAPER_MSTEXTCONTROLLER_H
