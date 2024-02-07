//
// Created by szymon on 13.05.23.
//

#ifndef SAPER_BOARD_H
#define SAPER_BOARD_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"

class Board
{
    friend class Game;

    std::vector<std::vector<Button>> Table;
    Button Title;
protected:
    std::vector<int> TabLocation;
public:
    Board(sf::Font &BoardFont, std::string Message={""}, sf::Vector2f Size={50, 50}, int SizeChar=30, sf::Color BgColor=sf::Color::Yellow, sf::Color TextColor=sf::Color::Black);
    void setButtonTitle(int PositionY, int PositionX, std::string &NewMessage);
    void setButtonColor(sf::Color ColText, sf::Color ColButton, int LocationY, int LocationX);
    void draw(sf::RenderWindow &Window) const;
    void isMouseOver(sf::RenderWindow &WindowA);
    void resetBoard(sf::Font &BoardFont);
};


#endif //SAPER_BOARD_H
