//
// Created by szymon on 13.05.23.
//

#ifndef SAPER_PLATE_H
#define SAPER_PLATE_H

#include <SFML/Graphics.hpp>
#include "Background.h"

class Plate
{
protected:
    Background Rectangle;
    sf::Text Text;
public:
    Plate(sf::Font &Font, std::string Message={" "}, sf::Vector2f Size={200, 50}, int SizeChar=30, sf::Color BgColor=sf::Color::Green, sf::Color TextColor=sf::Color::Black);

    void setPosition(sf::Vector2f Pos);
    void draw(sf::RenderWindow &Window) const;


};


#endif //SAPER_PLATE_H
