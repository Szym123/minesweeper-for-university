//
// Created by szymon on 17.05.23.
//

#ifndef SAPER_TILE_H
#define SAPER_TILE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Tile
{
protected:
    int Underground;
    bool TilePosition= false;
    bool TileFlag= false;

    void converter();
public:
    std::string PlayerVision;

    Tile(int UnderNumber=0);
    void operator++(int);
    int getNumber();
    void setNumber(int UnderNumb);
    bool getPosition();
    void changePosition();
    void operator<<(bool PrintFlag);
    bool getFlag();

};


#endif //SAPER_TILE_H
