#pragma once
#include <iostream>
#include <string>
#include "Zone.h"
using namespace std;
class Hero{
protected:
		string name;
		int health;
		int power;
		Zone* currentZone;
public:
	Hero(string name = "", int health = 100, int power = 10, Zone* currentZone = nullptr);
	virtual ~Hero();
	//gets
	string getName();
	int getHealth();
	int getPower();
	Zone* getCurrentZone();
	//sets
	void setName(string name);
	void setHealth(int health);
	void setPower(int power);
	void setCurrentZone(Zone* currentZone);
	// Simulation behavior
	virtual void attack(Hero& target) = 0; // función pura virtual, cada clase derivada debe implementarla
	virtual void moveTo(Zone* newZone) = 0;
	virtual void receiveDamage(int damage) = 0;
	virtual bool isAlive() = 0;
	virtual string toString() = 0;

};

