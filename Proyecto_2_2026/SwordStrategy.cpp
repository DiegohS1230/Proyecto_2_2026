#include "SwordStrategy.h"
void SwordStrategy::execute(EnemyHero* enemy, Player* player) {
    if (!enemy || !player)throw ClassExecption("SwordStrategy received a null pointer.");
    Zone* zone = enemy->getCurrentZone();
    if (zone)zone->damage(enemy->getPower());
    enemy->attack(*player);
}