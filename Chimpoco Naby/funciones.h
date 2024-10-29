#pragma once
#include <cstring>
using namespace std;

//MENUS//
void menuPrincipal ();
void mostrarMenu ();
void menuSeleccionPersonajes();
void cambioderonda (int i);
void mostrarBarraVida (int chimpoco[]);
void mostrarBarraVidaEnemigo(int enemigo[]);

//SWITCH MENU//
void modoAventura();
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
void turnoJugador(int &ronda, int &contRonda, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo);
void turnoEnemigo (int &ronda, int &contRonda, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo);

//ACCIONES//
int realizarAtaque(int chimpoco[], int danoMin, int danoMax);

//PASIVAS CHIMPOCO//
void pasivasrockito (int chimpoco[], int danoEnemigo);
void pasivaspicante (int chimpoco[], int danoRealizado);
void pasivafreddy (int chimpoco[], int enemigo[], string nombreEnemigo);
void pasivarayin (int chimpoco [], int enemigo[], string nombreEnemigo);

//PASIVAS ENEMIGOS//
void pasivaStitchard(int enemigo[], int turno);
void pasivaFurbyZhor(int turno, int chimpoco[], string nombreChimpoco);
void pasivaHelloCathy(int turno, int &danoRecibido);

//MANUAL//
void manual ();
void menumanual ();
void mostrarOpcion (int opcion);

//POCIONES Y BOOST//
int usaritem (int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo, int contRonda); // LA USO COMO INT, PERO PODRIA USARLA COMO BOOL, YA QUE RETORNA UNA BANDER
int menuitems(int chimpocos[], int enemigo[], string nombreChimpoco, string nombreEnemigo);
void boostataque (int chimpoco[]);
void boostdefensa (int chimpoco[], int enemigo[], int contRonda);
void pocionvida (int chimpoco[]);
