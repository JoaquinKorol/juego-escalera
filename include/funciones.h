#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/// explicacion de las funciones
void cargarCadena(char pal[], int tam);///carga nombre de jugadores

void cargarAleatorio(int v[], int tam, int limite);

void cargarNombres(char mNombres[][20], int tam);

void rondas();

void mostrarVector(int v[], int tam);

int sumarVector(int v[], int tam);

int maximoVector(int v[], int tam);

int combinaciones(int v[], int tam);

void cargarVector(int v[], int tam);

void ordenarVector(int v[], int tam );

void cargarPalabras(char mPal[][20], int tam);

void mostrarPalabras(char mPal[2][20], int tam);

int contarNumerosRepetidos(int v[], int numero, int tam);

void tirada(int dados[6]);

int calcularPuntaje(int tirada[], int dados[], int puntaje);

void limpiarPantalla();



#endif // FUNCIONES_H_INCLUDED
