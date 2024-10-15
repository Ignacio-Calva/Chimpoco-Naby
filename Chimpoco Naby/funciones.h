#pragma once
#include <cstring>
using namespace std;

//MENUS//
void menuPrincipal ();
void mostrarMenu ();
void menuSeleccionPersonajes();

//SWITCH MENU//
void modoAventura(string &nombreJugador);
void modoVersus ();
void godMode();
void estadisticas();
void manual ();

//CARGA DE DATOS//
string cargarNombre();
int seleccionPersonaje();
void inicializarChimpoco(int eleccion, int chimpoco[], string &nombreChimpoco);
void inicializarEnemigo (int i, int enemigo[], string &nombreEnemigo);


//BATALLAS//
void batalla (int chimpoco[], int enemigo[], string &nombreChimpoco, string &nombreEnemigo);

//TURNOS//
void turnoJugador(int &ronda, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo);
void turnoEnemigo (int &ronda, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo);
void pasivasEnemigos(int contRondas, int idEnemigo, int &danoMin, int &danoMax, int &enemigoVida);

//ACCIONES//
int realizarAtaque(int danoMin, int danoMax);
