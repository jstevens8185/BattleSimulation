//
//  Sprite.hpp
//  BSv0.3
//
//  Created by Jered Stevens on 2/9/23.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <stdio.h>
#include "Map.hpp"
#include "Components.hpp"
#include "Weapons.hpp"

enum SpriteClass {TANK, DPS, MEDIC, BOSS, MINION, OPERATOR};

/**
 *  Class: Sprite
 *
 *  Serves as the base class and interface for every character in the
 *      simulation. Contains all methods that are shared by all of
 *      the characters
 *
 *  Private Members:
 *      LocationCoordinates location
 *  Protected Members:
 *      SpriteClass classType;
 *      Health health;
 *      double armourClass;
 *      double moveSpeed;   // Meters per second
 *      double jumpHeight;  // Meters
 *      Melee melee;
 *      Weapon equippedWeapon;
 *  Public Methods:
 *      virtual void setClassType(SpriteClass newType);
 *      virtual SpriteClass getClassType();
 *      virtual void setHealth(const double hel);
 *      virtual double getHealth();
 *      virtual void increaseHealth(const double amount);
 *      virtual void reduceHealth(const double amount);
 *      virtual void attackHealth(const double amount);
 *      virtual bool isAlive();
 *      virtual void setMoveSpeed(const double move);
 *      virtual double getMoveSpeed();
 *      virtual void setJumpHeight(const double jump);
 *      virtual double getJumpHeight();
 *      virtual void setArmourClass(const double armour);
 *      virtual double getArmourClass();
 *      virtual void attack(Sprite& target);
 *      virtual void move(const float x, const float y, const float z);
 *      virtual bool isWithinMeleeRange(Sprite& target);
 *      virtual bool isWithinWeaponRange(Sprite& target);
 *      virtual float getXCoord();
 *      virtual float getYCoord();
 *      virtual float getZCoord();
 *      virtual LocationCoordinates getLocationCoord();
 *      virtual void setMeleeDamage(const double dam);
 *      virtual double getMeleeDamage();
 *      virtual void setMeleeRange(const double ran);
 *      virtual double getMeleeRange();
 *      virtual weaponType getWeaponType();
 *      virtual void fireWeapon();
 *      virtual double getWeaponDamage();
 *      virtual double getWeaponROF();
 *      virtual double getWeaponRange();
 *      virtual int getMagazineSize();
 *      virtual int getRoundsLeft();
 *      virtual double getAccuracy();
 */


class Sprite
{
private:
    LocationCoordinates location;
protected:
    SpriteClass classType;
    Health health;
    double armourClass;
    double moveSpeed;   // Meters per second
    double jumpHeight;  // Meters
    Melee melee;
    Weapon* equippedWeapon;
    
public:
    virtual void setClassType(SpriteClass newType);
    virtual SpriteClass getClassType();
    virtual void setHealth(const double hel);
    virtual double getHealth();
    virtual void increaseHealth(const double amount);
    virtual void reduceHealth(const double amount);
    virtual void attackHealth(const double amount);
    virtual bool isAlive();
    virtual void setMoveSpeed(const double move);
    virtual double getMoveSpeed();
    virtual void setJumpHeight(const double jump);
    virtual double getJumpHeight();
    virtual void setArmourClass(const double armour);
    virtual double getArmourClass();
    virtual void attack(Sprite& target);
    virtual void move(const float x, const float y, const float z);
    virtual bool isWithinMeleeRange(Sprite& target);
    virtual bool isWithinWeaponRange(Sprite& target);
    virtual float getXCoord();
    virtual float getYCoord();
    virtual float getZCoord();
    virtual LocationCoordinates getLocationCoord();
    virtual void setMeleeDamage(const double dam);
    virtual double getMeleeDamage();
    virtual void setMeleeRange(const double ran);
    virtual double getMeleeRange();
    virtual weaponType getWeaponType();
    virtual void fireWeapon();
    virtual double getWeaponDamage();
    virtual double getWeaponROF();
    virtual double getWeaponRange();
    virtual int getMagazineSize();
    virtual int getRoundsLeft();
    virtual double getAccuracy();
};


/**
 *  Struct: SpriteNode
 *
 *  To be used with SpriteList. SpriteNode will hold a pointer to a Sprite
 *      and an int to keep track of the current aggro associated with
 *      said Sprite.
 *
 *  Also contains 2 SpriteNode pointers to the next and the previous
 *      SpriteNodes.
 */
struct SpriteNode
{
private:
    Sprite* sprite;
    SpriteNode* next;
    SpriteNode* prev;
    int aggro;
public:
    SpriteNode();
    SpriteNode(Sprite& spr);
    ~SpriteNode();
    void setAggro(int agg);
    int getAggro();
    int increaseAggro();
};

/**
 *  Class:  SpriteList
 *
 *  Contains SpriteNodes with the ability to push new sprites
 *      onto the list and pop sprites off the list
 *
 **/
struct SpriteList
{
private:
    SpriteNode* first;
    SpriteNode* last;
public:
    SpriteList();
    SpriteList(Sprite& spr);
    void push(Sprite& spr);
    void pop(Sprite& spr);
};

/**
 *  Class:      Tank : Sprite
 *
 *  The Tank class is unique because of his ability to soak up
 *      a lot of damage, taunt the enemy, and keep attention
 *      on him through a highrate of weak attacks.
 **/

class Tank : public Sprite
{
private:
public:
    Tank();
    void taunt(Sprite& target);
    ~Tank();
};;

/**
 *  Class:      Medic : Sprite
 *
 *  The Medic is unique because he has the ability to heal team members.
 *  He will have a lower than normal armourClass though and deal less damage
 *  than other classes.
 **/
class Medic : public Sprite
{
private:
    double healRate;
    double healRange; // Meters
public:
    Medic();
    void healTeammate(Sprite& target);
};

/**
 *  Class:      Enemy : Sprite
 *
 *  The enemy class serves as a base class for Boss and Minion
 *  They will be unique because they will contain a member
 *      to keep track of agro towards the attacker
 **/

class Enemy : public Sprite
{
private:
    SpriteList targetList;
public:
    Enemy();
};



#endif /* Sprite_hpp */
