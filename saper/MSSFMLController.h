//
// Created by Pawel Czarzasty on 07/05/2024.
//

#ifndef SAPER_MSSFMLCONTROLLER_H
#define SAPER_MSSFMLCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include "SFML/Graphics.hpp"
class MSSFMLController {
    MinesweeperBoard &plansza;
    MSSFMLView &View;

public:
    MSSFMLController(MinesweeperBoard &plansza, MSSFMLView &View);
    void play(sf::RenderWindow &window);
};

#endif //SAPER_MSSFMLCONTROLLER_H
