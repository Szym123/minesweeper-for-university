//
// Created by szymon on 14.05.23.
//

#include "MainMenu.h"
#include "Interface.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"

void MainMenu::mouseMovement(Menu &MenuGraphics, sf::RenderWindow &MenuWindow)
{
    int Number=MenuGraphics.isMouseOver(MenuWindow);
    if(Number == 0)
    {
        for(int i=2; i < MenuGraphics.getTabSize(); i++)
        {
            MenuGraphics.setButtonColor(sf::Color::Black, sf::Color::Green, i);
        }
    }
    if(Number > 1)
    {
        MenuGraphics.setButtonColor(sf::Color::Red, sf::Color::Yellow, Number);
    }
}

int MainMenu::mouseTouched(Menu &MenuGraphicsA, sf::RenderWindow &MenuWindowA, sf::Event &MenuEventA)
{
    int Position,Answer=0;

    if(MenuEventA.mouseButton.button == sf::Mouse::Left)
    {
        Position=MenuGraphicsA.isMouseOver(MenuWindowA);
        switch (Position)
        {
            case 2:
            {
                Answer=2;
                break;
            }
            case 3:
            {
                MenuWindowA.close();
                break;
            }
        }
    }
    return  Answer;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainMenu::decisionLope(int &Option, sf::RenderWindow &InterWindow, sf::Event &InterEvent, Menu &InterGraphics, Board &InterBoard)
{

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
                mouseMovement(InterGraphics, InterWindow);
                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                Option=mouseTouched(InterGraphics, InterWindow, InterEvent);
                break;
            }
        }
    }
}

int MainMenu::getPoint()
{
    return 0;
}