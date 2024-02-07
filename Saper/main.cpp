#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "cmake-build-debug/things/Application.h"
#include "cmake-build-debug/things/Menu.h"
#include "cmake-build-debug/things/Board.h"

using namespace  std;

int main()
{
    sf::Font appFont;
    appFont.loadFromFile("font.ttf");

    Application app(appFont);

    app.loup(appFont);
    return 0;
}