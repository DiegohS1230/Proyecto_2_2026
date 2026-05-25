#include "Player.h"
#include <sstream>

Player::Player(string name, int health, int power, Zone* currentZone, Ability* ability)
{
    this->name = name;
    this->health = health;
    this->power = power;
	this->currentZone = currentZone;
	this->ability = ability;
}

Player::~Player()
{
	delete currentZone;
    delete ability;
}
//gets
Ability* Player::getAbility(){return ability;}
//sets
void Player::setAbility(Ability* ability){
if (ability) delete this->ability;
this->ability = ability;
}
// Simulation behavior
void Player::attack(Hero& target){target.receiveDamage(this->power);}
void Player::moveTo(Zone* newZone){this->currentZone = newZone;}

void Player::receiveDamage(int damage){
    this->health -= damage;
	if (this->health < 0) this->health = 0;
}

bool Player::isAlive(){return this->health > 0;}
string Player::toString(){
    stringstream ss;
      ss << "Player: " << name << "\n";
      ss << "Health: " << health << "\n";
	  ss << "Power: " << power << "\n";
    return ss.str();
}
