#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;
class ClassExecption : public exception
{
private:
	string mensaje;
public:
	ClassExecption(const string& mensaje) : mensaje(mensaje) {}
	const char* what() const noexcept override {
		return mensaje.c_str();
	}
};

