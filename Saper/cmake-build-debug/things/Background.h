//
// Created by szymon on 12.05.23.
//

#ifndef SAPER_BACKGROUND_H
#define SAPER_BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background:public sf::RectangleShape
{
public:
    Background(sf::Vector2f Size={300, 400}, sf::Color BgColor=sf::Color::Red, sf::Vector2f Position={250, 300});
};


#endif //SAPER_BACKGROUND_H
