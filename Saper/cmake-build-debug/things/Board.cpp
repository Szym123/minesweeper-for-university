//
// Created by szymon on 13.05.23.
//

#include "Board.h"
#include <SFML/Graphics.hpp>
#include "Button.h"

Board::Board(sf::Font &BoardFont, std::string Message, sf::Vector2f Size, int SizeChar, sf::Color BgColor, sf::Color TextColor)
:Title(BoardFont, {"Saper"}, {400,50}, SizeChar, sf::Color::Magenta, TextColor)
{
    int Number=0;
    float PosX=100,PosY=75;
    Button StampButton(BoardFont, Message, Size, SizeChar, BgColor, TextColor);
    std::vector<Button> ButtonVector;

    TabLocation.push_back(-1);
    TabLocation.push_back(-1);

    Title.setPosition({250,50});

    for(int i=0;i<8;i++)
    {
        ButtonVector.push_back(StampButton);
    }

    for(int i=0;i<8;i++)
    {
        Table.push_back(ButtonVector);
    }

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            Table[j][i].setPosition({PosY, PosX});
            PosY+=50;
        }
        PosY=75;
        PosX+=50;
    }
}

void Board::setButtonTitle(int PositionY, int PositionX, std::string &NewMessage)
{
    Table[PositionY][PositionX]=(NewMessage);
}

void Board::setButtonColor(sf::Color ColText, sf::Color ColButton, int LocationY, int LocationX)
{
    Table[LocationY][LocationX].setColor(ColButton, ColText);
}


void Board::draw(sf::RenderWindow &Window) const
{
    Title.draw(Window);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            Table[i][j].draw(Window);
        }
    }
}

void Board::isMouseOver(sf::RenderWindow &WindowA)
{
    TabLocation[0]=-1;
    TabLocation[1]=-1;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if (Table[i][j].isMouseOver(WindowA) == true)
            {
                TabLocation[0]=i;
                TabLocation[1]=j;
            }
        }
    }
}

void Board::resetBoard(sf::Font &BoardFont)
{
    float PosX=100,PosY=75;
    Button StampButton(BoardFont, {" "}, {50, 50}, 30, sf::Color::Yellow);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            Table[j][i]=StampButton;
            Table[j][i].setPosition({PosY, PosX});
            PosY+=50;
        }
        PosY=75;
        PosX+=50;
    }
}