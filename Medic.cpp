#include "Sprite.h"


	Medic::Medic() : cSprite(100, 1, 3, 1, 1, 1, 15, MEDIC) 
    {
		healRate = 1;
		meleeRange = .7; //Meters
		meleeDamage = 2; //HP
		gunRange = 15; //Meters
		accuracy = 50; //Percentage
	};
	Medic::Medic(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull, int healRate) 
    : cSprite(hel, dam, rof, mov, jmp, AR, numBull, MEDIC)
    {
		healRate = healRate;
		meleeRange = .7; //Meters
		meleeDamage = 2; //HP
		gunRange = 15; //Meters
		accuracy = 50; //Percentage
	}
	void Medic::healTeammate(cSprite& target) 
    {
		//if (target.getClass() != BOSS) {
			target.increaseHealth(healRate);
		//}
	};
