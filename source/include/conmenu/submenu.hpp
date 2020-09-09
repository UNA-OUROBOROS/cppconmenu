#pragma once
#include <conmenu/opcion.hpp>
#include <conmenu/menu.hpp>

class submenu : public opcion, public menu {
  public:
	submenu(std::string nombre);
	std::string getNombre() override;
	bool ejecutar() override;
};