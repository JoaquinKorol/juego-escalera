#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<ctime>

#include "dados.h"
#include "funciones.h"
#include "menus.h"
#include "unjugador.h"
#include "rlutil.h"

using namespace std;

void menuJuego(char nombres[][20], int puntaje, int contadorRondas, int maximoRondas[], int lanzamiento) {
    cout << "TURNO DE ";
    mostrarPalabras(nombres, 1);
    cout << "\t|\tPUNTAJE: " << puntaje << "\t|\tRONDA: " << contadorRondas << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: " <<  maximoRondas[maximoVector(maximoRondas, 3)] << " PUNTOS" << endl;
    cout << "LANZAMIENTO NUMERO " << lanzamiento << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << endl;
}

void menuFinRonda(char vNombres[][20], int contadorRondas, int puntaje){
        cout << "RONDA " << contadorRondas << endl;
        cout << "PUNTAJE DE ";
        mostrarPalabras(vNombres, 1);
        cout << ": " << puntaje << " PUNTOS " << endl;
        limpiarPantalla();
}

void menuFinJuego(char vNombres[][20], int puntaje, int rondas){
    cout << "GANADOR: ";
    mostrarPalabras(vNombres, 1);
    cout << endl << "EN " << rondas << " RONDAS " << endl;
    cout << "PUNTAJE: " << puntaje << endl;
    limpiarPantalla();
}
