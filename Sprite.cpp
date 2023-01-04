/***************************************************************************
 * File:	Sprite.cpp
 * Author: 	Jered Stevens
 * 
 * What it is:
 * 		Contains definitions for Sprites and all of it's subclasses.
 * 		Each subclass has it's own unique attributes, such as the medic
 * 		having the ability to heal other sprites.
*******************************************************************************/

#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Map.cpp"
#include "Weapons.cpp"
#include "Components.cpp"



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


class cSprite {
private:
	LocationCoordinates location;
protected:
	SpriteClass classType;
	Health	health;
	double moveSpeed;
	double jumpHeight;
	double armourRating;
	Melee melee;
	Weapon* weapon;

public:
	virtual SpriteClass getClassType() {
		return classType;
	}
	virtual void setClassType(SpriteClass newType){
		classType = newType;
		return;
	}
	virtual double getHealth() {
		return health.getHealth();
	}
	virtual void setHealth(double h) {
		health.setHealth(h);
	}
	virtual void increaseHealth(int amount) {
		if ((health.getHealth() + amount) < 100) {
			health.setHealth(health.getHealth() + amount);
			return;
		}
		else {
			health.setHealth(100);
			return;
		}
	}
	virtual void reduceHealth(double d) {
		health.setHealth(health.getHealth() - (d / armourRating));
	}
	virtual bool isAlive() {
		if (health.getHealth() > 0) {
			return true;
		}
		else
			return false;
	}
	virtual void attack(cSprite& target) {
		//If target is type operator, no damage can be dealt. You do what we do. Run.
		//If attacker is within melee range of target- attack with melee damage
		//If attacker is within gunRange of target - attack with damage
		if(target.getClassType() == OPERATOR){
			std::cout << "No damage can be dealt to God.\n";
			return;
		}
		if (melee.isWithinMeleeRange(this ,target))
		{
			target.reduceHealth(melee.getDamage());
			std::cout << "Successful Melee attack!" << std::endl;
			return;
		}
		else if (weapon->isWithinWeaponRange(this, target))
		{
			srand(time(0));
			int hitChance;
			for(int i = 0; i < weapon->getRateOfFire(); i++){
				weapon->fire();
				hitChance = (rand() % 100);
				if(hitChance < weapon->getAccuracy()){
					target.reduceHealth(weapon->getDamage());
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
	virtual void move(float x, float y, float z){
		location.updatePosition(x, y, z);
	}
    virtual void printLocation(){
        LocationCoordinates* tempLocation = location.getLocation();
        std::cout << "X: " << tempLocation->getXPosition() << ", "
            << "Y: " << tempLocation->getYPosition() << ", "
            << "Z: " << tempLocation->getZPosition() << ", ";
        delete tempLocation;
        return;
    }
	// bool isWithinMeleeRange(cSprite& target){
	// 	if (sqrt((location.getXPosition() - target.location.getXPosition())*(location.getXPosition() - target.location.getXPosition())
	// 		+ (location.getYPosition() - target.location.getYPosition())*(location.getYPosition() - target.location.getYPosition())  
	// 		+ (location.getZPosition() - target.location.getZPosition())*(location.getZPosition() - target.location.getZPosition())) <= meleeRange)
	// 	{
	// 		return true;
	// 	}

	// 	else
	// 	{
	// 		return false;
	// 	}
	// }
	// bool isWithinWeaponRange(cSprite& target){
	// 	if (sqrt((this->location.getXPosition() - target.location.getXPosition())*(this->location.getXPosition() - target.location.getXPosition())
	// 		+ (this->location.getYPosition() - target.location.getYPosition())*(this->location.getYPosition() - target.location.getYPosition())  
	// 		+ (this->location.getZPosition() - target.location.getZPosition())*(this->location.getZPosition() - target.location.getZPosition())) <= this->gunRange)
	// 	{
	// 		return true;
	// 	}

	// 	else
	// 	{
	// 		return false;
	// 	}
	// }
	float getXCoordinate()
	{
		return location.getXPosition();
	}
	float getYCoordinate()
	{
		return location.getYPosition();
	}
	float getZCoordinate()
	{
		return location.getZPosition();
	}
};

class Tank : public cSprite
{
private:
	int numBombs; 
public:
	Tank() :cSprite(100, 1, 5, .5, 1, 4, 100, TANK) {
		numBombs = 3;
		melee.setRange(1); //Meters
		melee.setDamage(30); //HP
		gunRange = 30; //Meters
		accuracy = 30; //Percentage
	}
	Tank(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull, int nBombs) : cSprite(hel, dam, rof, mov, jmp, AR, numBull, TANK) {
		numBombs = nBombs;
		melee.setRange(1); //Meters
		melee.setDamage(30); //HP
		gunRange = 30; //Meters
		accuracy = 30; //Percentage
	}
	int getNumBombs(){
		return numBombs;
	}

};

class Medic : public cSprite
{
private:
	int healRate; //HP
	int healRange = 15; //Meters
	
public:
	Medic() : cSprite(100, 1, 3, 1, 1, 1, 15, MEDIC) {
		healRate = 1;
		melee.setRange(.7); //Meters
		melee.setDamage(30); //HP
		gunRange = 15; //Meters
		accuracy = 50; //Percentage
	};
	Medic(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull, int healRate) : cSprite(hel, dam, rof, mov, jmp, AR, numBull, MEDIC){
		healRate = healRate;
		melee.setRange(.7); //Meters
		melee.setDamage(30); //HP
		gunRange = 15; //Meters
		accuracy = 50; //Percentage
	}
	void healTeammate(cSprite& target) {
		//if (target.getClass() != BOSS) {
			target.increaseHealth(healRate);
		//}
	};
};

class Boss : public cSprite
{
private:
	
public:
	Boss() :cSprite(100, 5, .5, .4, 1, 10, 75, BOSS) {
		melee.setRange(1); //Meters
		melee.setDamage(30); //HealthPoints
		gunRange = 30; //Meters
		accuracy = 40; //Percentage
	};
	Boss(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull) : cSprite(hel, dam, rof, mov, jmp, AR, numBull, BOSS) {
	
	};
};