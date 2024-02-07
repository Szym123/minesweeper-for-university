//
// Created by szymon on 12.05.23.
//

#include "Menu.h"

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Background.h"

using namespace std;

Menu::Menu(sf::Font &MenuFont, int Number): BgMenu({300, 400}, sf::Color::Red, {250, 250})
{
    Button StampButton(MenuFont);

    float Position=90;
    for(int i=0; i < Number; i++)
    {
        Tab.push_back(StampButton);
        Tab[i].setPosition({250, Position});
        Position+=60;
    }
}

void Menu::draw(sf::RenderWindow &Window) const
{
    Window.draw(BgMenu);
    for(int i=0; i < Tab.size(); i++)
    {
        Tab[i].draw(Window);
    }
}

void Menu::setButtonTitle(int PositionX, std::string NewMessage)
{
    Tab[PositionX]=(NewMessage);
}

void Menu::setButtonColor(sf::Color ColText, sf::Color ColButton, int Location)
{
    Tab[Location].setColor(ColButton, ColText);
}

int Menu::isMouseOver(sf::RenderWindow &WindowA)
{
    for(int i=0; i < Tab.size(); i++)
    {
        if(Tab[i].isMouseOver(WindowA) == true)
        {
            return i;
        }
    }
    return 0;
}

int Menu::getTabSize()
{
    return Tab.size();
}