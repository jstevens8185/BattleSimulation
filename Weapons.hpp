//
//  Weapons.hpp
//  BSv0.3
//
//  Created by Jered Stevens on 2/9/23.
//

#ifndef Weapons_hpp
#define Weapons_hpp

#include <stdio.h>

enum weaponType
{
    NONE,
    HANDGUN,
    MARKSMAN_RIFLE,
    SNIPER,
    ASSULT_RIFLE,
    LAUNCHER,
    MACHINE_GUN,
    SUB_MACHINE_GUN,
    CROSSBOW,
    STAFF,
    SWORD,
    DAGGER
};

class Weapon
{
private:
protected:
    weaponType type;
    double damage; // HP per shot
    double rateOfFire; // Shots per second
    double range; // Meters
    int magazineSize;
    int roundsLeft;
    double accuracy; // Percentage
    
public:
    virtual void setType(weaponType wType);
    virtual weaponType getWeaponType();
    virtual void setDamage(double dam);
    virtual double getDamage();
    virtual void setRateOfFire(double rof);
    virtual double getRateOfFire();
    virtual void setRange(double ran);
    virtual double getRange();
    virtual void setMagazineSize(int mag);
    virtual int getMagazineSize();
    virtual void setRoundsLeft(int rou);
    virtual double getRoundsLeft();
    virtual void setAccuracy(double acc);
    virtual double getAccuracy();
    virtual bool isEmpty();
    virtual void fire();
    virtual void reload();
};

class HandGun : public Weapon
{
private:
public:
    HandGun();
    HandGun(int dam, double rof, double ran, int magSize, double acc);
};

class SMG : public Weapon
{
private:
public:
    SMG();
    SMG(int dam, double rof, double ran, int magSize, double acc);
};

class AssultRifle : public Weapon
{
private:
public:
    AssultRifle();
    AssultRifle(int dam, double rof, double ran, int magSize, double acc);
};
#endif /* Weapons_hpp */
