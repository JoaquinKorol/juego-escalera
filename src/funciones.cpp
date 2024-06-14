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

void cargarCadena(char pal[], int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

void mostrarPalabras(char mPal[][20], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<mPal[i];
    }
}

void cargarNombres(char mNombres[][20], int tam){
    for(int i = 0; i < tam; i++) {
        cout << "Nombre " << i + 1 << ": " << mNombres[i];
        cargarCadena(mNombres[i], 19);
    }
}

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
  }


void tirada(int dados[]){
        cargarAleatorio(dados, 6, 6);
        int x = 7;
        for(int i = 0; i < 6; i++){
            dibujarDados(dados[i], x, 7);
            x += 10;
        }

        cout << endl;


}


void limpiarPantalla(){
    system("pause");
    system("cls");
}



int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}




void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}

int sumarVector(int v[], int tam ){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=v[i];
    }
    return suma;
}

int maximoVector(int v[], int tam){
    int i, posMax=0;
    for(i=1;i<tam;i++){
        if(v[i]>v[posMax]) {
                posMax=i;
        }
    }
    return posMax;
}

int combinaciones(int v[], int tam){
    int iguales = 0;
    int escalera = 0;
    int i;
    for(i = 1; i < tam; i++){
        if(v[i-1] != v[i]){
            iguales = 1;
            break;
        }
    }
    ordenarVector(v, 6);
    for(int j = 1; j < tam; j++){
        if(v[j-1] != v[j]-1){
            escalera = 1;
            break;
        }
    }
    if(escalera == 0){
        return 100;
    }else if(v[0] == 6 && iguales == 0){
        return 0;
    }else if (iguales==0){
        return v[0] * 10;
    }else {
        return sumarVector(v, tam);
    }
}



void cargarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<"INGRESE NUMERO: ";
        cin>>v[i];
    }
}

void ordenarVector(int v[], int tam ){
    int i,j, posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}
