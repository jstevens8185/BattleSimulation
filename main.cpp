#include <iostream>
#include <string>
#include <random>
#include "Sprite.cpp"







int main() {
	Tank tank1;
	Boss bossNas;
	Medic DrHouse;

	
	tank1.move(50,0,0);
	std::cout << "Tank location is "; 
	tank1.getLocation();
	std::cout << std::endl;
	bossNas.move(30,0,0);
	std::cout << "bossNass location is "; 
	bossNas.getLocation();
	std::cout << std::endl;
	tank1.attack(bossNas);
	std::cout << "bossNas health is " << bossNas.getHealth();
	
}