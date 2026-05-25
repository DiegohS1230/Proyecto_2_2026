#pragma once
#include "Hero.h"
#include "Ability.h"
class Player : public Hero{
private:
	Ability* ability;
	public:
	Player(string name = "", int health = 100, int power = 20, Zone* currentZone = nullptr, Ability* ability = nullptr);
	~Player();
	//gets
	Ability* getAbility();
	//sets
	void setAbility(Ability* ability);
	void attack(Hero& target) override;
	void moveTo(Zone* newZone) override;
	void receiveDamage(int damage) override;
	bool isAlive() override;
	string toString() override;
};

