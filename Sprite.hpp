//Implementation of Sprite.h

#include "Sprite.h"

cSprite::cSprite() 
	{
		health = 100.00;
		damage = 1.00;
		rateOfFire = 1.00;
		moveSpeed = 1.00;
		jumpHeight = 1.00;
		armourRating = 100.00;
		numBullets = 30;
		meleeRange = 5;
		meleeDamage = 25;
		gunRange = 1000;
		accuracy = 100;
		classType = OPERATOR;
	}

cSprite::cSprite(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull, SpriteClass sClass) 
	{
		health = hel;
		damage = dam;
		rateOfFire = rof;
		moveSpeed = mov;
		jumpHeight = jmp;
		armourRating = AR;
		numBullets = numBull;
		classType = sClass;
	}

SpriteClass cSprite::getClassType() 
	{
		return classType;
	}

void cSprite::setClassType(SpriteClass newType)
	{
		classType = newType;
		return;
	}
double cSprite::getHealth()
 	{
		return health;
	}
void cSprite::setHealth(double h)
 	{
		health = h;
	}
void cSprite::increaseHealth(int amount)
 	{
		if ((health + amount) < 100) {
			health += amount;
			return;
		}
		else {
			health = 100;
			return;
		}
	}
void cSprite::reduceHealth(double d)
 	{
		health = health - (d / armourRating);
	}
bool cSprite::isAlive()
 	{
		if (health > 0) {
			return true;
		}
		else
			return false;
	}
void cSprite::attack(cSprite& target)
 	{
		//If target is type operator, no damage can be dealt. You do what we do. Run.
		//If attacker is within melee range of target- attack with melee damage
		//If attacker is within gunRange of target - attack with damage
		if(target.getClassType() == OPERATOR){
			std::cout << "No damage can be dealt to God.\n";
			return;
		}
		if (isWithinMeleeRange(target))
		{
			target.reduceHealth(meleeDamage);
			std::cout << "Successful Melee attack!" << std::endl;
			return;
		}
		else if (isWithinWeaponRange(target))
		{
			srand(time(0));
			int hitChance;
			for(int i = 0; i < rateOfFire; i++){
				hitChance = (rand() % 100);
				if(hitChance < accuracy){
					target.reduceHealth(damage);
					std::cout << "Successful Weapon attack!" << std::endl;
				}
				else
				{
					std::cout << "Attack missed" << std::endl;
				}
			}
			return;
		}
		else
		{
			std::cout << "Target is out of range" << std::endl;
		}
	}
void cSprite::move(float x, float y, float z)
	{
		location.updatePosition(x, y, z);
	}
void cSprite::printLocation()
	{
        LocationCoordinates* tempLocation = location.getLocation();
        std::cout << "X: " << tempLocation->getXPosition() << ", "
            << "Y: " << tempLocation->getYPosition() << ", "
            << "Z: " << tempLocation->getZPosition() << ", ";
        delete tempLocation;
        return;
    }
bool cSprite::isWithinMeleeRange(cSprite& target)
	{
		if (sqrt((location.getXPosition() - target.location.getXPosition())*(location.getXPosition() - target.location.getXPosition())
			+ (location.getYPosition() - target.location.getYPosition())*(location.getYPosition() - target.location.getYPosition())  
			+ (location.getZPosition() - target.location.getZPosition())*(location.getZPosition() - target.location.getZPosition())) <= meleeRange)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
bool cSprite::isWithinWeaponRange(cSprite& target)
	{
		if (sqrt((this->location.getXPosition() - target.location.getXPosition())*(this->location.getXPosition() - target.location.getXPosition())
			+ (this->location.getYPosition() - target.location.getYPosition())*(this->location.getYPosition() - target.location.getYPosition())  
			+ (this->location.getZPosition() - target.location.getZPosition())*(this->location.getZPosition() - target.location.getZPosition())) <= this->gunRange)
		{
			return true;
		}

		else
		{
			return false;
		}
	}