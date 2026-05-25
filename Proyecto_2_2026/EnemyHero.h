#pragma once
#include "Hero.h"

class HeroStrategy;
class Player;

class EnemyHero : public Hero {
private:
    HeroStrategy* strategy;

public:
    HeroStrategy* getStrategy();
    void setStrategy(HeroStrategy* strategy);
    void act(Player* player);
    EnemyHero(string name = "", int health = 100, int power = 20, Zone* currentZone = nullptr);
    ~EnemyHero();
    void attack(Hero& target) override;
    void moveTo(Zone* newZone) override;
    void receiveDamage(int damage) override;
    bool isAlive() override;
    string toString() override;
};