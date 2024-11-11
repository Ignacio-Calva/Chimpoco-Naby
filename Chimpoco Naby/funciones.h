#pragma once
#include <cstring>
using namespace std;

//MENUS//
void menuPrincipal ();
void mostrarMenu ();
void menuSeleccionPersonajes(bool bgodMod);
void cambioderonda (int i);
void mostrarBarraVida (int chimpoco[]);
void mostrarBarraVidaEnemigo(int enemigo[]);
void mostrarVida (int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo);
void coutpasivas (int rondaEnemigo, int enemigo []);
void coutFinal (string nombreChimpoco, string nombreEnemigo);
void mostrarGanador(string &nombreGanador);

//BIENVENIDAS//
void bienvenidaGodMode();
void bienvenidaAventura();
void bienvenidaVersus();

//SWITCH MENU//
void modoAventura();
void modoVersus ();
void godMode();
void estadisticas();
void manual ();

//CARGA DE DATOS//
string cargarNombre();
int seleccionPersonaje(bool bgodMode);
void inicializarChimpoco(int eleccion, int chimpoco[], string &nombreChimpoco, bool godMode);
void inicializarEnemigo (int i, int enemigo[], string &nombreEnemigo);
void inicializarPersonajes (int turno, int chimpocoUno[], int chimpocoDos[], string &nombreChimpocoUno, string &nombreChimpocoDos, string nombreJugadorUno, string nombreJugadorDos);

//BATALLAS//
void batalla (int chimpoco[], int enemigo[], string &nombreChimpoco, string &nombreEnemigo, bool godMode);
void batallaVersus (int chimpocoUno[], int chimpocoDos[], string nombreChimpocoUno, string nombreChimpocoDos, string nombreJugadorUno, string nombreJugadorDos);
int batallaGodMode (int chimpoco[], int enemigo[], string &nombreChimpoco, string &nombreEnemigo, bool bGodMode);
//TURNOS//
int turnoJugador(int &rondaChimpoco, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo, bool &tiomickey, int &rondaEnemigo, bool bGodMode);
int turnoEnemigo(int &rondaEnemigo, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo, bool &tiomickey,bool bGodMode);
void turnoJugadorVersus(int &rondaChimpoco, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo, bool &tiomickey, int &rondaEnemigo);

//ACCIONES//
int realizarAtaque(int chimpoco[], int danoMin, int danoMax);
int dados (string nombreJugadorUno, string nombreJugadorDos);
int tirarDado();

//PASIVAS CHIMPOCO//
void pasivasChimpoco (int chimpoco[] , int danoRealizado, int enemigo[] , string nombreEnemigo);
void pasivasrockito (int chimpoco[], int danoEnemigo);
void pasivaspicante (int chimpoco[], int danoRealizado);
void pasivafreddy (int chimpoco[], int enemigo[], string nombreEnemigo);
void pasivarayin (int chimpoco [], int enemigo[], string nombreEnemigo);

//PASIVAS ENEMIGOS//
void pasivaStitchard(int enemigo[], int rondaEnemigo);
void pasivaFurbyZhor (int rondaEnemigo, int enemigo [], int chimpoco[], string nombreChimpoco);
void pasivaHelloCathy(int rondaChimpoco, int &danoRecibido, int enemigo[]);
void pasivaBabyYorda (int &rondaEnemigo, int chimpoco[], int enemigo [], string nombreChimpoco, string nombreEnemigo);
void pasivaTioMickey(int &danoRealizado, int enemigo[], int chimpoco[], int &rondaEnemigo, bool &tiomickey);

//MANUAL//
void manual ();
void menumanual ();
void mostrarOpcion (int opcion);

//POCIONES Y BOOST//
int usaritem (int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo); // LA USO COMO INT, PERO PODRIA USARLA COMO BOOL, YA QUE RETORNA UNA BANDER
int menuitems(int chimpocos[], int enemigo[], string nombreChimpoco, string nombreEnemigo);
void boostataque (int chimpoco[]);
void boostdefensa (int chimpoco[], int enemigo[]);
void pocionvida (int chimpoco[]);
