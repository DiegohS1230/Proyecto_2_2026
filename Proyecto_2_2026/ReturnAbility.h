#pragma once
#include "Ability.h"
class ReturnAbility : public Ability
{
	public:
		ReturnAbility(string name = "Return", int cost = 20) : Ability(name, cost) {}
		void use(Hero* hero) override;
};

