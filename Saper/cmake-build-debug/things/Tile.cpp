//
// Created by szymon on 17.05.23.
//

#include "Tile.h"

void Tile::converter()
{
    switch (Underground)
    {
        case 1:
            PlayerVision="1";
            break;
        case 2:
            PlayerVision="2";
            break;
        case 3:
            PlayerVision="3";
            break;
        case 4:
            PlayerVision="4";
            break;
        case 5:
            PlayerVision="5";
            break;
        case 6:
            PlayerVision="6";
            break;
        case 7:
            PlayerVision="7";
            break;
        case 8:
            PlayerVision="8";
            break;
        case 9:
            PlayerVision="*";
            break;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////

Tile::Tile(int UnderNumber)
{
    Underground=UnderNumber;
    converter();
}

void Tile::operator++(int)
{
    Underground++;
    converter();
}

int Tile::getNumber()
{
    return Underground;
}

void Tile::setNumber(int UnderNumb)
{
    Underground=UnderNumb;
    converter();
}

bool Tile::getPosition()
{
    return TilePosition;
}

void Tile::changePosition()
{
    TilePosition=true;
}

void Tile::operator<<(bool PrintFlag)
{
    TileFlag=PrintFlag;
}

bool Tile::getFlag()
{
    return TileFlag;
}