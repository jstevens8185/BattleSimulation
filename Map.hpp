//
//  Map.hpp
//  BSv0.3
//
//  Created by Jered Stevens on 2/9/23.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <iostream>

const int _NORTHWALL = 50;
const int _SOUTHWALL = -50;
const int _WESTWALL = -50;
const int _EASTWALL = 50;
const int _FLOOR = 0;
const int _CEILING = 100;

class LocationCoordinates {
private:
    float xPosition;
    float yPosition;
    float zPosition;
public:
    LocationCoordinates();
    LocationCoordinates(float x, float y);
    LocationCoordinates(float x, float y, float z);
    void setXPosition(float x) {xPosition = x;};
    void setYPosition(float y) {yPosition = y;};
    void setZPosition(float z) {zPosition = z;};
    float getXPosition() {return xPosition;};
    float getYPosition() {return yPosition;};
    float getZPosition() {return zPosition;};
    LocationCoordinates* getLocation();
    void updatePosition(float x, float y, float z);
    friend std::ostream& operator<<(std::ostream& os, const LocationCoordinates& coord);
};


#endif /* Map_hpp */
