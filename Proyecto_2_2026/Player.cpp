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
void Player::attack(Hero& target) { target.receiveDamage(this->power); } // El ataque del jugador inflige dano al objetivo igual a su poder.
void Player::moveTo(Zone* newZone){this->currentZone = newZone;} // El metodo moveTo actualiza la zona actual del jugador asignandole el nuevo puntero a la zona proporcionado como argumento.

void Player::receiveDamage(int damage){
    this->health -= damage; // El metodo receiveDamage reduce la salud del jugador en la cantidad de daño recibida. Si la salud cae por debajo de cero, se ajusta a cero para evitar valores negativos.
	if (this->health < 0) this->health = 0;
}

bool Player::isAlive() { return this->health > 0; } // El método verifica si el jugador sigue vivo comprobando si su salud es mayor que cero.
string Player::toString(){ //muestra la infromacion del jugador
    stringstream ss;
      ss << "Player: " << name << "\n";
      ss << "Health: " << health << "\n";
	  ss << "Power: " << power << "\n";
    return ss.str();
}
