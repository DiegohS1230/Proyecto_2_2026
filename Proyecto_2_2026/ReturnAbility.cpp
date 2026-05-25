#include "ReturnAbility.h"

void ReturnAbility::use(Hero* hero) { if (hero && hero->isAlive()) hero->setHealth(100); } // El método use de la clase ReturnAbility verifica si el puntero al héroe es válido y si el héroe está vivo.
