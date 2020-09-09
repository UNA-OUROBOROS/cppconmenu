#pragma once
#include <string>

class opcion {
	std::string nombre;

  public:
	opcion(std::string nombre) : nombre(nombre) {}
	virtual std::string getNombre() { return nombre; };
	virtual bool ejecutar() = 0;
	virtual ~opcion() = 0;
};