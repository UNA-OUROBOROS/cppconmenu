#pragma once
#include <conmenu/opcion.hpp>

#include <string>
#include <vector>

class submenu;

class menu : public opcion {
	std::vector<opcion *> opciones;
  public:
	menu(std::string titulo);
	void mostrar(bool submenu = false);
	void agregarOpcion(opcion *opcion);
	void agregarSubMenu(menu *s);

  protected:
	static void limpiar();
	bool ejecutar() override;
};
