#pragma once
#include <iostream>
#include <memory>
#include "ListZone.h"
#include "Player.h"
#include "EnemyHero.h"
#include "Logger.h"
using namespace std;
class SimulationEngine {
private:
    Logger logger;
    ListZone zones;
    unique_ptr<Player> player;
    unique_ptr<EnemyHero> swordHero;
    unique_ptr<EnemyHero> timeHero;
    unique_ptr<EnemyHero> faithHero;
    int turn;
    int maxTurns;
    bool finished;

public:
    SimulationEngine();
    ~SimulationEngine() = default;
    void start();
    void processTurn();
    void processEnemiesTurn();
    void processPlayerTurn();
    bool checkVictory();
    bool checkDefeat();
    void showState();
    ListZone* getZones();
    Player* getPlayer();
    void initialize();
    void checkDeaths();
    bool isCountryCollapsed();
    bool allEnemiesDefeated();
};