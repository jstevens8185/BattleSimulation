/***************************************************************************
 * File:	Sprite.cpp
 * Author: 	Jered Stevens
 * 
 * What it is:
 * 		Contains definitions for Sprites and all of it's subclasses.
 * 		Each subclass has it's own unique attributes, such as the medic
 * 		having the ability to heal other sprites.
*******************************************************************************/

#ifndef SPRITE
#define SPRITE

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Map.h"




enum SpriteClass {TANK, BOSS, DPS, MEDIC, MINION, OPERATOR};

/************************************************************************************
 * Class: 		cSprite
 * 
 * Purpose:		This is the parent class for all units. Contains functions and variables
 * 				held by every unit, such as health, move speed, and location within map.
 * 
 * Private Member Variables:
 * 				LocationCoordinates location
 * 
 * Protected Member Variables:
 * 				SpriteClass classType;
 *				double health;
 *				double damage;
 *				double rateOfFire;
 *				double moveSpeed;
 *				double jumpHeight;
 *				double armourRating;
 *				int numBullets;
 *				int meleeRange; 	-->Meters
 *				int meleeDamage; 	-->HealthPoints
 *				int gunRange; 		-->Meters
 *				int accuracy; 		-->Percentage 
 *
 * Constructors:
 * 				cSprite() - default constructor, God mode class
 * 
 * 				cSprite(double, double, double, double, double, double, int, SpriteClass)
 * 					-Standard constructor for playable types
 * 					-Parameters are as follows:
 * 						health
 * 						damage
 * 						rate of fire
 * 						movement speed
 * 						jump height
 * 						Armor rating
 * 						number of bullets
 * 						class type
 * 
 * Functions:
 * 				getClassType() -> returns SpriteClass
 * 				setClassType(SpriteClass) -> returns void
 * 				getHealth() -> returns double
 * 				setHealth(double) -> returns void
 * 				increaseHealth(int) -> returns void
 * 				reduceHealth(double) -> returns void
 * 				isAlive() -> returns bool
 * 				attack(cSprite&) -> returns void
 * 				move(float, flaot, float) -> returns void
 * 				printLocation() -> returns void
 * 				isWithinMeleeRange(cSprite&) -> returns bool
 * 				isWithinWeaponRange(cSprite&) -> returns bool
*************************************************************************************/

class cSprite {
private:
	LocationCoordinates location;
protected:
	SpriteClass classType;
	double health;
	double damage;
	double rateOfFire;
	double moveSpeed;
	double jumpHeight;
	double armourRating;
	int numBullets;
	int meleeRange; //Meters
	int meleeDamage; //HealthPoints
	int gunRange; //Meters
	int accuracy; //Percentage

public:
	cSprite(); 
	cSprite(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull, SpriteClass sClass);
	virtual SpriteClass getClassType(); 
	virtual void setClassType(SpriteClass newType);
	virtual double getHealth();
	virtual void setHealth(double h);
	virtual void increaseHealth(int amount); 
	virtual void reduceHealth(double d); 
	virtual bool isAlive(); 
	virtual void attack(cSprite& target); 
	virtual void move(float x, float y, float z);
    void printLocation();
	bool isWithinMeleeRange(cSprite& target);
	bool isWithinWeaponRange(cSprite& target);
};

class Tank : public cSprite
{
private:
	int numBombs; 
public:
	Tank();
	Tank(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull, int nBombs);
	int getNumBombs();
};

class Medic : public cSprite
{
private:
	int healRate; //HP
	int healRange = 15; //Meters
	
public:
	Medic();
	Medic(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull, int healRate);
	void healTeammate(cSprite& target);
};

class Boss : public cSprite
{
private:
	
public:
	Boss();
	Boss(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull);
};

#endif