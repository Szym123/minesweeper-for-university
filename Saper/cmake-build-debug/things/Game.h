//
// Created by szymon on 17.05.23.
//

#ifndef SAPER_GAME_H
#define SAPER_GAME_H

#include "Interface.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Menu.h"
#include "Board.h"
#include "Tile.h"

class Game:public Interface
{
    std::vector<std::vector<Tile>> Map;
    int Point=0;

    void mouseMovement(Board &GameGraphics, sf::RenderWindow &GameWindow);
    void generator();
    void openBoard(Board &GameGraphicsA, int YourPositionY, int YourPositionX);
    void mouseTouched(Board &GameGraphicsB, sf::RenderWindow &GameWindowB, sf::Event &GameEventB);
public:
    Game(sf::Font &FontGame);
    void decisionLope(int &Option, sf::RenderWindow &InterWindow, sf::Event &InterEvent, Menu &InterGraphics, Board &InterBoard);
    int getPoint();
};


#endif //SAPER_GAME_H
