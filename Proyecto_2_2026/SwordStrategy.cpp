#include "SwordStrategy.h"

void SwordStrategy::execute(EnemyHero* enemy, Player* player)
{
	if (!enemy && !player) rethrow_exception(make_exception_ptr(runtime_error("SwordStrategy is not implemented yet.")));
	enemy->attack(*player);
	enemy->getCurrentZone()->damage(100);

}
