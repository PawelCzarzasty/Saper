//
// Created by Pawel Czarzasty on 28/03/2024.
//
#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"


class MSBoardTextView {
private:

    MinesweeperBoard &plansza;
public:
MSBoardTextView(MinesweeperBoard &plansza);
void display();
};

#endif //SAPER_MSBOARDTEXTVIEW_H
