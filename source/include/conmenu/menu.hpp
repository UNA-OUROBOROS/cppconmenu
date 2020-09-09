#pragma once
#include <conmenu/opcion.hpp>

#include <string>
#include <vector>

class submenu;

class menu : protected opcion {
	std::vector<opcion *> opciones;
	std::string titulo;

  public:
	menu(std::string titulo);
	void mostrar(bool submenu = false);
	void agregarOpcion(opcion *opcion);
	void agregarSubMenu(menu *s);

  protected:
	std::string getTitulo();
	static void limpiar();

	std::string getNombre() override;
	bool ejecutar() override;
};
