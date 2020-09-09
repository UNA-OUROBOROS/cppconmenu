#include <conmenu/menu.hpp>
#include <iostream>

using std::cin;
using std::cout;

class opcionDummy : public opcion {
	std::string nombre;

  public:
	opcionDummy(std::string nombre) : nombre(nombre) {}
	std::string getNombre() override { return nombre; }
	bool ejecutar() override {
		cout << "hola, me llamo: \"" << nombre << "\".\n";
		cin.ignore();
		return true;
	}
};

int main(int, char **) {
	menu principal("menu principal");
	menu sub("sub menu");
	sub.agregarOpcion(new opcionDummy("opcion a"));
	sub.agregarOpcion(new opcionDummy("opcion b"));
	sub.agregarOpcion(new opcionDummy("opcion c"));
	principal.agregarOpcion(new opcionDummy("opcion principal"));
	principal.agregarSubMenu(&sub);
	principal.mostrar();
}
