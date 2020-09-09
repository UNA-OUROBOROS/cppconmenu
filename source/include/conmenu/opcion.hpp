#pragma once
#include <string>

class opcion {
  public:
	virtual std::string getNombre() = 0;
	virtual bool ejecutar() = 0;
};