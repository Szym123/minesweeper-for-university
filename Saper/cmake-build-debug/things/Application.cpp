//
// Created by szymon on 14.05.23.
//

#include "Application.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Game.h"

void Application::changeMode(sf::Font &AppFontC)
{
    switch (Mode)
    {
        case 1:
        {
            if(VisionMode == 2)
            {
                delete AppInterface;
                AppBoard.resetBoard(AppFontC);
            }
            AppInterface=new MainMenu;

            displayYourScore();

            VisionMode=1;
            Mode=0;
            break;
        }
        case 2:
        {
            delete AppInterface;

            AppInterface=new Game(AppFontC);

            VisionMode=2;
            Mode=0;
            break;
        }
    }
}

void Application::displayMode()
{
    switch (VisionMode)
    {
        case 1:
        {
            AppMenu.draw(AppWindow);
            break;
        }
        case 2:
        {
            AppBoard.draw(AppWindow);
            break;
        }
    }
}

void Application::displayYourScore()
{
    if(AppPoint == -1)
    {
        AppMenu.setButtonTitle(1, {"You lost"});
        AppPoint=0;
    }
    if(AppPoint == 6)
    {
        AppMenu.setButtonTitle(1, {"You win"});
        AppPoint=0;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

Application::Application(sf::Font &AppFontA): AppWindow(sf::VideoMode(500, 600), "Saper", sf::Style::Close), AppMenu(AppFontA, 4), AppBoard(AppFontA, " ")
{
    AppInterface=new MainMenu;

    AppMenu.setButtonTitle(0, {"Saper"});
    AppMenu.setButtonTitle(2, {"New game"});
    AppMenu.setButtonTitle(3, {"Exit"});

    AppMenu.setButtonColor(sf::Color::Black, sf::Color::Transparent, 1);
}

void Application::loup(sf::Font &AppFontB)
{
    while(AppWindow.isOpen())
    {
        AppWindow.clear(sf::Color::Black);

        changeMode(AppFontB);
        displayMode();

        AppWindow.display();

        AppInterface->decisionLope(Mode, AppWindow, AppEvent, AppMenu, AppBoard);
        AppPoint=AppInterface->getPoint();
    }
}