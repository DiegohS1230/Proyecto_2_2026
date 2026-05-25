#pragma once
#include "HeroStrategy.h"
#include "EnemyHero.h"
#include "Player.h"
#include "ClassExecption.h"
class SwordStrategy : public HeroStrategy {
public:
	void execute(EnemyHero* enemy, Player* player) override; // Implementación de la función pura virtual heredada de HeroStrategy, que define el comportamiento específico de esta estrategia.
};
