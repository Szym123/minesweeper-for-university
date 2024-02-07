//
// Created by szymon on 17.05.23.
//

#include "Game.h"
#include "Interface.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <time.h>
#include <cstdlib>


void Game::mouseMovement(Board &GameGraphics, sf::RenderWindow &GameWindow)
{
    GameGraphics.isMouseOver(GameWindow);

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(Map[i][j].getPosition() == false)
            {
                GameGraphics.setButtonColor(sf::Color::Black, sf::Color::Yellow, i, j);
            }
            else
            {
                GameGraphics.setButtonColor(sf::Color::Black, sf::Color::Blue, i, j);
            }
        }
    }

    if(GameGraphics.TabLocation[0] >= 0)
    {
        GameGraphics.setButtonColor(sf::Color::Black, sf::Color::Red, GameGraphics.TabLocation[0], GameGraphics.TabLocation[1]);
    }
}

void Game::generator()
{
    int ProbabilityX=0,ProbabilityY=0,PosiPoint=0;
    srand(time(nullptr));

    for(int i=0;i<6;i++)
    {
        do{
            ProbabilityX= rand() % 7 + 1;
            ProbabilityY= rand() % 7 + 1;
        }while(Map[ProbabilityY][ProbabilityX].getNumber() == 9);
        Map[ProbabilityY][ProbabilityX].setNumber(9);

        ProbabilityY--;
        ProbabilityX--;

        for(int j=0;j<3;j++)
        {
            PosiPoint=j;
            for(int k=0;k<3;k++)
            {
                if((ProbabilityY + PosiPoint) == -1){break;}
                if((ProbabilityX + k) == -1){break;}
                if((ProbabilityY + PosiPoint) == 8){break;}
                if((ProbabilityX + k) == 8){break;}

                if(Map[ProbabilityY + PosiPoint][ProbabilityX + k].getNumber() < 9){Map[ProbabilityY + PosiPoint][ProbabilityX + k]++;}
            }
        }
    }
}

void Game::openBoard(Board &GameGraphicsA, int YourPositionY, int YourPositionX)
{
    for(int i=1;i>-2;i-=2)
    {
        if((YourPositionX + i < 8) && (YourPositionX + i > -1) && !Map[YourPositionY][YourPositionX + i].getPosition())
        {
            if(Map[YourPositionY][YourPositionX + i].getNumber() == 0)
            {
                GameGraphicsA.setButtonColor(sf::Color::Black, sf::Color::Blue, YourPositionY, YourPositionX + i);
                GameGraphicsA.setButtonTitle(YourPositionY, YourPositionX + i, Map[YourPositionY][YourPositionX + i].PlayerVision);
                Map[YourPositionY][YourPositionX + i].changePosition();
                openBoard(GameGraphicsA, YourPositionY, YourPositionX + i);
            }
            else
            {
                GameGraphicsA.setButtonColor(sf::Color::Black, sf::Color::Blue, YourPositionY, YourPositionX + i);
                GameGraphicsA.setButtonTitle(YourPositionY, YourPositionX + i, Map[YourPositionY][YourPositionX + i].PlayerVision);
                Map[YourPositionY][YourPositionX + i].changePosition();
            }
        }

        if((YourPositionY + i < 8) && (YourPositionY + i > -1) && !Map[YourPositionY + i][YourPositionX].getPosition())
        {
            if(Map[YourPositionY + i][YourPositionX].getNumber() == 0)
            {
                GameGraphicsA.setButtonColor(sf::Color::Black, sf::Color::Blue, YourPositionY + i, YourPositionX);
                GameGraphicsA.setButtonTitle(YourPositionY + i, YourPositionX, Map[YourPositionY + i][YourPositionX].PlayerVision);
                Map[YourPositionY + i][YourPositionX].changePosition();
                openBoard(GameGraphicsA, YourPositionY + i, YourPositionX);
            }
            else
            {
                GameGraphicsA.setButtonColor(sf::Color::Black, sf::Color::Blue, YourPositionY + i, YourPositionY);
                GameGraphicsA.setButtonTitle(YourPositionY + i, YourPositionX, Map[YourPositionY + i][YourPositionX].PlayerVision);
                Map[YourPositionY + i][YourPositionX].changePosition();
            }
        }
    }
}

