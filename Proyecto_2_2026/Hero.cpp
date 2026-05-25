#include "Hero.h"
Hero::Hero(string name, int health, int power, Zone* currentZone)
{
	this->name = name;
	this->health = health;
	this->power = power;
	this->currentZone = currentZone;
}
Hero::~Hero(){ //void
}
//gets
string Hero::getName() { return name; }
int Hero::getHealth() { return health; }
int Hero::getPower() { return power; }
Zone* Hero::getCurrentZone(){return currentZone;}
//sets
void Hero::setName(string name) { this->name = name; }
void Hero::setHealth(int health) { this->health = health; }
void Hero::setPower(int power) { this->power = power; }
void Hero::setCurrentZone(Zone* currentZone){this->currentZone = currentZone;}

