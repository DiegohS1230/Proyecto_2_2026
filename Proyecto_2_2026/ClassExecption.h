#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;
class ClassExecption : public exception //hereda de la clase base exception para crear una excepción personalizada
{
private:
	string mensaje;
public:
	ClassExecption(const string& mensaje) : mensaje(mensaje) {} //constructor que recibe un mensaje de error y lo almacena en la variable miembro mensaje
	const char* what() const noexcept override {
		return mensaje.c_str();//sobrescribe el método what() de la clase base exception para devolver el mensaje de error almacenado en la variable miembro mensaje
	}
};

