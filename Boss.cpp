#include "Sprite.h"


	Boss::Boss() :cSprite(100, 5, .5, .4, 1, 10, 75, BOSS) 
    {
		meleeRange = 1; //Meters
		meleeDamage = 7; //HealthPoints
		gunRange = 30; //Meters
		accuracy = 40; //Percentage
	};
	Boss::Boss(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull) 
    : cSprite(hel, dam, rof, mov, jmp, AR, numBull, BOSS) 
    {
        
	};