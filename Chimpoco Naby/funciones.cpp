#include <iostream>
#include <cstring>
#include <time.h>
#include <conio.h>
#include "funciones.h"
using namespace std;

//MENU PRINCIPAL
void menuPrincipal (){
    srand(time(NULL));
    string nombreJugador;
    int opcion = 1;
    while (opcion !=0){
        mostrarMenu();
        cin>>opcion;
        switch (opcion) {
        case 1:
            modoAventura (nombreJugador);
            break;
//        case 2:
//            modoVersus ();
//            break;
//        case 3:
//            godMode ();
//            break;
//        case 4:
//            estadisticas ();
//            break;
//        case 5:
//            manual ();
//            break;
        case 0:
            cout<<"Saliedo del programa..."<<endl;
            break;
        default:
            cout<<"Ingrese una opcion correcta."<<endl;
            system ("pause");
            break;

        }
    }
}

//MOSTRAR MENU
void mostrarMenu (){
    system("cls");
    cout<<"================================================="<<endl;
    cout<<"                 CHIMPOCO FIGHT                  "<<endl;
    cout<<"================================================="<<endl;
    cout<<"1. Aventura                                      "<<endl;
    cout<<"2. Versus                                        "<<endl;
    cout<<"3. God Mode                                      "<<endl;
    cout<<"4. Estadisticas                                  "<<endl;
    cout<<"5. Manual                                        "<<endl;
    cout<<"0. Salir                                         "<<endl;
    cout<<"================================================="<<endl;
    cout<<"Ingrese la opcion deseada: ";
}

void modoAventura(string &nombreJugador) {
    nombreJugador = cargarNombre();
    int eleccion = seleccionPersonaje();
    int vida;
    switch (eleccion) {
        case 1:
            vida = 1200;
            break;
        case 2 :
            vida = 500;
            break;
        case 3:
            vida = 700;
            break;
        case 4:
            vida = 600;
            break;
    }

    batallaStitchard(vida, eleccion);

  }


void modoVersus (){

}

void godMode() {

}

void estadisticas() {

}

void manual () {

}

string cargarNombre(){
    string nombreIngresado;
    system("cls");
    cout << "Por favor, ingrese el nombre del jugador: ";
    cin >> nombreIngresado;
    system("cls");
    return nombreIngresado;
}

int seleccionPersonaje(){
    menuSeleccionPersonajes();
    int eleccion=0;
    while (eleccion == 0){
        cout << "Ingrese el personaje deseado: ";
        cin >> eleccion;

        switch (eleccion){
        case 1:
            cout << "El personaje seleccionado es ROCKITO" << endl;
            break;
        case 2:
            cout << "El personaje seleccionado es PICANTE" << endl;
            break;
        case 3:
            cout << "El personaje seleccionado es FREDDY" << endl;
            break;
        case 4:
            cout << "El personaje seleccionado es RAYIN" << endl;
            break;
        default:
            system("cls");
            cout << "Opcion invalida. Elija un numero valido." << endl;
            menuSeleccionPersonajes();
            eleccion = 0;
            break;
        }
    }
    system("pause");
    return eleccion;
}

void menuSeleccionPersonajes(){
    cout << "========================================" << endl;
    cout << "           LISTA DE PERSONAJES          " << endl;
    cout << "========================================" << endl;
    cout << "(1) ROCKITO" << endl;
    cout << "(2) PICANTE" << endl;
    cout << "(3) FREDDY" << endl;
    cout << "(4) RAYIN" << endl;
    cout << "========================================" << endl;
}

void batallaStitchard (int vida, int eleccion) {
    int personajeVida = vida;
    int personaje = eleccion;
    int enemigoVida = 150;
    int danoMin, danoMax;
    string nombrePersonaje;

    switch (personaje) {
    case 1:
        nombrePersonaje = "ROCKITO";
        danoMin = 40;
        danoMax = 50;
        break;
    case 2:
        nombrePersonaje = "PICANTE";
        danoMin = 55;
        danoMax = 65;
        break;
    case 3:
        nombrePersonaje = "FREDDY";
        danoMin = 35;
        danoMax = 55;
        break;
    case 4:
        nombrePersonaje = "RAYIN";
        danoMin = 15;
        danoMax = 85;
        break;
    }

    while (vida > 0 && enemigoVida > 0) {
        system("cls");
        cout << "========================================" << endl;
        cout << "         " << nombrePersonaje << " vs STITCHARD    " << endl;
        cout << "========================================" << endl;
        cout << nombrePersonaje << " >> Vida: " << personajeVida << endl;
        cout << "STITCHARD >> Vida: " << enemigoVida << endl;
        cout << "========================================" << endl;
        cout << "1. Atacar " << endl;
        cout << "2. Usar item " << endl;
        cout << "Elige tu accion: ";
        system("pause");
    }
}


int realizarAtaque(int danoMin, int danoMax){
    int danoRealizado, diferenciaDano;
    diferenciaDano = danoMax - danoMin + 1;
    danoRealizado = danoMin + (rand() % diferenciaDano);
    return danoRealizado;
}

