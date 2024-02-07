//
// Created by szymon on 12.05.23.
//

#include "Background.h"

Background::Background(sf::Vector2f Size, sf::Color BgColor, sf::Vector2f Position)
{
    sf::RectangleShape::setSize(Size);
    sf::RectangleShape::setFillColor(BgColor);
    sf::RectangleShape::setOrigin(Size.x / 2, Size.y / 2);
    sf::RectangleShape::setPosition(Position);
}
