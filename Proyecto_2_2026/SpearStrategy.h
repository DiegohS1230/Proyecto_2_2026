#pragma once
#include "HeroStrategy.h"
#include "ClassExecption.h"
class SpearStrategy
{
	public:
	void execute(EnemyHero* enemy, Player* player) {
		if (!enemy || !player) throw ClassExecption("SpearStrategy received a null pointer.");
		enemy->attack(*player);
		enemy->getCurrentZone()->damage(50);
	}
};

