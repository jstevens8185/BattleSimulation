#include "Sprite.h"


	Tank::Tank() :cSprite(100, 1, 5, .5, 1, 4, 100, TANK) 
    {
		numBombs = 3;
		meleeRange = 1; //Meters
		meleeDamage = 5; //HP
		gunRange = 30; //Meters
		accuracy = 30; //Percentage
	}
	Tank::Tank(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull, int nBombs) 
    : cSprite(hel, dam, rof, mov, jmp, AR, numBull, TANK) 
    {
		numBombs = nBombs;
		meleeRange = 1; //Meters
		meleeDamage = 5; //HP
		gunRange = 30; //Meters
		accuracy = 30; //Percentage
	}
	int Tank::getNumBombs()
    {
		return numBombs;
	}

