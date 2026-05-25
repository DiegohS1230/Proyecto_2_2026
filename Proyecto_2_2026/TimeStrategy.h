#pragma once
#include "HeroStrategy.h"
#include <stdexcept>
using namespace std;
class TimeStrategy : public HeroStrategy {
public:
    void execute(EnemyHero* enemy, Player* player) override {
        if (!enemy|| !player) throw runtime_error("TimeStrategy received a null pointer.");
        if (!enemy->isAlive()) return;
        int originalPower = enemy->getPower();
        enemy->receiveDamage(75);
        if (!enemy->isAlive()) {
            enemy->setPower(originalPower);
            return;
        }

        enemy->setPower(originalPower + 100);
        enemy->attack(*player);
        enemy->setPower(originalPower);
    }
};