#include <iostream>
#include <string>
#include <random>
#include "Sprite.cpp"







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