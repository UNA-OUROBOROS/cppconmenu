#include <conmenu/menu.hpp>
#include <conmenu/opcion.hpp>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;

menu::menu(std::string titulo) : titulo(titulo) {}

void menu::mostrar(bool submenu) {
	while (true) {
		limpiar();
		if (submenu) {
			cout << std::right << std::setfill('-') << std::setw(49);
			cout << " " + titulo + " <- *\n";
		} else {
			cout << "* -> " << std::left << std::setfill('-') << std::setw(43);
			cout << titulo + " "
			     << "\n";
		}

		for (size_t i = 0; i < opciones.size(); i++) {
			cout << i + 1 << ". ";
			if (dynamic_cast<menu *>(opciones[i])) {
				cout << "=> ";
		}
			cout << opciones[i]->getNombre() << ".\n";
		}
		cout << opciones.size() + 1 << ". ";
		cout << (submenu ? "Regresar" : "Salir");
		cout << ".\n";
		cout << "------------------------------------------------\n";
		int opcion = -1;

		if (cin >> opcion) {
			cin.ignore();
			if ((opcion) > 0 && opcion <= opciones.size() + 1) {
				if (opcion == opciones.size() + 1) {
					return;
				}
				limpiar();
				opciones[opcion - 1]->ejecutar();
			}
		} else {
			cin.clear();
			cin.ignore();
		}
	}
}
void menu::agregarOpcion(opcion *opcion) { opciones.push_back(opcion); }
void menu::agregarSubMenu(menu *s) { agregarOpcion((opcion *)s); }

std::string menu::getTitulo() { return titulo; }
void menu::limpiar() { system("clear"); }

std::string menu::getNombre() { return getTitulo(); }
bool menu::ejecutar() {
	mostrar(true);
	return true;
}