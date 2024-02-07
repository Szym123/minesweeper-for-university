//
// Created by szymon on 14.05.23.
//

#ifndef SAPER_MAINMENU_H
#define SAPER_MAINMENU_H

#include "Interface.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Board.h"


class MainMenu:public Interface
{
    void mouseMovement(Menu &MenuGraphics, sf::RenderWindow &MenuWindow);
    int mouseTouched(Menu &MenuGraphicsA, sf::RenderWindow &MenuWindowA, sf::Event &MenuEventA);
public:
    void decisionLope(int &Option, sf::RenderWindow &InterWindow, sf::Event &InterEvent, Menu &InterGraphics, Board &InterBoard);
    int getPoint();
};


#endif //SAPER_MAINMENU_H
