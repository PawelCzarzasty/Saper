//
// Created by Pawel Czarzasty on 07/05/2024.
//

#include "MSSFMLController.h"
MSSFMLController::MSSFMLController(MinesweeperBoard &plansza, MSSFMLView &View) : plansza(plansza), View(View){

}
void MSSFMLController::play(sf::RenderWindow &window){
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if(plansza.getGameState()== RUNNING) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    int wiersz = event.mouseButton.y / (600 / plansza.getBoardHeight());
                    int kolumna = event.mouseButton.x / (800 / plansza.getBoardWidth());
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        plansza.revealField(wiersz, kolumna);
                    } else if (event.mouseButton.button == sf::Mouse::Right) {
                        plansza.toggleFlag(wiersz, kolumna);
                    }
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        View.draw(window);
        window.display();
    }
}