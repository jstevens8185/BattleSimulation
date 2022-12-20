#include <iostream>
#include <string>
#include <random>

enum SpriteClass {TANK, BOSS, DPS, MEDIC, MINION, OPERATOR};

class cSprite {
private:
protected:
	SpriteClass classType;
	double health;
	double damage;
	double rateOfFire;
	double moveSpeed;
	double armourRating;
	int numBullets;

public:
	cSprite() {
		health = 100.00;
		damage = 1.00;
		rateOfFire = 1.00;
		moveSpeed = 1.00;
		armourRating = 1.00;
		numBullets = 30;
		classType = OPERATOR;
	}
	cSprite(double hel, double dam, double rof, double mov, double AR, int numBull, SpriteClass sClass) {
		health = hel;
		damage = dam;
		rateOfFire = rof;
		moveSpeed = mov;
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
		target.reduceHealth(damage);
	}
};

class Tank : public cSprite
{
private:
	int numBombs;
public:
	Tank() :cSprite(100, 1, 5, .5, 4, 100, TANK) {
		numBombs = 3;
	}
	Tank(double hel, double dam, double rof, double mov, double AR, int numBull, int nBombs) : cSprite(hel, dam, rof, mov, AR, numBull, TANK) {
		numBombs = nBombs;
	}
	int getNumBombs(){
		return numBombs;
	}

};

class Medic : public cSprite
{
private:
	int healRate;
public:
	Medic() : cSprite(100, 1, 1, 1, 1, 15, MEDIC) {
		healRate = 1;
	};
	Medic(double hel, double dam, double rof, double mov, double AR, int numBull, int healRate) : cSprite(hel, dam, rof, mov, AR, numBull, MEDIC){
		healRate = healRate;
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
	Boss() :cSprite(100, 5, .5, .4, 10, 75, BOSS) {

	};
	Boss(double hel, double dam, double rof, double mov, double AR, int numBull) : cSprite(hel, dam, rof, mov, AR, numBull, BOSS) {
	
	};
};

int main() {
	Tank tank1;
	Boss bossNas;
	Medic DrHouse;

	std::cout << "tank1 health before attack: " << tank1.getHealth() << std::endl;
	bossNas.attack(tank1);
	std::cout << "tank1 health before heal: " << tank1.getHealth() << std::endl;
	DrHouse.healTeammate(tank1);
	std::cout << "tank1 health after heal: " << tank1.getHealth() << std::endl;
}