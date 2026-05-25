#pragma once
#include "Ability.h"
#include "ClassExecption.h"
class YggdrasilAbility : public Ability
{
	public:
		YggdrasilAbility(string name = "Yggdrasil's Blessing", int cost = 30) : Ability(name, cost) {}
		void use(Zone* target) override;
		void use(Hero* target) override;
};
