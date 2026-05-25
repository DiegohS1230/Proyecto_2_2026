#pragma once
#include "HeroStrategy.h"
class SpearStrategy
{
	public:
	void execute(EnemyHero* enemy, Player* player) {
		if (!enemy || !player) throw runtime_error("SpearStrategy is not implemented yet.");
		enemy->attack(*player);
		enemy->getCurrentZone()->damage(50);
	}
};

