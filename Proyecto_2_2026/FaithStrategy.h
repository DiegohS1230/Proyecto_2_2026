#pragma once
#include "HeroStrategy.h"
#include <stdexcept>
using namespace std;

class FaithStrategy : public HeroStrategy {
public:
    void execute(EnemyHero* enemy, Player* player) override {
        if (!enemy || !player) throw runtime_error("FaithStrategy received a null pointer.");
        if (!enemy->isAlive() || !player->isAlive()) return;
        enemy->attack(*player);
        Zone* zone = player->getCurrentZone();
        if (zone) {
            zone->damage(5);
            zone->increaseCorruption(15);
            zone->setCivilians(zone->getCivilians() - 30);
        }
    }
};