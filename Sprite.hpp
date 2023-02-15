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
 *      void setClassType(SpriteClass newType);
 *      SpriteClass getClassType();
 *      void setHealth(const double hel);
 *      double getHealth();
 *      void increaseHealth(const double amount);
 *      void reduceHealth(const double amount);
 *      void attackHealth(const double amount);
 *      bool isAlive();
 *      void setMoveSpeed(const double move);
 *      double getMoveSpeed();
 *      void setJumpHeight(const double jump);
 *      double getJumpHeight();
 *      void setArmourClass(const double armour);
 *      double getArmourClass();
 *      virtual void attack(Sprite& target);
 *      void move(const float x, const float y, const float z);
 *      bool isWithinMeleeRange(Sprite& target);
 *      bool isWithinWeaponRange(Sprite& target);
 *      float getXCoord();
 *      float getYCoord();
 *      float getZCoord();
 *      LocationCoordinates getLocationCoord();
 *      void setMeleeDamage(const double dam);
 *      double getMeleeDamage();
 *      void setMeleeRange(const double ran);
 *      double getMeleeRange();
 *      weaponType getWeaponType();
 *      void fireWeapon();
 *      double getWeaponDamage();
 *      double getWeaponROF();
 *      double getWeaponRange();
 *      int getMagazineSize();
 *      int getRoundsLeft();
 *      double getAccuracy();
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
    
    double distanceBetween(Sprite* Original, Sprite& Target);
public:
    void setClassType(SpriteClass newType);
    SpriteClass getClassType();
    void setHealth(const double hel);
    double getHealth();
    void increaseHealth(const double amount);
    void reduceHealth(const double amount);
    void attackHealth(const double amount);
    bool isAlive();
    void setMoveSpeed(const double move);
    double getMoveSpeed();
    void setJumpHeight(const double jump);
    double getJumpHeight();
    void setArmourClass(const double armour);
    double getArmourClass();
    virtual void attack(Sprite& target);
    void move(const float x, const float y, const float z);
    bool isWithinMeleeRange(Sprite& target);
    bool isWithinWeaponRange(Sprite& target);
    float getXCoord();
    float getYCoord();
    float getZCoord();
    LocationCoordinates getLocationCoord();
    void setMeleeDamage(const double dam);
    double getMeleeDamage();
    void setMeleeRange(const double ran);
    double getMeleeRange();
    weaponType getWeaponType();
    void fireWeapon();
    double getWeaponDamage();
    double getWeaponROF();
    double getWeaponRange();
    int getMagazineSize();
    int getRoundsLeft();
    double getAccuracy();
    
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
 *  Class:  SpriteArray
 *
 *  Contains SpriteNodes with the ability to push new sprites
 *      onto the list and pop sprites off the list
 *
 **/
struct SpriteArray
{
private:
    SpriteNode* list[20];
    int top;
public:
    SpriteArray();
    SpriteArray(Sprite& spr);
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
};

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
    double healRate; // HP per turn
    double healRange; // Meters
public:
    Medic();
    void setHealRate(const double hRate);
    double getHealRate();
    void setHealRange(const double hRange);
    double getHealRange();
    void healTeammate(Sprite& target);
};

/**
 * Class:       Dps : Sprite
 *
 **/

class Dps : public Sprite
{
private:
public:
    Dps();
    ~Dps();
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
//    SpriteArray targetList;
public:
    Enemy();
};



#endif /* Sprite_hpp */
