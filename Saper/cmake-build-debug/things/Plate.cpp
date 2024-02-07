//
// Created by szymon on 13.05.23.
//

#include "Plate.h"

#include <SFML/Graphics.hpp>

Plate::Plate(sf::Font &Font, std::string Message, sf::Vector2f Size, int SizeChar, sf::Color BgColor, sf::Color TextColor)
{
    Text.setFont(Font);
    Text.setString(Message);
    Text.setFillColor(TextColor);
    Text.setCharacterSize(SizeChar);
    Text.setOrigin(Text.getLocalBounds().width / 2, Text.getLocalBounds().height / 2);

    Background stamp(Size, BgColor);

    Rectangle=stamp;
}

void Plate::setPosition(sf::Vector2f Pos)
{
    Rectangle.setPosition(Pos);
    Text.setPosition(Pos.x, Pos.y - 5);
}

void Plate::draw(sf::RenderWindow &Window) const
{
    Window.draw(Rectangle);
    Window.draw(Text);
}