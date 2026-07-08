//
// Created by c on 4/18/24.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>

class MSSFMLView {

    MinesweeperBoard &plansza;
    sf::Texture bomb;
    sf::Texture jeden;
    sf::Texture dwa;
    sf::Texture trzy;
    sf::Texture cztery;
    sf::Texture piec;
    sf::Texture szesc;
    sf::Texture siedem;
    sf::Texture osiem;
    sf::Texture dziewiec;
    sf::Texture flag;
    sf::Texture pole;
    sf::Font font;


public:
    MSSFMLView(MinesweeperBoard &plansza);
    void draw(sf::RenderWindow &window);
};


#endif //SAPER_MSSFMLVIEW_H
