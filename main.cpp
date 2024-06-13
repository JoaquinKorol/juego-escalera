#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<ctime>
#include "rlutil.h"

using namespace std;

#include "FUNCIONES.h"

void showItem(const char* text, int posx, int posy, bool selected) {

	if (selected) {
		rlutil::setBackgroundColor(rlutil::BLUE);
		rlutil::locate(posx - 3, posy);
		std::cout <<" " <<(char)175 << " " << text << " " << (char)174 <<" " <<std::endl;

	}
	else {
		rlutil::setBackgroundColor(rlutil::BLACK);
		rlutil::locate(posx-3, posy);
		std::cout << "   " << text << "   "<< std::endl;
	}

	rlutil::setBackgroundColor(rlutil::BLACK);
}

enum Opciones {
	Opcion1=0,
	Opcion2=1,
	Opcion3=2,
	Salir=3
};


int main() {
	int op = 1;
	int y = 0;
	rlutil::hidecursor();

	do {

		rlutil::setBackgroundColor(rlutil::BLACK);
		rlutil::setColor(rlutil::WHITE);
		rlutil::hidecursor();

		showItem(" MODO UN JUGADOR ", 30, 10, y == Opcion1);
		showItem(" MODO DOS JUGADORES ", 30, 11, y == Opcion2);
		showItem(" MODO SIMULADO ", 30, 12, y == Opcion3);
		showItem(" SALIR   ", 30, 13, y == Salir);

		switch (rlutil::getkey())
		{
		case 14: // UP
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y--;
			if (y < 0) {
				y = 0;
			}
			break;
		case 15: // DOWN
			rlutil::locate(28, 10 + y);
			std::cout << " " << std::endl;
			y++;
			if (y > 3) {
				y = 3;
			}
			break;
		case 1: modoUnJugador();
            break;
			switch (y)
			{
			case 3:
				op = 0;
			default:
				break;
			}


			break;
		default:
			break;
		}

		//¿std::cout << "Key: " << key;

		//rlutil::anykey();
		//op = 1;

	} while (op != 0);

	return 0;
}

