#pragma once
#include <iostream>
#include <cstdlib>
#include "Map.cpp"

enum SpriteClass {TANK, BOSS, DPS, MEDIC, MINION, OPERATOR};

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
	int meleeRange = 1; //Meters
	int meleeDamage = 7; //HealthPoints
	int gunRange = 30; //Meters
	int accuracy = 40; //Percentage

public:
	cSprite() {
		health = 100.00;
		damage = 1.00;
		rateOfFire = 1.00;
		moveSpeed = 1.00;
		jumpHeight = 1.00;
		armourRating = 1.00;
		numBullets = 30;
		classType = OPERATOR;
	}
	cSprite(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull, SpriteClass sClass) {
		health = hel;
		damage = dam;
		rateOfFire = rof;
		moveSpeed = mov;
		jumpHeight = jmp;
		armourRating = AR;
		numBullets = numBull;
		classType = sClass;
	}
	//cSprite(SpriteClass type) {
	//	classType = type;
	//	if (type == TANK) {
	//		health = 100;
	//		damage = 1;
	//		rateOfFire = 5;
	//		moveSpeed = .5;
	//		armourRating = 4;
	//		numBullets = 200;
	//	}
	//	if (type == BOSS) {
	//		health = 100;
	//		damage = 5;
	//		rateOfFire = .5;
	//		moveSpeed = .4;
	//		armourRating = 10;
	//		numBullets = 75;
	//	}
	//	if (type == DPS) {
	//		health = 100;
	//		damage = 2;
	//		rateOfFire = 2;
	//		moveSpeed = 1;
	//		armourRating = 1;
	//		numBullets = 30;
	//	}
	//	if (type == MEDIC) {
	//		health = 100;
	//		damage = 1;
	//		rateOfFire = 1;
	//		moveSpeed = 1;
	//		armourRating = 1;
	//		numBullets = 15;
	//	}
	//}

	virtual SpriteClass getClass() {
		return classType;
	}
	virtual double getHealth() {
		return health;
	}
	virtual void setHealth(double h) {
		health = h;
	}
	virtual void increaseHealth(int amount) {
		if ((health + amount) < 100) {
			health += amount;
			return;
		}
		else {
			health = 100;
			return;
		}
	}
	virtual void reduceHealth(double d) {
		health = health - (d / armourRating);
	}
	virtual bool isAlive() {
		if (health > 0) {
			return true;
		}
		else
			return false;
	}
	virtual void attack(cSprite& target) {
		//If attacker is within melee range of target- attack with melee damage
		//If attacker is within gunRange of target - attack with damage
		if (isWithinMeleeRange(target))
		{
			target.reduceHealth(meleeDamage);
			std::cout << "Successful Melee attack!" << std::endl;
			return;
		}
		else if (isWithinWeaponRange(target))
		{
			target.reduceHealth(damage);
			std::cout << "Successful Weapon attack!" << std::endl;
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
    void getLocation(){
        LocationCoordinates* tempLocation = location.getLocation();
        std::cout << "X: " << tempLocation->getXPosition() << ", "
            << "Y: " << tempLocation->getYPosition() << ", "
            << "Z: " << tempLocation->getZPosition() << ", ";
        delete tempLocation;
        return;
    }
	bool isWithinMeleeRange(cSprite& target){
		if (abs(location.getXPosition() - target.location.getXPosition()) <= meleeRange &&
		 	abs(location.getYPosition() - target.location.getYPosition()) <= meleeRange &&
			abs(location.getZPosition() - target.location.getZPosition()) <= meleeRange)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
	bool isWithinWeaponRange(cSprite& target){
		if (abs(location.getXPosition() - target.location.getXPosition()) <= gunRange &&
		 	abs(location.getYPosition() - target.location.getYPosition()) <= gunRange &&
			abs(location.getZPosition() - target.location.getZPosition()) <= gunRange)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
};

class Tank : public cSprite
{
private:
	int numBombs; 
public:
	Tank() :cSprite(100, 1, 5, .5, 1, 4, 100, TANK) {
		numBombs = 3;
		meleeRange = 1; //Meters
		meleeDamage = 5; //HP
		gunRange = 30; //Meters
		accuracy = 30; //Percentage
	}
	Tank(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull, int nBombs) : cSprite(hel, dam, rof, mov, jmp, AR, numBull, TANK) {
		numBombs = nBombs;
		meleeRange = 1; //Meters
		meleeDamage = 5; //HP
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
	Medic() : cSprite(100, 1, 1, 1, 1, 1, 15, MEDIC) {
		healRate = 1;
		meleeRange = .7; //Meters
		meleeDamage = 2; //HP
		gunRange = 15; //Meters
		accuracy = 50; //Percentage
	};
	Medic(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull, int healRate) : cSprite(hel, dam, rof, mov, jmp, AR, numBull, MEDIC){
		healRate = healRate;
		meleeRange = .7; //Meters
		meleeDamage = 2; //HP
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
		meleeRange = 1; //Meters
		meleeDamage = 7; //HealthPoints
		gunRange = 30; //Meters
		accuracy = 40; //Percentage
	};
	Boss(double hel, double dam, double rof, double mov, double jmp, double AR, int numBull) : cSprite(hel, dam, rof, mov, jmp, AR, numBull, BOSS) {
	
	};
};