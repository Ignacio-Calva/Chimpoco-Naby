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
            cout<<"Saliendo del programa..."<<endl;
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

//CARGAR NOMBRE
string cargarNombre(){
    string nombreIngresado;
    system("cls");
    cout << "Por favor, ingrese el nombre del jugador: ";
    cin >> nombreIngresado;
    system("cls");
    return nombreIngresado;
}

//MENU SELECCION PERSONAJE
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

//SELECCION PERSONAJE
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

//MODO AVENTURA
void modoAventura (string &nombreJugador){
    int chimpoco [8], enemigo [5];
    string nombreChimpoco = cargarNombre();
    string nombreEnemigo;
    int eleccion = seleccionPersonaje();
    for (int i = 1 ; i < 6 ; i++ ){
        inicializarChimpoco (eleccion, chimpoco, nombreChimpoco);
        inicializarEnemigo (i, enemigo, nombreEnemigo);
        batalla (chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
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
            nombreChimpoco = "ROCKYTO" ;
            break;
        case 2: // Picante
            chimpoco [0] = 500;
            chimpoco [1] = 55;
            chimpoco [2] = 65;
            chimpoco [3] = eleccion;
            nombreChimpoco = "PICANTE" ;
            break;
        case 3: // Freddy
            chimpoco [0] = 700;
            chimpoco [1] = 35;
            chimpoco [2] = 55;
            chimpoco [3] = eleccion;
            nombreChimpoco = "FREDDY" ;
            break;
        case 4: // Rayin
            chimpoco [0] = 600;
            chimpoco [1] = 15;
            chimpoco [2] = 85;
            chimpoco [3] = eleccion;
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
            nombreEnemigo = "STITCHARD" ;
            break;
        case 2: // FurbyZhor
            enemigo[0] = 300;
            enemigo[1] = 25;
            enemigo[2] = 45;
            enemigo[3] = i;
            nombreEnemigo = "FURBYZHOR" ;
            break;
        case 3: // HelloCathy
            enemigo[0] = 450;
            enemigo[1] = 40;
            enemigo[2] = 55;
            enemigo[3] = i;
            nombreEnemigo = "HELLOCATHY" ;
            break;
        case 4: // BabyYorda
            enemigo[0] = 700;
            enemigo[1] = 55;
            enemigo[2] = 75;
            enemigo[3] = i;
            nombreEnemigo = "BABYYORDA" ;
            break;
        case 5: // TioMickey
            enemigo[0] = 1500;
            enemigo[1] = 25;
            enemigo[2] = 150;
            enemigo[3] = i;
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
        cout << "========================================" << endl;
        cout << "         BATALLA INICIADA              " << endl;
        cout << "========================================" << endl;
        cout << " " << nombreChimpoco << " >> Vida: " << chimpoco[0] << endl;
        cout << " " << nombreEnemigo << " >> Vida: " << enemigo[0] << endl;
        cout << "========================================" << endl;

        turnoJugador(ronda, chimpoco, enemigo, nombreChimpoco, nombreEnemigo);

        if (enemigo[0] <= 0) {
            cout << "Has ganado! " << nombreEnemigo << " ha sido derrotado!" << endl;
            system("pause");
            break;
        }

        turnoEnemigo(ronda, chimpoco, enemigo, nombreChimpoco, nombreEnemigo);

        if (chimpoco[0] <= 0) {
            cout << "Has sido derrotado! " << nombreEnemigo << " gana!" << endl;
            system("pause");
            break;

    }
}

}

//TURNO JUGADOR
void turnoJugador(int &ronda, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo){
    ronda ++;
    system("cls");
    cout << "========================================" << endl;
    cout << "         " << nombreChimpoco << " vs " << nombreEnemigo << endl;
    cout << "========================================" << endl;
    cout << " " << nombreChimpoco << " >> Vida: " << chimpoco[0] << endl;
    cout << " " << nombreEnemigo << " >> Vida: " << enemigo[0] << endl;
    cout << "========================================" << endl;
    cout << "1. Atacar " << endl;
    cout << "2. Usar item " << endl;
    cout << "Elige tu accion: ";
    int opcion;
    cin >> opcion;
    while (opcion != 1 && opcion != 2){
        cout << "Opcion invalida." << endl;
        cout << "Elige tu accion: ";
        cin >> opcion;
    }

    int danoMin = chimpoco[1];
    int danoMax = chimpoco[2];

    if (opcion == 1) {
        int dano = realizarAtaque (danoMin, danoMax);
        enemigo [0] -= dano;
        cout << nombreChimpoco << " ha infringido " << dano << " de dano a " << nombreEnemigo << endl;
           system ("pause");
    } else if (opcion == 2){
        //ACA VA LA FUNCION XD
    }
}

//TURNO ENEMIGO
void turnoEnemigo (int &ronda, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo) {
    int contRondas =0;
    contRondas ++;
    ronda ++;
    system("cls");

    cout << "========================================" << endl;
    cout << "         " << nombreChimpoco << " vs " << nombreEnemigo << endl;
    cout << "========================================" << endl;
    cout << " " << nombreChimpoco << " >> Vida: " << chimpoco[0] << endl;
    cout << " " << nombreEnemigo << " >> Vida: " << enemigo[0] << endl;
    cout << "========================================" << endl;

    int danoMin = enemigo[1];
    int danoMax = enemigo[2];

    int danoEnemigo = realizarAtaque(danoMin, danoMax);
    chimpoco [0] -= danoEnemigo;
    cout << nombreEnemigo << " ha infligido " << danoEnemigo << " de dano a " << nombreChimpoco << endl;
    system("pause");
}

//REALIZAR ATAQUE
int realizarAtaque(int danoMin, int danoMax){
    int danoRealizado, diferenciaDano;
    diferenciaDano = danoMax - danoMin + 1;
    danoRealizado = danoMin + (rand() % diferenciaDano);
    return danoRealizado;
}


//////////////////////////////////////////////////////////////////////////
///////////////////////////// EN DESARROLLO /////////////////////////////
//////////////////////////////////////////////////////////////////////////


//PASIVAS DE ENEMIGOS
void pasivasEnemigos(int contRondas, int idEnemigo, int &danoMin, int &danoMax, int &enemigoVida){
    switch (idEnemigo){
    case 1:
        if (contRondas == 3){
            enemigoVida += 150;
            danoMin = 15;
            danoMax = 45;
            cout << "Stitchard ha activado su pasiva!" << endl;
            system("pause");
        } else if (contRondas == 4){
            enemigoVida -= 150;
            danoMin = 5;
            danoMax = 15;
            cout << "Se ha agotado la pasiva de Stitchard!" << endl;
        }
        break;
    case 2:
    default:
        break;
    }
}

//ELEGIR POCIONES
void elegirPociones(int &cargasBoostAtaque, int &cargasBoostDefensa, int &cargasPocionVida){
    int opcion;
    system("cls");
    cout << "======================================" << endl;
    cout << "=========POCIONES DISPONIBLES=========" << endl;
    cout << "======================================" << endl;
    cout << "1) Pociones de Boost de ataque: " << cargasBoostAtaque << endl;
    cout << "2) Pociones de Boost de defensa: " << cargasBoostDefensa << endl;
    cout << "3) Pociones de Pociones de vida: " << cargasPocionVida << endl;
    cout << "======================================" << endl;
    cout << "Por favor, elija la pocion deseada: ";
    cin >> opcion;
    switch (opcion){
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }

}

//
void modoVersus (){}
void godMode(){}
void estadisticas(){}
void manual (){}
