//
// Created by szymon on 14.05.23.
//

#ifndef SAPER_APPLICATION_H
#define SAPER_APPLICATION_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Board.h"
#include "Interface.h"

class Application
{

    sf::RenderWindow AppWindow;
    sf::Event AppEvent;
    sf::Font AppFont;

    Interface *AppInterface;

    Menu AppMenu;
    Board AppBoard;

    int Mode=0,VisionMode=1,AppPoint=0;

    void changeMode(sf::Font &AppFontC);
    void displayMode();
    void displayYourScore();
public:
    Application(sf::Font &AppFontA);
    void loup(sf::Font &AppFontB);
};


#endif //SAPER_APPLICATION_H
