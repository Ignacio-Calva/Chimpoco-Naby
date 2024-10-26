#include <iostream>
#include <cstring>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"
using namespace std;

/// CAMBIAR DE COLOR
void colorsito (int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

/// MENU PRINCIPAL
void menuPrincipal (){
    srand(time(NULL));
    int opcion = 1;
    while (opcion !=0){
        mostrarMenu();
        cin>>opcion;
        switch (opcion) {
        case 1:
            modoAventura ();
            break;
        case 2: ///FALTA
            modoVersus ();
            break;
        case 3: ///FALTA
            godMode ();
            break;
        case 4: ///FALTA
            estadisticas ();
            break;
        case 5:
              manual ();
              break;
        case 0:
            colorsito (4);
            cout<<"Saliendo del programa..."<<endl;
            colorsito (7);
            break;
        default:
            colorsito (4);
            cout<<"Ingrese una opcion correcta."<<endl;
            colorsito (7);
            system ("pause");
            break;

        }
    }
}

//MOSTRAR MENU
void mostrarMenu (){
    system("cls");
    colorsito (5);
    cout<<"================================================="<<endl;
    colorsito (10);
    cout<<"                 CHIMPOCO FIGHT                  "<<endl;
    colorsito (5);
    cout<<"================================================="<<endl;
    colorsito (10);
    cout<<"1. Aventura                                      "<<endl;
    cout<<"2. Versus                                        "<<endl;
    cout<<"3. God Mode                                      "<<endl;
    cout<<"4. Estadisticas                                  "<<endl;
    cout<<"5. Manual                                        "<<endl;
    cout<<"0. Salir                                         "<<endl;
    colorsito (5);
    cout<<"================================================="<<endl;
    colorsito (10);
    cout<<"Ingrese la opcion deseada: ";
}

//CARGAR NOMBRE
string cargarNombre(){
    string nombreIngresado;
    system("cls");
    cout << "Por favor, ingrese el nombre del jugador: ";
    cin >> nombreIngresado;
    system("cls");
    return nombreIngresado;
}

//SELECCION PERSONAJE
int seleccionPersonaje(){
    menuSeleccionPersonajes();
    int eleccion = 0;
    while (eleccion == 0){
        cin >> eleccion;
        switch (eleccion){
        case 1:
            colorsito (6);
            cout << "El personaje seleccionado es ROCKITO" << endl;
            colorsito (7);
            break;
        case 2:
            colorsito (4);
            cout << "El personaje seleccionado es PICANTE" << endl;
            colorsito (7);
            break;
        case 3:
            colorsito (9);
            cout << "El personaje seleccionado es FREDDY" << endl;
            colorsito (7);
            break;
        case 4:
            colorsito (14);
            cout << "El personaje seleccionado es RAYIN" << endl;
            colorsito (7);
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

//MENU SELECCION PERSONAJE
void menuSeleccionPersonajes(){
    system("cls");
    colorsito (5);
    cout << "========================================" << endl;
    colorsito (10);
    cout << "           LISTA DE PERSONAJES          " << endl;
    colorsito (5);
    cout << "========================================" << endl;
    colorsito (6);
    cout << "(1) ROCKITO" << endl;
    colorsito (4);
    cout << "(2) PICANTE" << endl;
    colorsito (9);
    cout << "(3) FREDDY" << endl;
    colorsito (14);
    cout << "(4) RAYIN" << endl;
    colorsito (5);
    cout << "========================================" << endl;
    colorsito (10);
    cout << "Ingrese el personaje deseado: ";
}

//MODO AVENTURA
void modoAventura (){
    int chimpoco [10], enemigo [5];
    string nombreChimpoco;
    string nombreEnemigo;
    int eleccion = seleccionPersonaje();
    for (int i = 1 ; i < 6 ; i++ ){
        inicializarChimpoco (eleccion, chimpoco, nombreChimpoco);
        inicializarEnemigo (i, enemigo, nombreEnemigo);
        batalla (chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
        cambioderonda(i);
    }

}

// COUTS DE CAMBIO DE RONDA
void cambioderonda(int i){
    system("cls");
    if (i<6){
    switch (i){
        case 1 :
            colorsito(10); // VERDE
            cout << "***************************************" << endl;
            cout << "*                                     *" << endl;
            cout << "*         !Cambiaste de Ronda!        *" << endl;
            cout << "*         Tu proximo rival es:        *" << endl;
            cout << "*              FurbyZhor              *" << endl;
            cout << "*                                     *" << endl;
            cout << "***************************************" << endl;
            system("pause");
            break;
        case 2 :
            colorsito(10); // VERDE
            cout << "***************************************" << endl;
            cout << "*                                     *" << endl;
            cout << "*         !Cambiaste de Ronda!        *" << endl;
            cout << "*         Tu proximo rival es:        *" << endl;
            cout << "*              HelloCathy             *" << endl;
            cout << "*                                     *" << endl;
            cout << "***************************************" << endl;
            system("pause");
            break;
        case 3 :
            colorsito(10); // VERDE
            cout << "***************************************" << endl;
            cout << "*                                     *" << endl;
            cout << "*         !Cambiaste de Ronda!        *" << endl;
            cout << "*         Tu proximo rival es:        *" << endl;
            cout << "*              BabyYorda              *" << endl;
            cout << "*                                     *" << endl;
            cout << "***************************************" << endl;
            system("pause");
            break;
        case 4 :
            colorsito(10); // VERDE
            cout << "***************************************" << endl;
            cout << "*                                     *" << endl;
            cout << "*         !Cambiaste de Ronda!        *" << endl;
            cout << "*         Tu proximo rival es:        *" << endl;
            cout << "*              TioMickey              *" << endl;
            cout << "*                                     *" << endl;
            cout << "***************************************" << endl;
            system("pause");
            break;
        }
    }
}

//INICIALIZAR CHIMPOCO
void inicializarChimpoco (int eleccion, int chimpoco[], string &nombreChimpoco) {
    switch (eleccion){
        case 1: // Rockito
            /* VIDA */ chimpoco [0] = 1200;
            /* DAÑO MINIMO */chimpoco [1] = 40;
            /* DAÑO MAXIMO */chimpoco [2] = 50;
            /* TIPO DE CHIMPOCO */chimpoco [3] = eleccion;
            /* BOOST DE ATAQUE */ chimpoco [4] = 3;
            /* TURNOS BOOST DE ATAQUE */ chimpoco [5] = 0;
            /* BOOST DE DEFENSA */ chimpoco [6] = 3;
            /* TURNOS BOOST DE DEFENSA */ chimpoco [7] = 0;
            /* POCION DE VIDA */chimpoco [8] = 3;
            /* VIDA MAXIMA */ chimpoco [9] = 1200;
            nombreChimpoco = "ROCKYTO" ;
            break;
        case 2: // Picante
            chimpoco [0] = 500;
            chimpoco [1] = 55;
            chimpoco [2] = 65;
            chimpoco [3] = eleccion;
            chimpoco [4] = 3;
            chimpoco [5] = 0;
            chimpoco [6] = 3;
            chimpoco [7] = 0;
            chimpoco [8] = 3;
            chimpoco [9] = 500;
            nombreChimpoco = "PICANTE" ;
            break;
        case 3: // Freddy
            chimpoco [0] = 700;
            chimpoco [1] = 35;
            chimpoco [2] = 55;
            chimpoco [3] = eleccion;
            chimpoco [4] = 3;
            chimpoco [5] = 0;
            chimpoco [6] = 3;
            chimpoco [7] = 0;
            chimpoco [8] = 3;
            chimpoco [9] = 700;
            nombreChimpoco = "FREDDY" ;
            break;
        case 4: // Rayin
            chimpoco [0] = 600;
            chimpoco [1] = 15;
            chimpoco [2] = 85;
            chimpoco [3] = eleccion;
            chimpoco [4] = 3;
            chimpoco [5] = 0;
            chimpoco [6] = 3;
            chimpoco [7] = 0;
            chimpoco [8] = 3;
            chimpoco [9] = 600;
            nombreChimpoco = "RAYIN" ;
            break;
        default:
            break;
    }
}

//INICIALIZAR ENEMIGO
void inicializarEnemigo (int i, int enemigo[], string &nombreEnemigo){
    switch (i){
        case 1: // Stitchard
            enemigo[0] = 150;
            enemigo[1] = 5;
            enemigo[2] = 15;
            enemigo[3] = i;
            enemigo[4] = 0;
            nombreEnemigo = "STITCHARD" ;
            break;
        case 2: // FurbyZhor
            enemigo[0] = 300;
            enemigo[1] = 25;
            enemigo[2] = 45;
            enemigo[3] = i;
            enemigo[4] = 0;
            nombreEnemigo = "FURBYZHOR" ;
            break;
        case 3: // HelloCathy
            enemigo[0] = 450;
            enemigo[1] = 40;
            enemigo[2] = 55;
            enemigo[3] = i;
            enemigo[4] = 0;
            nombreEnemigo = "HELLOCATHY" ;
            break;
        case 4: // BabyYorda
            enemigo[0] = 700;
            enemigo[1] = 55;
            enemigo[2] = 75;
            enemigo[3] = i;
            enemigo[4] = 0;
            nombreEnemigo = "BABYYORDA" ;
            break;
        case 5: // TioMickey
            enemigo[0] = 1500;
            enemigo[1] = 25;
            enemigo[2] = 150;
            enemigo[3] = i;
            enemigo[4] = 0;
            nombreEnemigo = "TIOMICKEY" ;
            break;
        default:
            break;
    }
}

//BATALLA
void batalla (int chimpoco[], int enemigo[], string &nombreChimpoco, string &nombreEnemigo) {
    int ronda = 1;
    int contRonda = 0;

    while (true) {
        system("cls");

        turnoJugador(ronda, contRonda, chimpoco, enemigo, nombreChimpoco, nombreEnemigo);

        if (enemigo[0] <= 0) {
            system("cls");
            colorsito (10); // VERDE
            cout << "***************************************" << endl;
            cout << "*                                     *" << endl;
            cout << "*         !Felicidades!               *" << endl;
            cout << "*     "<< nombreEnemigo <<" HA SIDO DERROTADO !   *" << endl;
            cout << "*                                     *" << endl;
            cout << "***************************************" << endl;
            colorsito(10); // VERDE
            system("pause");
            break;
        }

        pasivafreddy  (chimpoco, enemigo, nombreEnemigo); // ACTIVA SU PASIVA INDEPENDIENTEMENTE DE SI ATACA O DEFIENDE

        if (enemigo[4] == 0){
            turnoEnemigo(ronda, contRonda, chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
        } else {enemigo [4] = enemigo[4]-1;}

        if (chimpoco[0] <= 0) {
            system ("cls");
            colorsito(12); // ROJO FUERTE
            cout << "***************************************" << endl;
            cout << "*                                     *" << endl;
            cout << "*         !Lo Siento!                 *" << endl;
            cout << "*      Has Perdido el Juego...        *" << endl;
            cout << "*                                     *" << endl;
            cout << "***************************************" << endl;
            colorsito (10);
            system("pause");
            break;
        }
    }
}

//TURNO JUGADOR
void turnoJugador(int &ronda, int &contRonda, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo) {
    ronda++;
    contRonda++;

    while (true) {
        system("cls");
        colorsito(5);
        cout << "========================================" << endl;
        colorsito(10);
        cout << "         " << nombreChimpoco << " vs " << nombreEnemigo << endl;
        colorsito(5);
        cout << "========================================" << endl;
        colorsito(10);
        cout << " " << nombreChimpoco << " >> Vida: " << chimpoco[0] << endl;
        cout << " " << nombreEnemigo << " >> Vida: " << enemigo[0] << endl;
        colorsito(5);
        cout << "========================================" << endl;
        colorsito(4);
        cout << "1. Atacar " << endl;
        colorsito(11);
        cout << "2. Usar item " << endl;
        colorsito(10);
        cout << "Elige tu accion: ";

        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            int danoMin = chimpoco[1], danoMax = chimpoco[2];
            int danoRealizado = realizarAtaque(chimpoco, danoMin, danoMax);

            if (chimpoco[5] > 0) { // Si hay turnos con el boost activado, se agrega el 30%
                danoRealizado += danoRealizado * 0.30;
                chimpoco[5]--;
                cout << "Se ha consumido una carga de pocion de ataque. Restantes: " << chimpoco[5] << endl;
            }
            pasivaspicante(chimpoco, danoRealizado);
            enemigo[0] -= danoRealizado;
            colorsito (4);
            cout << nombreChimpoco << " ha infligido " << danoRealizado << " de dano a " << nombreEnemigo << endl;
            colorsito (10);
            pasivarayin(chimpoco, enemigo, nombreEnemigo);
            system("pause");
            break;

        } else if (opcion == 2) {
            usaritem(chimpoco, enemigo, nombreChimpoco, nombreEnemigo, contRonda);
            break;

        } else {
            colorsito(4);
            cout << "Opcion invalida." << endl;
            colorsito(7);
            system ("pause");
        }
    }
}

//TURNO ENEMIGO
void turnoEnemigo (int &ronda, int &contRonda, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo) {
    contRonda ++;
    ronda ++;
    system("cls");

    colorsito(5);
    cout << "========================================" << endl;
    colorsito(10);
    cout << "         " << nombreChimpoco << " vs " << nombreEnemigo << endl;
    colorsito(5);
    cout << "========================================" << endl;
    colorsito(10);
    cout << " " << nombreChimpoco << " >> Vida: " << chimpoco[0] << endl;
    cout << " " << nombreEnemigo << " >> Vida: " << enemigo[0] << endl;
    colorsito(5);
    cout << "========================================" << endl;
    colorsito(10);

    int danoMin = enemigo[1];
    int danoMax = enemigo[2];
    int danoEnemigo = realizarAtaque(chimpoco, danoMin, danoMax);

    /// BOOST DE DEFENSA

    if (chimpoco[7] > 0){
        danoEnemigo -= danoEnemigo* 0.20;
        chimpoco[7]--;
        cout << "Se ha consumido una carga de pocion de defensa. Restantes: " << chimpoco[7] << endl;
    }

    pasivasrockito (chimpoco, danoEnemigo);

    chimpoco [0] -= danoEnemigo;
    colorsito (4);
    cout << nombreEnemigo << " ha infligido " << danoEnemigo << " de dano a " << nombreChimpoco << endl;
    colorsito (10);
    system("pause");
}

//REALIZAR ATAQUE
int realizarAtaque(int chimpoco[], int danoMin, int danoMax){
    int danoRealizado, diferenciaDano;
    diferenciaDano = danoMax - danoMin + 1;
    danoRealizado = danoMin + (rand() % diferenciaDano);
    return danoRealizado;
}

/// PASIVAS CHIMPOCO
void pasivasrockito (int chimpoco[], int danoEnemigo){
    if (chimpoco [3] == 1){
        danoEnemigo = danoEnemigo-danoEnemigo*0.15;
    }
}

void pasivaspicante (int chimpoco[], int danoRealizado){
    if (chimpoco[3] == 2) {
        int chance = rand() % 100;
        if (chance < 15) {
            danoRealizado *= 2;
            colorsito (4);
            cout << "GOLPE CRITICO!" << endl;
            colorsito (10);
        }
    }
}

void pasivafreddy (int chimpoco[], int enemigo[], string nombreEnemigo){
    if (chimpoco[3] == 3) {
        int chance = rand() % 100;
        if (chance < 15) {
            enemigo[4] += 2;
            cout << nombreEnemigo << " ha sido congelado!" << endl;
            system ("pause");
        }
    }
}

void pasivarayin (int chimpoco [], int enemigo[], string nombreEnemigo){
    if (chimpoco[3] == 4) {
        int chance = rand() % 100;
        if (chance < 25) {
            enemigo[4] += 1;
            cout << nombreEnemigo << " ha sido paralizado!" << endl;
        }
    }
}

//PASIVAS ENEMIGO

//////////////////////////////// POCIONES ////////////////////////////////

//POCIONES//
void usaritem(int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo, int contRonda) {
    int opcion;
    while (true) {
        opcion = menuitems(chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
        switch (opcion) {
            case 1:  // Boost de ataque
                if (chimpoco[4] > 0) {
                    boostataque(chimpoco);
                    return;
                } else {
                    system("cls");
                    cout << "No tienes suficientes boosts de ataque. Reintenta con otro." << endl;
                    system("pause");
                } break;
            case 2:  // Boost de defensa
                if (chimpoco[6] > 0) {
                    boostdefensa(chimpoco, enemigo, contRonda);
                    return;
                } else {
                    system("cls");
                    cout << "No tienes suficientes boosts de defensa. Reintenta con otro." << endl;
                    system("pause");
                } break;
            case 3:  // Poción de vida
                if (chimpoco[8] > 0) {
                    pocionvida(chimpoco);
                    return;
                } else {
                    system("cls");
                    cout << "No tienes suficientes pociones de vida. Reintenta con otro." << endl;
                    system("pause");
                } break;
            default:
                cout << "Opcion invalida. Reintenta con otra." << endl;
                system("pause");
                system("cls");
                break;
        }
    }
}

//MENU ITEMS
int menuitems(int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo){
    int opcion ;
    system("cls");
    colorsito(5);
    cout << "========================================" << endl;
    colorsito(10);
    cout << "         " << nombreChimpoco << " vs " << nombreEnemigo << endl;
    colorsito(5);
    cout << "========================================" << endl;
    colorsito(10);
    cout << " " << nombreChimpoco << " >> Vida: " << chimpoco[0] << endl;
    cout << " " << nombreEnemigo << " >> Vida: " << enemigo[0] << endl;
    colorsito(5);
    cout << "========================================" << endl;
    colorsito (9);
    cout << "1. Boost de ataque: Incrementa tu dano por 30% << CANTIDAD; " << chimpoco [4] << endl;
    cout << "2. Boost de defensa: Reduce el dano recibido un 20% << CANTIDAD; " << chimpoco [6]<< endl;
    cout << "3. Pocion de vida: Recupera el 50% de tu vida total << CANTIDAD; " << chimpoco [8] << endl;
    colorsito (10);
    cout << "Elige tu accion: ";
    cin >> opcion;
    return opcion;
}

//BOOST ATAQUE
void boostataque (int chimpoco[]){
    chimpoco [4]--;
    chimpoco [5] = chimpoco [5] + 2;
}

//BOOTS DEFENSA
void boostdefensa (int chimpoco[], int enemigo[], int contRonda){
    chimpoco [6]--;
    chimpoco [7] = 2;
}

//POTI VIDA
void pocionvida (int chimpoco[]){
    chimpoco [8]--;
    chimpoco[0] = chimpoco [0] + (chimpoco [9]/2);
    if (chimpoco [0] > chimpoco [9]){
        chimpoco[0] = chimpoco [9] ;
    }
}

/// MANUAL ///

void manual (){
   int opcion;
   while (true) {
        menumanual();
        cin >> opcion;

        if (opcion < 6 && opcion > 0) {
            mostrarOpcion(opcion);
        } else if (opcion == 0) {
            cout << "Saliendo al menú... " << endl;
            system("pause");
            break;
        } else {
            cout << "Opcion invalida, por favor selecciona una opciOn correcta." << endl;
            system("pause");
        }
   }
}

void menumanual () {
    system("cls");
    cout<<"================================================="<<endl;
    cout<<"           MANUAL DE USUARIO - CHIMPOCO          "<<endl;
    cout<<"================================================="<<endl;
    cout<<"1. Especificaciones del Juego                    "<<endl;
    cout<<"2. Detalle de las Opciones del Menú              "<<endl;
    cout<<"3. Funcionamiento de los Combates                "<<endl;
    cout<<"4. Uso de Pociones                               "<<endl;
    cout<<"5. Creditos de los Desarrolladores               "<<endl;
    cout<<"0. Salir al Menu                                 "<<endl;
    cout<<"================================================="<<endl;
    cout<<"Ingrese la opcion deseada: ";
}

void mostrarOpcion(int opcion) {
    system ("cls");
    switch(opcion) {
        case 1:
            cout << "=================================================" << endl;
            cout << "          ESPECIFICACIONES DEL JUEGO:            " << endl ;
            cout << "=================================================" << endl;
            cout << "Titulo: ChimpocoFight " << endl ;
            cout << "Categoria: Juego en consola " << endl ;
            cout << "Plataforma: Code::Blocks " << endl ;
            cout << "Jugadores: 1 o 2 " << endl ;
            cout << "Genero: Pelea por turnos " << endl ;
            cout << endl ;
            cout << "=================================================" << endl;
            cout << "                 DESCRIPCION:                    " << endl ;
            cout << "=================================================" << endl;
            cout << "ChimpocoFight es un juego de pelea por turnos que combina estrategia y azar. " << endl ;
            cout << "Los jugadores eligen un Chimpoco para enfrentarse a una serie de oponentes, " << endl ;
            cout << "donde deberan demostrar sus habilidades y superar desafios para alcanzar " << endl;
            cout << "el titulo de ChimpocoMaster.\n " << endl;
            system ("pause");
            break;
        case 2:
            cout << "=================================================" << endl;
            cout << "        DETALLE DE LAS OPCIONES DEL MENU :       " << endl;
            cout << "=================================================" << endl;
            cout << "1. Aventura: Inicia la historia principal. " << endl;
            cout << "2. Versus: Combate entre dos jugadores. " << endl;
            cout << "3. God Mode: Juega con ventajas ilimitadas. " << endl;
            cout << "4. Estadisticas: Muestra tus estadisticas. " << endl;
            cout << "5. Manual: Instrucciones y creditos del juego. " << endl;
            system ("pause");
            break;
        case 3:
            cout << "=================================================" << endl;
            cout << "        FUNCIONAMIENTO DE LOS COMBATES:          " << endl;
            cout << "=================================================" << endl;
            cout << "- Cada combate se realiza por turnos. " << endl;
            cout << "- Elige entre atacar o usar pociones. " << endl;
            cout << "- La victoria se obtiene al reducir la vida del enemigo a 0. " << endl;
            system ("pause");
            break;
        case 4:
            cout << "=================================================" << endl;
            cout << "                 USO DE POCIONES :               " << endl;
            cout << "=================================================" << endl;
            cout << "- Boost de ataque: Incrementa tu dano por 30%. " << endl;
            cout << "- Boost de defensa: Reduce el dano recibido un 20%. " << endl;
            cout << "- Pocion de vida: Recupera el 50% de tu vida total. " << endl;
            system ("pause");
            break;
        case 5:
            cout << "=================================================" << endl;
            cout << "                  DESARROLADORES:                " << endl;
            cout << "=================================================" << endl;
            cout << "    DESARROLLADORA ;   ABRIL JUANA TRINIDAD      " << endl;
            cout << "=================================================" << endl;
            system ("pause");
            break;
        default:
            cout << "Opcion no valida. " << endl;
            break;
    }
}

/// ///////////// ///
/// EN DESARROLLO ///
/// ///////////// ///

// PASIVA DE STITCHARD
void pasivaStitchard(int enemigo[], int turno) {
    if (turno == 3) {
        enemigo[0] += 150;  // Aumenta la vida en 150
        enemigo[1] = 45;  // Aumenta el daño a 45
        enemigo[2] = 45;  // Establece el daño mínimo y máximo en 45
        cout << "Stitchard entra en furia! Su vida aumenta y su daño incrementa." << endl;
    }
}

// PASIVA DE FURBYZHOR
void pasivaFurbyZhor(int turno, int chimpoco[], string nombreChimpoco) {
    if (turno % 4 == 0) {
        cout << "FurbyZhor canta una canción hipnótica, " << nombreChimpoco << " pierde su próximo turno!" << endl;
        chimpoco[4] = 1;  // Impide el turno del chimpoco
        system("pause");
    }
}

// PASIVA DE HELLOCATHY
void pasivaHelloCathy(int turno, int &danoRecibido) {
    if (turno % 2 == 0) {
        cout << "HelloCathy reduce el daño recibido en un 30%!" << endl;
        danoRecibido *= 0.7;
    } else {
        cout << "HelloCathy recibe un 15% más de daño!" << endl;
        danoRecibido *= 1.15;
    }
}

void modoVersus (){}
void godMode(){}
void estadisticas(){}

