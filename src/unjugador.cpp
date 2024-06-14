#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<ctime>

#include "dados.h"
#include "FUNCIONES.h"
#include "menus.h"
#include "unjugador.h"
#include "rlutil.h"

using namespace std;

void modoUnJugador(){
    rlutil::setBackgroundColor(rlutil::GREEN);
    int puntaje = 0, contadorRondas = 0, lanzamiento;
    int vDados[6];
    system("cls");
    char nombres[2][20];
    cargarNombres(nombres, 1);
    limpiarPantalla();
    while(puntaje < 100){
        int maximoRondas[3] = {0};
        contadorRondas++;
        for (int i=0; i<3; i++){
            lanzamiento = i + 1;
            menuJuego(nombres, puntaje, contadorRondas, maximoRondas, lanzamiento);
            cout << "\t";
            tirada(vDados);
            maximoRondas[i] = combinaciones(vDados, 6);
            cout << endl << "\t" << "\t";
            if(maximoRondas[i] == 0){
                cout << "SEXTETO DE 6!  " << endl;
                puntaje = 0;
            }else if(maximoRondas[i] == 100){
                cout << "ESCALERA! !GANASTE EL JUEGO!  ";
                break;
            }else if(contarNumerosRepetidos(vDados, vDados[0], 6) == 6){
                cout << "SEXTETO DE " << vDados[0] << "!  ";
            }else {
                cout << "SUMA DE DADOS! ";
            }
            cout << "PUNTAJE " << maximoRondas[i] << endl;
            cout << endl;
            limpiarPantalla();
        }
        puntaje += maximoRondas[maximoVector(maximoRondas, 3)];
        menuFinRonda(nombres, contadorRondas, puntaje);
        }
        menuFinJuego(nombres, puntaje, contadorRondas);
}


