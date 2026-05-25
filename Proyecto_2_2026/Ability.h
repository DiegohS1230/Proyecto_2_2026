#pragma once
#include "Zone.h"
#include "Hero.h"
class Ability
{
protected:
	string name;
	int cost;
	public:
		Ability(string name = "", int cost = 0) : name(name), cost(cost) {}
		//gets
		string getName() { return name; }
		int getCost() { return cost; }
		//sets
		void setName(string name) { this->name = name; }
		void setCost(int cost) { this->cost = cost; }
		virtual ~Ability() = default;
		virtual void use(Hero* target) { target->receiveDamage(0); }
		virtual void use(Zone* target) { target->damage(0); }
};

