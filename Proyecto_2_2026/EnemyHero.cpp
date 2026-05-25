#include "EnemyHero.h"
#include "HeroStrategy.h"
#include "Player.h"
#include <sstream>

HeroStrategy* EnemyHero::getStrategy()
{
	return strategy;
}

void EnemyHero::setStrategy(HeroStrategy* strategy) {
	if (this->strategy != nullptr) {
		delete this->strategy;
	}

	this->strategy = strategy;
}

void EnemyHero::act(Player* player) {
	if (strategy != nullptr) {
		strategy->execute(this, player);
	}
}

EnemyHero::EnemyHero(string name, int health, int power, Zone* currentZone): Hero(name, health, power, currentZone) {
	this->strategy = nullptr;
}

EnemyHero::~EnemyHero()	
{
	delete strategy;
}

void EnemyHero::attack(Hero& target)
{
	target.receiveDamage(this->power);
}

void EnemyHero::moveTo(Zone* newZone)
{
	this->currentZone = newZone;
}

void EnemyHero::receiveDamage(int damage)
{
	this->health -= damage;
	if (this->health < 0) this->health = 0;
}

bool EnemyHero::isAlive()
{
	if (health > 0) return true;
    return false;
}

string EnemyHero::toString()
{
	stringstream ss;
	 ss << "Enemy Hero: " << name << "\n";
	 ss << "Health: " << health << "\n";
	 ss << "Power: " << power << "\n";
	 if (currentZone) {
		 ss << "Current Zone: " << currentZone->getName() << "\n";
	 } else {
		 ss << "Current Zone: None\n";
	 }
    return ss.str();
}
