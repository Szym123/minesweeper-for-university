//
// Created by szymon on 12.05.23.
//

#ifndef SAPER_BUTTON_H
#define SAPER_BUTTON_H

#include <SFML/Graphics.hpp>
#include "Plate.h"

class Button:public Plate
{
public:
    using Plate::Plate;

    void setColor(sf::Color BgColor, sf::Color TextColor);
    void operator=(std::string NewText);
    bool isMouseOver(sf::RenderWindow &Window) const;
};


#endif //SAPER_BUTTON_H