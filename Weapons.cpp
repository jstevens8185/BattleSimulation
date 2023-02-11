//
//  Weapons.cpp
//  BSv0.3
//
//  Created by Jered Stevens on 2/9/23.
//

#include "Weapons.hpp"
#include <iostream>

void Weapon::setType(weaponType wType)
{
    type = wType;
};

weaponType Weapon::getWeaponType()
{
    return type;
};

void Weapon::setDamage(double dam)
{
    damage = dam;
};
double Weapon::getDamage()
{
    return damage;
};
void Weapon::setRateOfFire(double rof)
{
    rateOfFire = rof;
};
double Weapon::getRateOfFire()
{
    return rateOfFire;
};
void Weapon::setRange(double ran)
{
    range = ran;
};
double Weapon::getRange()
{
    return range;
};
void Weapon::setMagazineSize(int mag)
{
    magazineSize = mag;
};
int Weapon::getMagazineSize()
{
    return magazineSize;
};
void Weapon::setRoundsLeft(int rou)
{
    roundsLeft = rou;
};
double Weapon::getRoundsLeft()
{
    return roundsLeft;
};
void Weapon::setAccuracy(double acc)
{
    accuracy = acc;
};
double Weapon::getAccuracy()
{
    return accuracy;
};
bool Weapon::isEmpty()
{
    if (roundsLeft > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
};
void Weapon::fire()
{
    if(isEmpty())
    {
        reload();
        return;
    }else
    {
        roundsLeft--;
    }
};
void Weapon::reload(){
    std::cout << "RELOADING!\n";
    roundsLeft = magazineSize;
};

HandGun::HandGun()
{
    setType(HANDGUN);
    setDamage(10.00);   // Damage per shot
    setRateOfFire(2);// Shots per second
    setRange(15.00);    // Meters
    setMagazineSize(13);
    setRoundsLeft(getMagazineSize());
    setAccuracy(75.00);
};

SMG::SMG()
{
    setType(SUB_MACHINE_GUN);
    setDamage(5.00);   // Damage per shot
    setRateOfFire(8);// Shots per second
    setRange(15.00);    // Meters
    setMagazineSize(30);
    setRoundsLeft(getMagazineSize());
    setAccuracy(60);
};
