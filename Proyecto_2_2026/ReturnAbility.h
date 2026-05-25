#pragma once
#include "ClassExecption.h"
#include "Ability.h"
class ReturnAbility : public Ability
{
	public:
		ReturnAbility(string name = "Return", int cost = 20) : Ability(name, cost) {} // Constructor que inicializa el nombre y el costo de la habilidad, con valores predeterminados.
		void use(Hero* hero) override;
};

