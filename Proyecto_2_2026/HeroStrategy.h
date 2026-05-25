#pragma once
#include "EnemyHero.h"
#include "Player.h"
class HeroStrategy{
	public:
		virtual ~HeroStrategy() = default;
		virtual void execute(EnemyHero* enemy, Player* player) = 0; //Es la función pura virtual que cada estrategia concreta debe implementar para definir su comportamiento específico en el juego. Recibe un puntero al enemigo que ejecuta la estrategia y un puntero al jugador como objetivo de la acción.
};

