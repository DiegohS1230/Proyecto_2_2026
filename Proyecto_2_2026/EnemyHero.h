#pragma once
#include "Hero.h"

class HeroStrategy;
class Player;

class EnemyHero : public Hero {
private:
    HeroStrategy* strategy;
public:
	// Constructor y Destructor
    EnemyHero(string name = "", int health = 100, int power = 20, Zone* currentZone = nullptr);
    ~EnemyHero();
	//meotodos para la estrategia
    HeroStrategy* getStrategy();
    void setStrategy(HeroStrategy* strategy);
    void act(Player* player);
    void attack(Hero& target) override;
    void moveTo(Zone* newZone) override;
    void receiveDamage(int damage) override;
    bool isAlive() override;
    string toString() override;
};