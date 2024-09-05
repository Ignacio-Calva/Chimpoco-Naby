#pragma once
#include <cstring>
using namespace std;

//
void menuPrincipal ();
void mostrarMenu ();

//SWITCH MENU//
void modoAventura(string &nombreJugador);
void modoVersus ();
void godMode();
void estadisticas();
void manual ();

//CARGA DE DATOS
string cargarNombre();
int seleccionPersonaje();
