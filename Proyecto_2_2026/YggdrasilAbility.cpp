#include "YggdrasilAbility.h"
#include "YggdrasilAbility.h"

void YggdrasilAbility::use(Zone* target) {
    if (!target) throw ClassExecption("YggdrasilAbility received a null pointer.");
    target->heal(20);
    target->setCorruption(target->getCorruption() - 10);
    target->setCivilians(target->getCivilians() + 100);
}

void YggdrasilAbility::use(Hero* target) {
	if (!target) throw ClassExecption("YggdrasilAbility received a null pointer.");
    target->setHealth(target->getHealth() + 20);
}