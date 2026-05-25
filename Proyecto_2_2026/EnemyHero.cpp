#include "EnemyHero.h"
#include "HeroStrategy.h"
#include "Player.h"
#include <sstream>

HeroStrategy* EnemyHero::getStrategy()
{
	return strategy;
}

void EnemyHero::setStrategy(HeroStrategy* strategy) {
	if (this->strategy) delete this->strategy; // Si ya hay una estrategia asignada, se elimina para evitar fugas de memoria.
	this->strategy = strategy;
}

void EnemyHero::act(Player* player) {
	if (strategy) strategy->execute(this, player); // Si hay una estrategia asignada, se ejecuta pasando el enemigo actual y el jugador como argumentos. Esto permite que el enemigo realice acciones específicas basadas en la estrategia definida.
}

EnemyHero::EnemyHero(string name, int health, int power, Zone* currentZone): Hero(name, health, power, currentZone) {
	this->strategy = nullptr; // Inicializa el puntero a la estrategia como nullptr, lo que indica que inicialmente no hay una estrategia asignada al enemigo. La estrategia se puede asignar posteriormente utilizando el método setStrategy.
}

EnemyHero::~EnemyHero()	
{
	delete strategy;
}

void EnemyHero::attack(Hero& target)
{
	target.receiveDamage(this->power); // El método attack toma una referencia a un objeto Hero como objetivo y le inflige daño igual al poder del enemigo.
}

void EnemyHero::moveTo(Zone* newZone)
{
	this->currentZone = newZone; // El método moveTo actualiza la zona actual del enemigo asignándole el nuevo puntero a la zona proporcionado como argumento.
}

void EnemyHero::receiveDamage(int damage)
{
	this->health -= damage; // El método receiveDamage reduce la salud del enemigo en la cantidad de daño recibida. Si la salud cae por debajo de cero, se ajusta a cero para evitar valores negativos.
	if (this->health < 0) this->health = 0;
}

bool EnemyHero::isAlive()
{
	if (health > 0) return true; // El método isAlive verifica la salud del enemigo.
    return false;
}

string EnemyHero::toString() //muestra la informacion del enemigo.
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
