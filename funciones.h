#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/// explicacion de las funciones
void cargarCadena(char pal[], int tam);///carga nombre de jugadores

void cargarAleatorio(int v[], int tam, int limite);

void rondas();

void mostrarVector(int v[], int tam);

int sumarVector(int v[], int tam);

int maximoVector(int v[], int tam);

int combinaciones(int v[], int tam);

void cargarVector(int v[], int tam);

void ordenarVector(int v[], int tam );

void cargarPalabras(char mPal[][20], int tam);

void mostrarPalabras(char mPal[2][19], int tam);

int contarNumerosRepetidos(int v[], int numero, int tam);

void menuJuego(char nombres[][20], int puntaje, int contadorRondas, int maximoRondas[], int lanzamiento);

void tirada(int dados[6]);

void menuFinRonda(char vNombres[][20], int contadorRondas, int puntaje);

int calcularPuntaje(int tirada[], int dados[], int puntaje);

void limpiarPantalla();

void dibujarCuadrado(int posx, int posy);

void dibujarDados(int numero, int posx, int posy);




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

void mostrarPalabras(char mPal[2][20], int tam){
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
                puntaje += 100;
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



}

void menuJuego(char nombres[][20], int puntaje, int contadorRondas, int maximoRondas[], int lanzamiento) {
    cout << "TURNO DE ";
    mostrarPalabras(nombres, 1);
    cout << "\tPUNTAJE: " << puntaje << "\tRONDA: " << contadorRondas << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "MAXIMO PUNTAJE DE LA RONDA: " <<  maximoRondas[maximoVector(maximoRondas, 3)] << " PUNTOS" << endl;
    cout << "LANZAMIENTO NUMERO " << lanzamiento << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl;
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

void menuFinRonda(char vNombres[][20], int contadorRondas, int puntaje){
        cout << "RONDA " << contadorRondas << endl;
        cout << "PUNTAJE DE ";
        mostrarPalabras(vNombres, 1);
        cout << ": " << puntaje << " PUNTOS " << endl;
        limpiarPantalla();
}

void menuFinJuego(char vNombres[]){
    cout << "GANADOR ";
}

void limpiarPantalla(){
    system("pause");
    system("cls");
}

void dibujarCuadrado(int posx, int posy){
    rlutil::setColor(rlutil::RED);
    for(int x = posx; x <= posx + 6; x++){
        for(int y = posy; y <= posy + 2; y++){
            rlutil::locate(x, y);
            cout << (char) 219;
        }
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::GREEN);

}

void dibujarDados(int numero, int posx, int posy){
    dibujarCuadrado(posx, posy);

    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::RED);

    rlutil::saveDefaultColor();

    switch(numero){
        case 1:
            rlutil::locate(posx + 3, posy + 1);
            cout << (char) 254;
            break;
        case 2:
            rlutil::locate(posx + 1, posy);
            cout << (char) 220;
            rlutil::locate(posx + 5, posy + 2);
            cout << (char) 223;
            break;
        case 3:
            rlutil::locate(posx + 1, posy);
            cout << (char) 220;
            rlutil::locate(posx + 3, posy + 1);
            cout << (char) 254;
            rlutil::locate(posx + 5, posy + 2);
            cout << (char) 223;
            break;
        case 4:
            rlutil::locate(posx + 1, posy);
            cout << (char) 220;
            rlutil::locate(posx + 5, posy);
            cout << (char) 220;
            rlutil::locate(posx + 5, posy + 2);
            cout << (char) 223;
            rlutil::locate(posx + 1, posy + 2);
            cout << (char) 223;
            break;
        case 5:
            rlutil::locate(posx + 3, posy + 1);
            cout << (char) 254;
            rlutil::locate(posx + 1, posy);
            cout << (char) 220;
            rlutil::locate(posx + 5, posy);
            cout << (char) 220;
            rlutil::locate(posx + 5, posy + 2);
            cout << (char) 223;
            rlutil::locate(posx + 1, posy + 2);
            cout << (char) 223;
            break;
        case 6:
            rlutil::locate(posx + 1, posy);
            cout << (char) 220;
            rlutil::locate(posx + 1, posy + 1);
            cout << (char) 254;
            rlutil::locate(posx + 5, posy);
            cout << (char) 220;
            rlutil::locate(posx + 5, posy + 2);
            cout << (char) 223;
            rlutil::locate(posx + 5, posy + 1);
            cout << (char) 254;
            rlutil::locate(posx + 1, posy + 2);
            cout << (char) 223;
            break;

    }
    rlutil::resetColor();
    rlutil::setBackgroundColor(rlutil::GREEN);

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


#endif // FUNCIONES_H_INCLUDED
