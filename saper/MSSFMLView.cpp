//
// Created by c on 4/18/24.
//
#include "MSSFMLView.h"
MSSFMLView::MSSFMLView(MinesweeperBoard &plansza) : plansza(plansza) {
    bomb.loadFromFile("../bomba.png");
    jeden.loadFromFile("../1.jpeg");
    dwa.loadFromFile("../2.jpeg");
    trzy.loadFromFile("../3.jpeg");
    cztery.loadFromFile("../4.jpeg");
    piec.loadFromFile("../5.jpeg");
    szesc.loadFromFile("../6.jpeg");
    siedem.loadFromFile("../7.jpeg");
    osiem.loadFromFile("../8.jpeg");
    dziewiec.loadFromFile("../9.jpeg");
    flag.loadFromFile("../flag.jpeg");
    pole.loadFromFile("../pole.png");
    font.loadFromFile("../nordic.ttf");
}

void MSSFMLView::draw(sf::RenderWindow &window) {
    for (int row = 0; row < plansza.getBoardHeight(); row++) {
        for (int col = 0; col < plansza.getBoardWidth(); col++) {
            sf::Sprite sprite;
            if(plansza.isRevealed(row,col)==1){
                if(plansza.getFieldInfo(row, col)=='x'){
                    sprite.setTexture(bomb);
                    float scale = std::min(800.f / (bomb.getSize().x * plansza.getBoardWidth()), 600.f / (bomb.getSize().y * plansza.getBoardHeight()));
                    sprite.setScale(scale, scale);
                }
                if(plansza.countMines(row,col)==1) {
                    sprite.setTexture(jeden);
                    float scale = std::min(800.f / (jeden.getSize().x * plansza.getBoardWidth()), 600.f / (jeden.getSize().y * plansza.getBoardHeight()));
                    sprite.setScale(scale, scale);
                }
                if(plansza.countMines(row,col)==2) {
                    sprite.setTexture(dwa);
                    float scale = std::min(800.f / (dwa.getSize().x * plansza.getBoardWidth()), 600.f / (dwa.getSize().y * plansza.getBoardHeight()));
                    sprite.setScale(scale, scale);
                }
                if(plansza.countMines(row,col)==3) {
                    sprite.setTexture(trzy);
                    float scale = std::min(800.f / (trzy.getSize().x * plansza.getBoardWidth()), 600.f / (trzy.getSize().y * plansza.getBoardHeight()));
                    sprite.setScale(scale, scale);
                }
                if(plansza.countMines(row,col)==4) {
                    sprite.setTexture(cztery);
                    float scale = std::min(800.f / (cztery.getSize().x * plansza.getBoardWidth()), 600.f / (cztery.getSize().y * plansza.getBoardHeight()));
                    sprite.setScale(scale, scale);
                }
                if(plansza.countMines(row,col)==5) {
                    sprite.setTexture(piec);
                    float scale = std::min(800.f / (piec.getSize().x * plansza.getBoardWidth()), 600.f / (piec.getSize().y * plansza.getBoardHeight()));
                    sprite.setScale(scale, scale);
                }
                if(plansza.countMines(row,col)==6) {
                    sprite.setTexture(szesc);
                    float scale = std::min(800.f / (szesc.getSize().x * plansza.getBoardWidth()), 600.f / (szesc.getSize().y * plansza.getBoardHeight()));
                    sprite.setScale(scale, scale);
                }
                if(plansza.countMines(row,col)==7) {
                    sprite.setTexture(siedem);
                    float scale = std::min(800.f / (siedem.getSize().x * plansza.getBoardWidth()), 600.f / (siedem.getSize().y * plansza.getBoardHeight()));
                    sprite.setScale(scale, scale);
                }
                if(plansza.countMines(row,col)==8) {
                    sprite.setTexture(osiem);
                    float scale = std::min(800.f / (osiem.getSize().x * plansza.getBoardWidth()), 600.f / (osiem.getSize().y * plansza.getBoardHeight()));
                    sprite.setScale(scale, scale);
                }
                if(plansza.countMines(row,col)==9) {
                    sprite.setTexture(dziewiec);
                    float scale = std::min(800.f / (dziewiec.getSize().x * plansza.getBoardWidth()), 600.f / (dziewiec.getSize().y * plansza.getBoardHeight()));
                    sprite.setScale(scale, scale);
                }
            }
            if(plansza.isRevealed(row,col)== 0){
                sprite.setTexture(pole);
                float scale = std::min(800.f / (pole.getSize().x * plansza.getBoardWidth()), 600.f / (pole.getSize().y * plansza.getBoardHeight()));
                sprite.setScale(scale, scale);

            }
            if(plansza.hasFlag(row,col)==1){
                sprite.setTexture(flag);
                float scale = std::min(800.f / (flag.getSize().x * plansza.getBoardWidth()), 600.f / (flag.getSize().y * plansza.getBoardHeight()));
                sprite.setScale(scale, scale);
            }
            sprite.setPosition(col * (800.f / plansza.getBoardWidth()), row * (600.f / plansza.getBoardHeight()));
            window.draw(sprite);
        }
    }
    if(plansza.getGameState()==FINISHED_LOSS){
        sf::Text loss("PRZEGRALES", sf::Font(), 100);
        loss.setFont(font);
        loss.setPosition(200, 200);
        loss.setFillColor(sf::Color(250,0,0));
        window.draw(loss);
        sf::sleep(sf::seconds(5));
    }
    if(plansza.getGameState()== FINISHED_WIN){
        sf::Text win("WYGRALES", sf::Font(), 100);
        win.setFont(font);
        win.setPosition(200, 200);
        win.setFillColor(sf::Color(250,0,0));
        window.draw(win);
    }
}
