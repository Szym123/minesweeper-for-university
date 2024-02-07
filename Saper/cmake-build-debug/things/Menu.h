//
// Created by szymon on 12.05.23.
//

#ifndef SAPER_MENU_H
#define SAPER_MENU_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Background.h"

class Menu
{
protected:
    std::vector<Button> Tab;
    Background BgMenu;
public:
    Menu(sf::Font &MenuFont, int Number);

    void draw(sf::RenderWindow &Window) const;
    void setButtonTitle(int PositionX, std::string NewMessage);
    void setButtonColor(sf::Color ColText, sf::Color ColButton, int Location);
    int isMouseOver(sf::RenderWindow &WindowA);
    int getTabSize();
};

#endif //SAPER_MENU_H
