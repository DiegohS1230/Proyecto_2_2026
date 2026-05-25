#include <iostream>
#include "SimulationEngine.h"

using namespace std;

int main() {
	SimulationEngine engine; // Creo una instancia del motor de simulación
	engine.start(); // le doy iniciar y como esta ultima esta hecha con punteros inteligentes, se encargará de liberar la memoria automáticamente al finalizar el programa
    return 0;
}