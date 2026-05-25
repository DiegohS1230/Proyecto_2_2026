#pragma once
#include "HeroStrategy.h"
#include "ClassExecption.h"
using namespace std;
class TimeStrategy : public HeroStrategy {
public:
    void execute(EnemyHero* enemy, Player* player) override {
		if (!enemy || !player) throw ClassExecption("TimeStrategy received a null pointer."); // Verificación de punteros nulos para evitar errores de acceso a memoria.
		if (!enemy->isAlive()) return; // Si el enemigo no está vivo, no se ejecuta la estrategia.
        int originalPower = enemy->getPower();
		enemy->receiveDamage(75); // El enemigo recibe daño. Si el enemigo muere, se restaura su poder original y se termina la función.
		if (!enemy->isAlive()) { 
            enemy->setPower(originalPower);
            return;
        }

		enemy->setPower(originalPower + 100); // El enemigo aumenta su poder temporalmente para realizar un ataque más fuerte contra el jugador. Después del ataque, se restaura el poder original del enemigo para mantener el equilibrio del juego.
        enemy->attack(*player);
        enemy->setPower(originalPower);
    }
};