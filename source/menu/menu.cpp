#include <conmenu/menu.hpp>
#include <conmenu/opcion.hpp>
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;

menu::menu(std::string titulo) : titulo(titulo) {}

void menu::mostrar(bool alterno) {
		while (true) {
			limpiar();
			if(alterno){
				cout << std::right << std::setfill('-') << std::setw(49);
				cout << " " + titulo + " <- *\n";
			}
			else{
				cout << "* -> " << std::left << std::setfill('-') << std::setw(43);
				cout << titulo + " " << "\n";
			}
			
			for (size_t i = 0; i < opciones.size(); i++) {
				cout << i + 1 << ". " << opciones[i]->getNombre() << ".\n";
			}
			cout << opciones.size() + 1 << ". Salir.\n";
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
void menu::agregarSubMenu(submenu *s) { agregarOpcion((opcion *)s); }

std::string menu::getTitulo() { return titulo; }
void menu::limpiar() { system("clear"); }