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

//BATALLAS//
void batallaStitchard (int vida, int eleccion, string nombrePersonaje, int danoMin, int danoMax);

//TURNOS//
int Turnos (int vida, int enemigoVida, string nombrePersonaje, string nombreEnemigo, int danoMin, int danoMax, int danoMinEnemigo, int danoMaxEnemigo, int idEnemigo);
void turnoJugador (int &ronda, int vida, int &enemigoVida, string nombrePersonaje, string nombreEnemigo, int danoMin, int danoMax);
void turnoEnemigo(int &ronda, int &vida, string nombrePersonaje, string nombreEnemigo, int enemigoVida, int danoMin, int danoMax, int &contRonda, int idEnemigo);
void pasivasEnemigos(int contRondas, int idEnemigo, int &danoMin, int &danoMax, int &enemigoVida);

//ACCIONES//
int realizarAtaque(int danoMin, int danoMax);


