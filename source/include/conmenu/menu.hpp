#pragma once
#include <vector>
#include <string>

class opcion;
class submenu;

class menu {
	std::vector<opcion *> opciones;
	std::string titulo;
  public:
	menu(std::string titulo);
	void mostrar(bool alterno = false);
	void agregarOpcion(opcion *opcion);
	void agregarSubMenu(submenu *s);
  protected:
	std::string getTitulo();
	static void limpiar();
};
