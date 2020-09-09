#include <conmenu/submenu.hpp>

submenu::submenu(std::string nombre) : menu(nombre) {}
	std::string submenu::getNombre(){ return menu::getTitulo(); }
	bool submenu::ejecutar(){
		menu::mostrar();
		return true;
	}