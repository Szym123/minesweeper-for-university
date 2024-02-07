//
// Created by szymon on 14.05.23.
//

#ifndef SAPER_INTERFACE_H
#define SAPER_INTERFACE_H

#include "Menu.h"
#include "Board.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Interface
{
public:
    virtual void decisionLope(int &Option, sf::RenderWindow &InterWindow, sf::Event &InterEvent, Menu &InterGraphics, Board &InterBoard) = 0;
    virtual int getPoint()=0;
};


#endif //SAPER_INTERFACE_H
