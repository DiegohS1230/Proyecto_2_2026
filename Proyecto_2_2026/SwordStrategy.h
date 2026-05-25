#pragma once
#include "HeroStrategy.h"
#include "EnemyHero.h"
#include "Player.h"
class SwordStrategy : public HeroStrategy {
public:
    void execute(EnemyHero* enemy, Player* player) override;
};
