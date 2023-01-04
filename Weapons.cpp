#ifndef _WEAPONS_CPP
#define _WEAPONS_CPP

/*********************************************************
 * File:        Weapons.cpp
 * 
 * Purpose:     
 * 
 * 
 * 
 * Author:      Jered Stevens
 * Date:        12/28/22
 * 
***********************************************************/
#include "Sprite.cpp"
#include <iostream>

enum weaponType{NONE, HANDGUN, MARKSMAN_RIFLE, SNIPER, ASSULT_RIFLE, LAUNCHER, MACHINE_GUN, CROSSBOW};

class Weapon{
    private:
    protected:
        weaponType type;
        double damage;
        double rateOfFire; //number of shots per second
        double range;
        int magazineSize;
        int roundsLeft;
        double accuracy;
    public:
        virtual void setType(weaponType wType)
        {
            type = wType;
        }
        virtual weaponType getType()
        {
            return type;
        }
        virtual void setDamage(double d)
        {
            damage = d;
        }
        virtual double getDamage()
        {
            return damage;
        }
        virtual void setRateOfFire(double rof)
        {
            rateOfFire = rof;
        }
        virtual double getRateOfFire()
        {
            return rateOfFire;
        }
        virtual void setRange(double r)
        {
            range = r;
        }
        virtual double getRange()
        {
            return range;
        }
        virtual void setMagazineSize(int m)
        {
            magazineSize = m;
        }
        virtual int getMagazineSize()
        {
            return magazineSize;
        }
        virtual void setRoundsLeft(int r)
        {
            roundsLeft = r;
        }
        virtual int getRoundsLeft()
        {
            return roundsLeft;
        }
        virtual void setAccuracy(double a)
        {
            accuracy = a;
        }
        virtual double getAccuracy()
        {
            return accuracy;
        }
        virtual bool isEmpty()
        {
            if (roundsLeft > 0){
                return false;
            }
            else
            {
                return true;
            }
            
        }
        virtual void fire()
        {
            if(isEmpty())
            {
                reload();
                return;
            }else
            {
                roundsLeft--;
            }
        }
        virtual void reload()
        {
            std::cout << "RELOADING!\n";
            roundsLeft = magazineSize;
        }
        virtual bool isWithinWeaponRange(cSprite* attacker, cSprite& target){
            if (sqrt((attacker->getXCoordinate() - target.getXCoordinate())*(attacker->getXCoordinate() - target.getXCoordinate())
                + (attacker->getYCoordinate() - target.getYCoordinate())*(attacker->getYCoordinate() - target.getYCoordinate())  
                + (attacker->getZCoordinate() - target.getZCoordinate())*(attacker->getZCoordinate() - target.getZCoordinate())) <= range)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

class HandGun : public Weapon{
    private:

    public:
        HandGun()
        {
            type = HANDGUN;
            damage = 15;
            rateOfFire = 4; //4 shots per second
            range = 10; //10 meters
            magazineSize = roundsLeft = 20;
        };
        HandGun(weaponType wType, int dam, double rof, int ran, int magSize)
        {
            type = wType;
            damage = dam;
            rateOfFire = rof;
            range = ran;
            magazineSize = roundsLeft = magSize;
        }
};


#endif 