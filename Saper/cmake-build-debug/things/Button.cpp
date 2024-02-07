//
// Created by szymon on 12.05.23.
//

#include "Button.h"

#include <SFML/Graphics.hpp>

void Button::setColor(sf::Color BgColor, sf::Color TextColor)
{
    Rectangle.setFillColor(BgColor);
    Text.setFillColor(TextColor);
}

void Button::operator=(std::string NewText)
{
    Text.setString(NewText);
    Text.setOrigin(Text.getLocalBounds().width / 2, Text.getLocalBounds().height / 2);
}

bool Button::isMouseOver(sf::RenderWindow &Window) const
{
    float MouseX=sf::Mouse::getPosition(Window).x;
    float MouseY=sf::Mouse::getPosition(Window).y;

    float BtnPosX= Rectangle.getPosition().x - Rectangle.getLocalBounds().width / 2;
    float BtnPosY= Rectangle.getPosition().y - Rectangle.getLocalBounds().height / 2;

    float BtnxPosWidth= Rectangle.getPosition().x + Rectangle.getLocalBounds().width / 2;
    float BtnyPosHeight= Rectangle.getPosition().y + Rectangle.getLocalBounds().height / 2;

    if(MouseX < BtnxPosWidth && MouseX > BtnPosX && MouseY < BtnyPosHeight && MouseY > BtnPosY)
    {return true;}

    return false;
}