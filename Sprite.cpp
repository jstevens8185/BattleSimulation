//
//  Sprite.cpp
//  BSv0.3
//
//  Created by Jered Stevens on 2/9/23.
//

#include "Sprite.hpp"
#include <cmath>



void Sprite::setClassType(SpriteClass newType)
{
    classType = newType;
}
SpriteClass Sprite::getClassType()
{
    return classType;
};
void Sprite::setHealth(const double hel)
{
    health.setHealth(hel);
};
double Sprite::getHealth()
{
    return health.getHealth();
};
void Sprite::increaseHealth(const double amount)
{
    if ((health.getHealth() + amount) < 100) {
        health.setHealth(health.getHealth() + amount);
        return;
    }
    else {
        health.setHealth(100);
        return;
    }
};
/**
 *  reduceHealth is deducts amount from health, ignoring armour class
 */
void Sprite::reduceHealth(const double amount)
{
    setHealth(getHealth() - amount);
};
/**
 *  attackHealth is calculated by dividing the damage by armour class
 *      then subtracting that amount from the current health value
 */
void Sprite::attackHealth(const double amount)
{
    setHealth(getHealth() - (amount / armourClass));
};
bool Sprite::isAlive()
{
    if (getHealth() > 0) {
        return true;
    }
    else
        return false;
};
void Sprite::setMoveSpeed(const double move)
{
    moveSpeed = move;
};
double Sprite::getMoveSpeed()
{
    return moveSpeed;
};
void Sprite::setJumpHeight(const double jump)
{
    jumpHeight = jump;
};
double Sprite::getJumpHeight()
{
    return jumpHeight;
};
void Sprite::setArmourClass(const double armour)
{
    armourClass = armour;
};
double Sprite::getArmourClass()
{
    return armourClass;
};
void Sprite::attack(Sprite& target)
{
    //If target is type operator, no damage can be dealt. You do what we do. Run.
    //If attacker is within melee range of target- attack with melee damage
    //If attacker is within gunRange of target - attack with damage
            if(target.getClassType() == OPERATOR){
                std::cout << "No damage can be dealt to a God.\n";
                return;
            }
            if (isWithinMeleeRange(target))
            {
                target.attackHealth(getMeleeDamage());
                std::cout << "Successful Melee attack!" << std::endl;
                return;
            }
            else if (isWithinWeaponRange(target))
            {
                srand(static_cast<int> (time(0)));
                int hitChance;
                for(int i = 0; i < getWeaponROF(); i++){
                    ;
                    hitChance = (rand() % 100);
                    if(hitChance < getAccuracy()){
                        target.attackHealth(getWeaponDamage());
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
    return;
};
void Sprite::move(const float x, const float y, const float z)
{
    location.updatePosition(x, y, z);
};
bool Sprite::isWithinMeleeRange(Sprite& target)
{
    if (distanceBetween(this, target) <= getMeleeRange())
    {
        return true;
    }
    
    else
    {
        return false;
    }
};
bool Sprite::isWithinWeaponRange(Sprite& target)
{
    if (distanceBetween(this, target) <= getWeaponRange())
    {
        return true;
    }
    
    else
    {
        return false;
    }
};
float Sprite::getXCoord()
{
    return location.getXPosition();
};
float Sprite::getYCoord()
{
    return location.getYPosition();
};
float Sprite::getZCoord()
{
    return location.getZPosition();
};
LocationCoordinates Sprite::getLocationCoord()
{
    return location;
};
void Sprite::setMeleeDamage(const double dam)
{
    melee.setDamage(dam);
};
double Sprite::getMeleeDamage()
{
    return melee.getDamage();
};
void Sprite::setMeleeRange(const double ran)
{
    melee.setRange(ran);
};
double Sprite::getMeleeRange()
{
    return melee.getRange();
};
weaponType Sprite::getWeaponType()
{
    return equippedWeapon->getWeaponType();
};
void Sprite::fireWeapon()
{
    equippedWeapon->fire();
}
double Sprite::getWeaponDamage()
{
    return equippedWeapon->getDamage();
};
double Sprite::getWeaponROF()
{
    return equippedWeapon->getRateOfFire();
};
double Sprite::getWeaponRange()
{
    return equippedWeapon->getRange();
};
int Sprite::getMagazineSize()
{
    return equippedWeapon->getMagazineSize();
};
int Sprite::getRoundsLeft()
{
    return equippedWeapon->getRoundsLeft();
};
double Sprite::getAccuracy()
{
    return equippedWeapon->getAccuracy();
};

double Sprite::distanceBetween(Sprite* original, Sprite& target)
{
    return sqrt((original->getXCoord() - target.getXCoord())*(original->getXCoord() - target.getXCoord())
             + (original->getYCoord() - target.getYCoord())*(original->getYCoord() - target.getYCoord())
             + (original->getZCoord() - target.getZCoord())*(original->getZCoord() - target.getZCoord()));
}

// SpriteNode::SpriteNode()
// {
//     sprite = nullptr;
//     next = prev = nullptr;
//     aggro = 0;
// };

// SpriteNode::SpriteNode(Sprite& target)
// {
//     sprite = &target;
//     next = prev = nullptr;
//     aggro = 0;
// }

/**
 * Array structure to hold sprite node. Enemys will contain a SpriteArray to
 *  keep track of who has the highest aggro
 * 
 **/

// SpriteArray::SpriteArray()
// {
//       top = 1;
// };

// void SpriteArray::push(Sprite& spr)
// {
    
// }

/**
 *  Class:      Tank : Sprite
 *
 *  The Tank class is unique because of his ability to soak up
 *      a lot of damage, taunt the enemy, and keep attention
 *      on him through a highrate of weak attacks.
 */

Tank::Tank()
{
    setClassType(TANK);
    setHealth(100);
    setArmourClass(100);
    setMoveSpeed(2);
    setJumpHeight(1);
    setMeleeRange(1);
    setMeleeDamage(20);
    equippedWeapon = new SMG();
};

void Tank::taunt(Sprite& target)
{
    return;
};

Tank::~Tank()
{
    delete equippedWeapon;
};

/**
 *  Class:      Medic : Sprite
 *
 *  The Medic is unique because he has the ability to heal team members.
 *  He will have a lower than normal armourClass though and deal less damage
 *  than other classes.
 **/

Medic::Medic()
{
    setClassType(MEDIC);
    setHealth(100);
    setArmourClass(50);
    setMoveSpeed(4);
    setJumpHeight(1.2);
    setMeleeRange(1);
    setMeleeDamage(15);
    equippedWeapon = new HandGun();
    setHealRate(5);
    setHealRange(5);
}

void Medic::healTeammate(Sprite& target)
{
    if (target.getClassType() != BOSS && target.getClassType() != MINION)
    {
        target.increaseHealth(getHealRate());
    };

    return;
}

void Medic::setHealRate(const double hRate)
{
    healRate = hRate;
};
double Medic::getHealRate()
{
    return healRate;
};
void Medic::setHealRange(const double hRange)
{
    healRange = hRange;
}
double Medic::getHealRange()
{
    return healRange;
};

/**
 * Class:       Dps : Sprite
 *
 **/


Dps::Dps()
{
    setClassType(DPS);
    setHealth(100);
    setArmourClass(50);
    setMoveSpeed(3);
    setJumpHeight(1.5);
    setMeleeRange(1.5);
    setMeleeDamage(25);
    equippedWeapon = new AssultRifle();
};


/**
 *  The enemy class serves as a base class for Boss and Minion
 *  They will be unique because they will contain a member
 *      to keep track of agro towards the attacker
 */

Enemy::Enemy()
{
    
};
