#pragma once
#include "EnemyHero.h"
#include "Player.h"
class HeroStrategy{
	public:
		virtual ~HeroStrategy() = default;
		virtual void execute(EnemyHero* enemy, Player* player) = 0;
};

