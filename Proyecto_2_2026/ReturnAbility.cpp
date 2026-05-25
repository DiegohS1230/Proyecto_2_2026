#include "ReturnAbility.h"

void ReturnAbility::use(Hero* hero) {if (hero && hero->isAlive()) hero->setHealth(100);}
