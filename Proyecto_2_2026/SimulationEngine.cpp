#include "SimulationEngine.h"
#include "SwordStrategy.h"
#include "TimeStrategy.h"
#include "FaithStrategy.h"
#include <sstream>

SimulationEngine::SimulationEngine()
    : logger("output/log.txt", "output/report.txt") {
    turn = 1;
    maxTurns = 5;
    finished = false;
}

void SimulationEngine::initialize() {
    zones.addZone(new Zone("Seoul", 20, 10, 1200));
    zones.addZone(new Zone("Busan", 10, 5, 900));

    player = make_unique<Player>("Return Hero", 1000, 20);
    player->setCurrentZone(zones.findZone("Seoul"));

    swordHero = make_unique<EnemyHero>("Sword Hero", 150, 35);
    timeHero = make_unique<EnemyHero>("Time Hero", 100, 25);
    faithHero = make_unique<EnemyHero>("Faith Hero", 120, 20);

    swordHero->setCurrentZone(zones.findZone("Seoul"));
    timeHero->setCurrentZone(zones.findZone("Busan"));
    faithHero->setCurrentZone(zones.findZone("Seoul"));

    swordHero->setStrategy(new SwordStrategy());
    timeHero->setStrategy(new TimeStrategy());
    faithHero->setStrategy(new FaithStrategy());

    logger.write("Simulation initialized.");
}

void SimulationEngine::start() {
    initialize();

    while (!finished && turn <= maxTurns) {
        processTurn();
        checkDeaths();

        if (checkVictory()) {
            logger.write("Victory: all enemy heroes were defeated.");
            finished = true;
        }
        else if (checkDefeat()) {
            logger.write("Defeat: the player died or the country collapsed.");
            finished = true;
        }

        turn++;
    }

    logger.write("Simulation ended.");
    logger.writeReport("Final result:\n" + player->toString() + "\n" + zones.toString());
}

void SimulationEngine::processTurn() {
    logger.write("\n******** TURN " + to_string(turn) + " ********");

    processEnemiesTurn();

    if (!checkDefeat()) {
        processPlayerTurn();
    }

    showState();
}

void SimulationEngine::processEnemiesTurn() {
    logger.write("\n******** Enemies Turn ********");

    if (swordHero && swordHero->isAlive()) {
        logger.write(swordHero->getName() + " acts.");
        swordHero->act(player.get());
    }

    if (timeHero && timeHero->isAlive()) {
        logger.write(timeHero->getName() + " acts.");
        timeHero->act(player.get());
    }

    if (faithHero && faithHero->isAlive()) {
        logger.write(faithHero->getName() + " acts.");
        faithHero->act(player.get());
    }
}

void SimulationEngine::processPlayerTurn() {
    logger.write("\n******** Player Turn ********");

    if (!player || !player->isAlive()) {
        return;
    }

    Zone* seoul = zones.findZone("Seoul");

    if (seoul) {
        logger.write(player->getName() + " uses Yggdrasil on Seoul.");
        seoul->heal(20);
    }
}

void SimulationEngine::checkDeaths() {
    if (player && !player->isAlive()) {
        logger.write(player->getName() + " has fallen.");
    }

    if (swordHero && !swordHero->isAlive()) {
        logger.write(swordHero->getName() + " has fallen.");
    }

    if (timeHero && !timeHero->isAlive()) {
        logger.write(timeHero->getName() + " has fallen.");
    }

    if (faithHero && !faithHero->isAlive()) {
        logger.write(faithHero->getName() + " has fallen.");
    }
}

bool SimulationEngine::allEnemiesDefeated() {
    return swordHero && timeHero && faithHero &&
        !swordHero->isAlive() &&
        !timeHero->isAlive() &&
        !faithHero->isAlive();
}

bool SimulationEngine::isCountryCollapsed() {
    int collapsedZones = 0;

    Zone* seoul = zones.findZone("Seoul");
    Zone* busan = zones.findZone("Busan");

    if (seoul && seoul->isCollapsed()) {
        collapsedZones++;
    }

    if (busan && busan->isCollapsed()) {
        collapsedZones++;
    }

    return collapsedZones >= 2;
}

bool SimulationEngine::checkVictory() {
    return allEnemiesDefeated();
}

bool SimulationEngine::checkDefeat() {
    if (!player || !player->isAlive()) {
        return true;
    }

    if (isCountryCollapsed()) {
        return true;
    }

    return false;
}

void SimulationEngine::showState() {
    logger.write("\n******** CURRENT STATE ********");

    if (player) {
        logger.write(player->toString());
    }

    if (swordHero) {
        logger.write(swordHero->toString());
    }

    if (timeHero) {
        logger.write(timeHero->toString());
    }

    if (faithHero) {
        logger.write(faithHero->toString());
    }

    logger.write(zones.toString());
}

ListZone* SimulationEngine::getZones() {
    return &zones;
}

Player* SimulationEngine::getPlayer() {
    return player.get();
}