void Game::mouseTouched(Board &GameGraphicsB, sf::RenderWindow &GameWindowB, sf::Event &GameEventB)
{
    std::string flag="P",notFlag=" ";
;
    if(GameEventB.mouseButton.button == sf::Mouse::Left)
    {
        GameGraphicsB.isMouseOver(GameWindowB);
        if(GameGraphicsB.TabLocation[0] != -1)
        {
            if(!Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]].getFlag())
            {
                if (Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]].getNumber() == 0)
                {
                    GameGraphicsB.setButtonColor(sf::Color::Black, sf::Color::Blue, GameGraphicsB.TabLocation[0], GameGraphicsB.TabLocation[1]);
                    GameGraphicsB.setButtonTitle(GameGraphicsB.TabLocation[0], GameGraphicsB.TabLocation[1], Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]].PlayerVision);
                    Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]].changePosition();
                    openBoard(GameGraphicsB, GameGraphicsB.TabLocation[0], GameGraphicsB.TabLocation[1]);
                }
                if (Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]].getNumber() == 9)
                {
                    Point = -1;
                }
                else
                {
                    GameGraphicsB.setButtonColor(sf::Color::Black, sf::Color::Blue, GameGraphicsB.TabLocation[0], GameGraphicsB.TabLocation[1]);
                    GameGraphicsB.setButtonTitle(GameGraphicsB.TabLocation[0], GameGraphicsB.TabLocation[1], Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]].PlayerVision);
                    Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]].changePosition();
                }
            }
        }
    }

    if(GameEventB.mouseButton.button == sf::Mouse::Right)
    {
        GameGraphicsB.isMouseOver(GameWindowB);
        if(GameGraphicsB.TabLocation[0] != -1)
        {
            if(!Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]].getPosition())
            {
                if(!Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]].getFlag())
                {
                    GameGraphicsB.setButtonTitle(GameGraphicsB.TabLocation[0], GameGraphicsB.TabLocation[1], flag);
                    Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]] << true;
                    if (Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]].getNumber() == 9) {
                        Point++;
                    }
                }
                else
                {
                    GameGraphicsB.setButtonTitle(GameGraphicsB.TabLocation[0], GameGraphicsB.TabLocation[1], notFlag);
                    Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]] << false;
                    if (Map[GameGraphicsB.TabLocation[0]][GameGraphicsB.TabLocation[1]].getNumber() == 9) {
                        Point--;
                    }
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////
Game::Game(sf::Font &FontGame)
{
    Tile StampTile;
    std::vector<Tile> StampVector;
    for(int i=0;i<64;i++)
    {
        StampVector.push_back(StampTile);
    }

    for(int i=0;i<64;i++)
    {
        Map.push_back(StampVector);
    }

    generator();
}

void Game::decisionLope(int &Option, sf::RenderWindow &InterWindow, sf::Event &InterEvent, Menu &InterGraphics, Board &InterBoard)
{
    int Function=0;
    InterBoard.isMouseOver(InterWindow);

    while (InterWindow.pollEvent(InterEvent))
    {
        switch (InterEvent.type)
        {
            case sf::Event::Closed: {
                InterWindow.close();
                break;
            }
            case sf::Event::KeyPressed: {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) == true)
                {
                    InterWindow.close();
                    break;
                }
            }
            case sf::Event::MouseMoved:
            {
                mouseMovement(InterBoard, InterWindow);
                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                mouseTouched(InterBoard, InterWindow, InterEvent);
                break;
            }
        }

        if(Point == -1 || Point == 6)
        {
            Option=1;
            break;
        }
    }
}

int Game::getPoint()
{
    return Point;
}