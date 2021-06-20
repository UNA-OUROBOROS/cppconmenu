#include <conmenu/menu.hpp>
#include <conmenu/opcion.hpp>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;

menu::menu(std::string nombre) : opcion(nombre) {}

void menu::mostrar(bool submenu) {
	while (true) {
		limpiar();
		if (submenu) {
			cout << std::right << std::setfill('-') << std::setw(49);
			cout << " " + getNombre() + " <- *\n";
		} else {
			cout << "* -> " << std::left << std::setfill('-') << std::setw(43);
			cout << getNombre() + " "
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
				opciones[static_cast<size_t>(opcion) - 1]->ejecutar();
			}
		} else {
			cin.clear();
			cin.ignore();
		}
	}
}
void menu::agregarOpcion(opcion *opcion) { opciones.push_back(opcion); }
void menu::agregarSubMenu(menu *s) { agregarOpcion((opcion *)s); }

void menu::limpiar() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

bool menu::ejecutar() {
	mostrar(true);
	return true;
}

menu::~menu() {
	for (auto *ptr : opciones) {
		delete ptr;
	}
}

opcion::~opcion() = default;
