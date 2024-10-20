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
void asignarEstadisticas(int eleccion, int &vida, string &nombrePersonaje, int &danoMin, int &danoMax);

//BATALLAS//
void batallaStitchard (int vida, int eleccion, string nombrePersonaje, int danoMin, int danoMax, int &idEnemigo, int &cargasBoostAtaque, int &cargasBoostDefensa, int &cargasPocionVida);

//TURNOS//
int Turnos (int vida, int enemigoVida, string nombrePersonaje, string nombreEnemigo, int danoMin, int danoMax, int danoMinEnemigo, int danoMaxEnemigo, int idEnemigo,  int &cargasBoostAtaque, int &cargasBoostDefensa, int &cargasPocionVida);
void turnoJugador (int &ronda, int vida, int &enemigoVida, string nombrePersonaje, string nombreEnemigo, int danoMin, int danoMax, int &cargasBoostAtaque, int &cargasBoostDefensa, int &cargasPocionVida);
void turnoEnemigo(int &ronda, int &vida, string nombrePersonaje, string nombreEnemigo, int enemigoVida, int danoMin, int danoMax, int &contRonda, int idEnemigo);

//ACCIONES//
int realizarAtaque(int danoMin, int danoMax);
void elegirPociones(int &cargasBoostAtaque, int &cargasBoostDefensa, int &cargasPocionVida);
void pocionAtaque(int &cargasBoostAtaque);
//PASIVAS ENEMIGOS//
void pasivasEnemigos(int contRondas, int idEnemigo, int &danoMin, int &danoMax, int &enemigoVida);
void pasivaStitchard (int contRondas, int idEnemigo, int &danoMin, int &danoMax, int &enemigoVida) ;
