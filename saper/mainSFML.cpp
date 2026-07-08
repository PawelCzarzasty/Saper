//
// Created by c on 4/18/24.
//
#include "MSSFMLController.h"
#include "MSSFMLView.h"
#include "MinesweeperBoard.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SAPER");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MinesweeperBoard board(10, 10, DEBUG);
    MSSFMLView view (board);  // przekazujemy przez referencję planszę jako argument konstruktora
    MSSFMLController ctrl(board,view);
    ctrl.play(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        view.draw(window);
        window.display();
    }

    return 0;
}
