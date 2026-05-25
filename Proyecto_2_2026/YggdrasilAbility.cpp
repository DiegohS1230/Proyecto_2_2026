#include "YggdrasilAbility.h"



void YggdrasilAbility::use(Zone* target)
{
	if(target)target->heal(20);
	target->setCorruption(target->getCorruption() - 20);
	target->setCivilians(target->getCivilians() + 40);
}

void YggdrasilAbility::use(Hero* target)
{
	if(target && target->getHealth() > 0)
	target->receiveDamage(-20); // Negative damage to heal the hero
	target->setHealth(target->getHealth() + 20);
}
