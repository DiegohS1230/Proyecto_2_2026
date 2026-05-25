#pragma once
#include "HeroStrategy.h"
#include <stdexcept>
#include "ClassExecption.h"
using namespace std;

class FaithStrategy : public HeroStrategy {
public:
    void execute(EnemyHero* enemy, Player* player) override {
		if (!enemy || !player) throw ClassExecption("FaithStrategy received a null pointer."); // Validación de punteros nulos
		if (!enemy->isAlive() || !player->isAlive()) return; // Si alguno de los héroes no está vivo, no se ejecuta la estrategia
        enemy->attack(*player); 
		Zone* zone = player->getCurrentZone(); // Obtener la zona actual del jugador para aplicar los efectos del ataque del enemigo
		if (zone) {// Validación de puntero nulo para la zona
			zone->damage(5);// El ataque del enemigo daña la zona
			zone->increaseCorruption(15); // El ataque del enemigo aumenta la corrupción de la zona
			zone->setCivilians(zone->getCivilians() - 30); // El ataque del enemigo reduce el número de civiles en la zona
        }
    }
};