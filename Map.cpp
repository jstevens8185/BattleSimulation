//
//  Map.cpp
//  BSv0.3
//
//  Created by Jered Stevens on 2/9/23.
//
#include <iostream>
#include "Map.hpp"

LocationCoordinates::LocationCoordinates()
{
    xPosition = 0;
    yPosition = 0;
    zPosition = 0;
}

LocationCoordinates::LocationCoordinates(float x, float y)
{
    xPosition = x;
    yPosition = y;
    zPosition = 0;
}
LocationCoordinates::LocationCoordinates(float x, float y, float z)
{
    xPosition = x;
    yPosition = y;
    zPosition = z;
}

LocationCoordinates* LocationCoordinates::getLocation()
{
    return new LocationCoordinates(this->xPosition, this->yPosition, this->zPosition);
}

void LocationCoordinates::updatePosition(float x, float y, float z)
{
    if((xPosition + x) > 50) {
                    xPosition = 50;
                    x = 0;
                }else if((xPosition + x) < -50){
                    xPosition = -50;
                    x = 0;
                }
                if((yPosition + y) > 50) {
                    yPosition = 50;
                    y = 0;
                }else if((yPosition + y) < -50){
                    yPosition = -50;
                    y = 0;
                }
                if((zPosition + z) > 100) {
                    zPosition = 100;
                    z = 0;
                }else if((zPosition + z) < 0){
                    zPosition = 0;
                    z = 0;
                }
                xPosition += x;
                yPosition += y;
                zPosition +=z;
}

std::ostream& operator<<(std::ostream& os, const LocationCoordinates& coord)
{
    os << "(" << coord.xPosition << ", " << coord.yPosition << ", " << coord.zPosition << ")";
    return os;
}
