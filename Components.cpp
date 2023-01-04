#ifndef _COMPONENTS_CPP
#define _COMPONENTS_CPP

#include "Map.cpp"
#include "Sprite.cpp"


/****************************************************
 * File:        Components.cpp
 * 
 * Purpose:     Holds all the different components 
 *              to be used by sprites
 * 
 * Author:      Jered Stevens
 * Date:        1/2/23
******************************************************/


enum SpriteClass {TANK, BOSS, DPS, MEDIC, MINION, OPERATOR};

struct Health
{   
    double sHealth;

    Health()
    {
        sHealth = 100;
    }
    Health(double x)
    {
        sHealth = x;
    }
    double getHealth()
    {
        return sHealth;
    }
    void setHealth(double x)
    {
        sHealth = x;
    }
};

struct Melee
{
    double meleeDamage;
    double meleeRange;

    Melee()
    {
        meleeDamage = 1;
        meleeRange = 1;
    }
    Melee(double mDam, double mRange)
    {
        meleeDamage = mDam;
        meleeRange = mRange;
    }
    void setDamageAndRange(double d, double r){
        meleeDamage = d;
        meleeRange = r;
    }
    void setDamage(double d)
    {
        meleeDamage = d;
    }
    void setRange(double r)
    {   
        meleeRange = r;
    }
    double getDamage()
    {
        return meleeDamage;
    }
    double getRange()   
    {
        return meleeRange;
    }
    bool isWithinMeleeRange(cSprite* attacker, cSprite& target){
        if (sqrt((attacker->getXCoordinate() - target.getXCoordinate())*(attacker->getXCoordinate() - target.getXCoordinate())
			+ (attacker->getYCoordinate() - target.getYCoordinate())*(attacker->getYCoordinate() - target.getYCoordinate())  
			+ (attacker->getZCoordinate() - target.getZCoordinate())*(attacker->getZCoordinate() - target.getZCoordinate())) <= meleeRange)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
};


#endif