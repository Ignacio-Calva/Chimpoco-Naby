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
    int opcion = 1; int danoRecibido[5] = {0}, danoRealizado[5] = {0}, pocionesUsadas[5] = {0}, turnosSob[5] = {0};
    while (opcion !=0){
        mostrarMenu();
        cin>>opcion;
        switch (opcion) {
        case 1:
            modoAventura (danoRecibido, danoRealizado, pocionesUsadas, turnosSob);
            break;
        case 2:
            modoVersus ();
            break;
        case 3:
            godMode ();
            break;
        case 4:
            estadisticas (danoRecibido, danoRealizado, pocionesUsadas, turnosSob);
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

// MOSTRAR MENU
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

// CARGAR NOMBRE
string cargarNombre(){
    string nombreIngresado;
    system("cls");
    cout << "Por favor, ingrese el nombre del jugador: ";
    cin >> nombreIngresado;
    system("cls");
    return nombreIngresado;
}

/// FUNCIONES MODO AVENTURA ///

// BIENVENIDA AVENTURA
void bienvenidaAventura() {
    system ("cls");
    colorsito (5);
    cout << "===========================================================" << endl;
    colorsito (10);
    cout << R"(
     Bienvenido al MODO AVENTURA de ChimpocoFight!
      Por favor, ingresa tu nombre para comenzar.

       Luego, preparate para elegir tu Chimpoco
  Que la suerte este de tu lado, !y comienza la aventura!
    )" << endl;
    colorsito (5);
    cout << "===========================================================" << endl;
    colorsito (10);
}

// MODO AVENTURA
void modoAventura (int danoRecibido [], int danoRealizado [], int pocionesUsadas[], int turnosSob[]){
    bienvenidaAventura();
    string nombreJugador;
    cout << " Ingresa tu nombre: ";
    cin >> nombreJugador;
    int chimpoco [11], enemigo [10];
    int  partidaActual [4]{0}; // 0 = DAÑO RECIBIDO, 1 = DAÑO REALIZADO, 2 = POCIONES USADAS, 3 = TURNOS SOBREVIVIDOS.
    string nombreChimpoco;
    string nombreEnemigo;
    system("cls");
    int eleccion = seleccionPersonaje();
    for (int i = 1 ; i < 6 ; i++ ){
        inicializarChimpocoGM (eleccion, chimpoco, nombreChimpoco);
        inicializarEnemigo (i, enemigo, nombreEnemigo);
        batalla (chimpoco, enemigo, nombreChimpoco, nombreEnemigo, partidaActual);
        cambioderonda(i);
    }
    cargarEstadisticas (partidaActual, danoRecibido, danoRealizado, pocionesUsadas, turnosSob);
}

// SELECCION PERSONAJE
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
            menuSeleccionPersonajes();
            colorsito (4);
            cout << "Opcion invalida. Elija un numero valido." << endl;
            eleccion = 0;
            break;
        }
    }
    system("pause");
    return eleccion;
}

// MENU SELECCION PERSONAJE
void menuSeleccionPersonajes(){
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
    cout << "Ingrese el personaje deseado: " << endl;
}

// INICIALIZAR CHIMPOCO
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
            /* TURNOS SALTADOS */ chimpoco [10] = 0;
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
            chimpoco [10] = 0;
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
            chimpoco [10] = 0;
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
            chimpoco [10] = 0;
            nombreChimpoco = "RAYIN" ;
            break;
        default:
            break;
    }
}

// INICIALIZAR ENEMIGO
void inicializarEnemigo (int i, int enemigo[], string &nombreEnemigo){
    switch (i){
        case 1: // Stitchard
            //enemigo[0] = 150;
            enemigo[0] = 100;
            enemigo[1] = 5;
            enemigo[2] = 15;
            enemigo[3] = i;
            enemigo[4] = 0; //TURNOS SALTADOS
            enemigo[9] = 150; //VIDA MAX // LO GUARDO EN EL 9 POR LA BARRA DE VIDA EN EL MODO VERSUS ;)
            nombreEnemigo = "STITCHARD" ;
            break;
        case 2: // FurbyZhor
            //enemigo[0] = 300;
            enemigo[0] = 100;
            enemigo[1] = 25;
            enemigo[2] = 45;
            enemigo[3] = i;
            enemigo[4] = 0;
            enemigo[9] = 300;
            nombreEnemigo = "FURBYZHOR" ;
            break;
        case 3: // HelloCathy
            //enemigo[0] = 450;
            enemigo[0] = 100;
            enemigo[1] = 40;
            enemigo[2] = 55;
            enemigo[3] = i;
            enemigo[4] = 0;
            enemigo [9] = 450;
            nombreEnemigo = "HELLOCATHY" ;
            break;
        case 4: // BabyYorda
            //enemigo[0] = 700;
            enemigo[0] = 100;
            enemigo[1] = 55;
            enemigo[2] = 75;
            enemigo[3] = i;
            enemigo[4] = 0;
            enemigo[9] = 700;
            nombreEnemigo = "BABYYORDA" ;
            break;
        case 5: // TioMickey
            //enemigo[0] = 1500;
            enemigo[0] = 100;
            enemigo[1] = 25;
            enemigo[2] = 150;
            enemigo[3] = i;
            enemigo[4] = 0;
            enemigo[9] = 1500;
            nombreEnemigo = "TIOMICKEY" ;
            break;
        default:
            break;
    }
}

// BATALLA
void batalla (int chimpoco[], int enemigo[], string &nombreChimpoco, string &nombreEnemigo, int partidaActual[]) {
    int rondaChimpoco, rondaEnemigo = 0;
    bool tiomickey = false;
    while (true) {
        system("cls");

        pasivaBabyYorda (rondaEnemigo, chimpoco, enemigo, nombreChimpoco, nombreEnemigo);

        if (chimpoco [10] == 0){
            turnoJugador (rondaChimpoco, chimpoco, enemigo, nombreChimpoco, nombreEnemigo, tiomickey, rondaEnemigo, partidaActual);
        } else {chimpoco [10] = 0;}

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
            turnoEnemigo(rondaEnemigo, chimpoco, enemigo, nombreChimpoco, nombreEnemigo, tiomickey, partidaActual);
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

        partidaActual [3] = partidaActual [3] +1 ;
        system ("pause");
    }
}

// TURNO JUGADOR
void turnoJugador(int &rondaChimpoco, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo, bool &tiomickey, int &rondaEnemigo, int partidaActual[]) {
    rondaChimpoco++;

    while (true) {
        system("cls");
        mostrarVida (chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
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
            pasivaTioMickey (danoRealizado, enemigo, chimpoco, rondaEnemigo, tiomickey); // PRIMERA PARTE DE SU PASIVA, LA OTRA PARTE ESTA EN EL TURNO ENEMIGO

            if (chimpoco[5] > 0) { // Si hay turnos con el boost activado, se agrega el 30%
                danoRealizado += danoRealizado * 0.30;
                chimpoco[5]--;
                colorsito (9);
                cout << "Se ha consumido una carga de pocion de ataque. Restantes: " << chimpoco[5] << endl;
            }

            pasivaspicante(chimpoco, danoRealizado);
            pasivaHelloCathy (rondaChimpoco, danoRealizado, enemigo);
            enemigo[0] -= danoRealizado;
            colorsito (4);
            cout << nombreChimpoco << " ha infligido " << danoRealizado << " de dano a " << nombreEnemigo << endl; colorsito (10);
            partidaActual [1] = partidaActual [1] + danoRealizado;
            pasivarayin(chimpoco, enemigo, nombreEnemigo);
            system("pause");
            break;

        } else if (opcion == 2) {
            int resultado = usaritem(chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
            if (resultado == 0) {
            } else {
                partidaActual [2] = partidaActual [2] + 1;
                break;}

        } else {
            colorsito(4);
            cout << "Opcion invalida." << endl;
            colorsito(7);
            system ("pause");
        }
    }
}

// TURNO ENEMIGO
void turnoEnemigo (int &rondaEnemigo, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo, bool &tiomickey, int partidaActual[]) {
    rondaEnemigo ++;
    system("cls");

    pasivaStitchard (enemigo, rondaEnemigo);
    pasivaFurbyZhor (rondaEnemigo, enemigo, chimpoco, nombreChimpoco);
    mostrarVida (chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
    coutpasivas (rondaEnemigo, enemigo);

    int danoMin = enemigo[1];
    int danoMax = enemigo[2];
    int danoEnemigo = realizarAtaque(chimpoco, danoMin, danoMax);

    /// BOOST DE DEFENSA

    if (chimpoco[7] > 0){
        danoEnemigo -= danoEnemigo* 0.20;
        chimpoco[7]--;
        colorsito (9);
        cout << "Se ha consumido una carga de pocion de defensa. Restantes: " << chimpoco[7] << endl;
    }

    pasivasrockito (chimpoco, danoEnemigo);

    if (tiomickey) {
        danoEnemigo += danoEnemigo * 0.15; // SEGUNDA PARTE DE SU PASIVA
        cout << "TioMickey ha aumentado su ataque en un 15% debido a su pasiva!" << endl;
        tiomickey = false;
    }

    chimpoco [0] -= danoEnemigo;
    colorsito (4);
    cout << nombreEnemigo << " ha infligido " << danoEnemigo << " de dano a " << nombreChimpoco << endl; colorsito (10);
    partidaActual [0] = partidaActual [0] + danoEnemigo;
}

/// FUNCIONES MODO VERSUS ///

// BIENVENIDA VERSUS
void bienvenidaVersus (){
    system("cls");
    colorsito(5);
    cout << "===========================================================" << endl;
    colorsito(11);
    cout << R"(
         Bienvenidos al MODO VERSUS de ChimpocoFight!
         Dos jugadores estan a punto de enfrentarse.

       Cada uno debera ingresar su nombre y tirar los dados
        !El que saque el numero mas alto elige primero!

                    !Que gane el mejor!
        )" << endl;
    colorsito(5);
    cout << "===========================================================" << endl;
    colorsito(11);


}

// MODO VERSUS
void modoVersus(){
    int chimpocoUno [11], chimpocoDos[11];
    bienvenidaVersus ();
    string nombreChimpocoUno, nombreChimpocoDos, nombreJugadorUno, nombreJugadorDos;
    colorsito (5);
    cout << "Ingrese el nombre del Jugador Uno; " ; colorsito (10);
    cin >> nombreJugadorUno ; colorsito (5);
    cout << "Ingrese el nombre del Jugador Dos; " ; colorsito (10);
    cin >> nombreJugadorDos ; colorsito (5);
    string nombreGanador = nombreJugadorUno; string nombrePerdedor = nombreJugadorDos;
    int turno =  dados (nombreJugadorUno, nombreJugadorDos);
    inicializarPersonajes (turno, chimpocoUno, chimpocoDos, nombreChimpocoUno, nombreChimpocoDos, nombreJugadorUno, nombreJugadorDos);
    batallaVersus (chimpocoUno, chimpocoDos, nombreChimpocoUno, nombreChimpocoDos, nombreJugadorUno, nombreJugadorDos);
}

// BATALLA VERSUS
void batallaVersus(int chimpocoUno[], int chimpocoDos[], string nombreChimpocoUno, string nombreChimpocoDos, string nombreJugadorUno, string nombreJugadorDos) {
    int rondaChimpocoUno = 0, rondaChimpocoDos = 0;
    bool tiomickey = false;

    while (true) {
        system("cls");
        if (chimpocoUno[10] > 0) {
            chimpocoUno[10]-- ;
            colorsito(4);
            cout << nombreChimpocoUno << " ha sido congelado, y pierde su turno ;(" << endl;
            colorsito(10);
        } else {
            colorsito(5);
            cout << "========================================" << endl;
            colorsito(12);
            cout << "         ES EL TURNO DE " << nombreJugadorUno << endl;
            colorsito(5);
            turnoJugadorVersus(rondaChimpocoUno, chimpocoUno, chimpocoDos, nombreChimpocoUno, nombreChimpocoDos, rondaChimpocoDos);
        }

        if (chimpocoDos[0] <= 0) {
            mostrarGanador(nombreChimpocoUno);
            break;
        }

        if (chimpocoDos[10] > 0) {
            system ("cls");
            chimpocoDos[10]--;
            colorsito(9);
            cout << nombreChimpocoDos << " esta congelado y no puede actuar este turno :( " << endl;
            colorsito(10);
            system ("pause");
        } else {
            colorsito(5);
            system("cls");
            cout << "========================================" << endl;
            colorsito(9);
            cout << "         ES EL TURNO DE " << nombreJugadorDos << endl;
            colorsito(5);
            turnoJugadorVersus(rondaChimpocoDos, chimpocoDos, chimpocoUno, nombreChimpocoDos, nombreChimpocoUno, rondaChimpocoUno);
        }

        if (chimpocoUno[0] <= 0) {
            mostrarGanador(nombreChimpocoDos);
            break;
        }
    }
}

// TURNO JUGADOR VERSUS
void turnoJugadorVersus(int &rondaChimpoco, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo, int &rondaEnemigo) {
    rondaChimpoco++;

    while (true) {
        mostrarVida(chimpoco, enemigo, nombreChimpoco, nombreEnemigo);

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

            if (chimpoco[5] > 0) {
                danoRealizado += danoRealizado * 0.30;
                chimpoco[5]--;
                colorsito(9);
                cout << "Se ha consumido una carga de pocion de ataque. Restantes: " << chimpoco[5] << endl;
            }

            if (enemigo[7] > 0) {
                int danoRecibido = danoRealizado;
                danoRealizado -= danoRecibido * 0.20;
                cout << "El dano sin la defensa habria sido: " << danoRecibido << endl;
                cout << "El dano final es de: " << danoRealizado << endl;
                //danoRealizado = danoRealizado - danoRealizado * 0.20;
                enemigo[7]--;
                colorsito(9);
                cout << "Se ha consumido una carga de pocion de defensa de " << nombreEnemigo << ". Restantes: " << enemigo [7] << endl;
                colorsito(10);
            }

            pasivasChimpoco(chimpoco, danoRealizado, enemigo, nombreEnemigo);

            enemigo[0] -= danoRealizado;
            colorsito(4);
            cout << nombreChimpoco << " ha infligido " << danoRealizado << " de dano a " << nombreEnemigo << endl;
            colorsito(10);
            system("pause");
            break;
        } else if (opcion == 2) {
            int resultado = usaritem(chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
            if (resultado != 0) {
                break;
            }
        } else {
            colorsito(4);
            cout << "Opcion invalida." << endl;
            colorsito(7);
            system("pause");
        }
    }
}

// FUNCION PARA APLICAR LAS PASIVAS Y EFECTOS
void pasivasChimpoco(int chimpoco[], int &danoRealizado, int enemigo[], string nombreEnemigo) {
    if (chimpoco[3] == 1) {
        pasivasrockito(chimpoco, danoRealizado);
    } else if (chimpoco[3] == 2) {
        pasivaspicante(chimpoco, danoRealizado);
    } else if (chimpoco[3] == 3) {
        int chance = rand() % 100;
        if (chance < 70) {
            enemigo[10] += 2;
            cout << nombreEnemigo << " ha sido congelado!" << endl;}
    } else if (chimpoco[3] == 4) {
        int chance = rand() % 100;
        if (chance < 70) {
            enemigo[10] += 1;
            cout << nombreEnemigo << " ha sido paralizado!" << endl;
        }
    }
}

// COUT MOSTRAR GANADOR
void mostrarGanador(string &nombreGanador) {
    system("cls");
    colorsito(10);
    cout << "***************************************" << endl;
    cout << "*                                     *" << endl;
    cout << "*         !Felicidades!               *" << endl;
    cout << "*     " << nombreGanador << " HA GANADO EL COMBATE!   *" << endl;
    cout << "*                                     *" << endl;
    cout << "***************************************" << endl;
    colorsito(10);
    system("pause");
}

// TIRAR DADO
int tirarDado() {
    return rand() % 6 + 1;
}

// DADOS
int dados (string nombreJugadorUno, string nombreJugadorDos){
    string ganador;
    int dadosJ1, dadosJ2, turno;
    do{
        system ("cls"); colorsito (5);
        cout << "================================================="<<endl; colorsito (10);
        cout << " TIRA LOS DADOS EL JUGADOR " << nombreJugadorUno << endl; colorsito (5);
        cout << "================================================="<<endl; colorsito (10);
        dadosJ1 = tirarDado();
        cout <<" SACO " << dadosJ1 << endl; colorsito (5);
        cout << "================================================="<<endl; colorsito (10);
        cout << " TIRA LOS DADOS EL JUGADOR " << nombreJugadorDos << endl; colorsito (5);
        cout << "================================================="<<endl; colorsito (10);
        dadosJ2 = tirarDado();
        cout << " SACO " << dadosJ2 << endl; colorsito (5);
        cout << "================================================="<<endl; colorsito (10);

        if (dadosJ1>dadosJ2) {
            ganador = nombreJugadorUno;
            turno = 1;
        } else if (dadosJ2>dadosJ1) {
            ganador = nombreJugadorDos;
            turno = 2; }
        else { cout << " !HAY UN EMPATE! SE DEBE VOLVER A TIRAR" << endl; colorsito (5);
               cout << "================================================="<<endl; colorsito (10);
               system ("pause");}

    } while (dadosJ1 == dadosJ2);

    cout << " !EL JUGADOR " << ganador << " GANA! ELIJE SU CHIMPOCO PRIMERO!" << endl;
    system ("pause");
    return turno;
}

// INICIALIZAR PERSONAJES
void inicializarPersonajes(int turno, int chimpocoUno[], int chimpocoDos[], string &nombreChimpocoUno, string &nombreChimpocoDos, string nombreJugadorUno, string nombreJugadorDos) {
    int eleccionUno, eleccionDos;
    system("cls");
    if (turno == 1) {
        colorsito(5);
        cout << "========================================" << endl; colorsito(10);
        cout << "         ELIGE EL JUGADOR " << nombreJugadorUno << endl; colorsito(5);
        eleccionUno = seleccionPersonaje();
        inicializarChimpoco(eleccionUno, chimpocoUno, nombreChimpocoUno);

        do {
            system("cls");
            colorsito(5);
            cout << "========================================" << endl; colorsito(10);
            cout << "         ELIGE EL JUGADOR " << nombreJugadorDos << endl; colorsito(5);
            eleccionDos = seleccionPersonaje();

            if (eleccionUno == eleccionDos) {
                colorsito (4);
                cout << "NO PUEDES ELEGIR ESE CHIMPOCO, ELIGE OTRO" << endl; colorsito (10);
                system("pause");
            } else { inicializarChimpoco(eleccionDos, chimpocoDos, nombreChimpocoDos);}

        } while (eleccionUno == eleccionDos);

    } else {
        colorsito(5);
        cout << "========================================" << endl; colorsito(10);
        cout << "         ELIGE EL JUGADOR " << nombreJugadorDos << endl; colorsito(5);
        eleccionDos = seleccionPersonaje();
        inicializarChimpoco(eleccionDos, chimpocoDos, nombreChimpocoDos);

        do {
            system("cls");
            colorsito(5);
            cout << "========================================" << endl; colorsito(10);
            cout << "         ELIGE EL JUGADOR " << nombreJugadorUno << endl; colorsito(5);
            eleccionUno = seleccionPersonaje();

            if (eleccionUno == eleccionDos) {
                colorsito (4);
                cout << "NO PUEDES ELEGIR ESE CHIMPOCO, ELIGE OTRO" << endl; colorsito (10);
                system("pause");
            } else { inicializarChimpoco(eleccionUno, chimpocoUno, nombreChimpocoUno);}

        } while (eleccionUno == eleccionDos);
    }
}


/// FUNCIONES GODMODE ///

// BIENVENIDA GODMODE
void bienvenidaGodMode(){
 system("cls");
    colorsito(5);
    cout << "===========================================================" << endl;
    colorsito(11);
    cout << R"(
         Bienvenidos al GOD MODE de ChimpocoFight!
         Este es un modo de prueba con poder ilimitado.

       Cada jugador tendra 9999 puntos de vida y 99 pociones,
            permitiendo experimentar al maximo!

        Pueden salir del combate y volver al menu principal
                 en cualquier momento.

                    !Que comience la batalla!
        )" << endl;
    colorsito(5);
    cout << "===========================================================" << endl;
    colorsito(11);
}

// GOD MODE
void godMode (){
    bienvenidaGodMode();
    string nombreJugador, nombreChimpoco, nombreEnemigo;
    cout << " Ingresa tu nombre: ";
    cin >> nombreJugador;
    int chimpoco [11], enemigo [10]; int salir = 1;
    system("cls");
    bool bGodMode = true;
    int eleccion = seleccionPersonaje();
    if (eleccion == 0) {return;}
    for (int i = 1 ; i < 6 ; i++ ){
        inicializarChimpocoGM (eleccion, chimpoco, nombreChimpoco);
        inicializarEnemigo (i, enemigo, nombreEnemigo);
        salir = batallaGodMode (chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
        if (salir == 0) {return;}
        cambioderonda(i);
    }
}

// INICIALIZAR CHIMPOCO
void inicializarChimpocoGM (int eleccion, int chimpoco[], string &nombreChimpoco) {
    chimpoco [0] = 9999; // VIDA
    chimpoco [4] = 99; // BOOST AT
    chimpoco [6] = 99; // BOOST DEF
    chimpoco [8] = 99; // POTI VIDA
    chimpoco [9] = 9999; // VIDA MAX

    switch (eleccion){
        case 1: // Rockito
            chimpoco [1] = 40;
            chimpoco [2] = 50;
            chimpoco [3] = eleccion;
            chimpoco [5] = 0;
            chimpoco [7] = 0;
            chimpoco [10] = 0;
            nombreChimpoco = "ROCKYTO" ;
            break;
        case 2: // Picante
            chimpoco [1] = 55;
            chimpoco [2] = 65;
            chimpoco [3] = eleccion;
            chimpoco [5] = 0;
            chimpoco [7] = 0;
            chimpoco [10] = 0;
            nombreChimpoco = "PICANTE" ;
            break;
        case 3: // Freddy
            chimpoco [1] = 35;
            chimpoco [2] = 55;
            chimpoco [3] = eleccion;
            chimpoco [5] = 0;
            chimpoco [7] = 0;
            chimpoco [10] = 0;
            nombreChimpoco = "FREDDY" ;
            break;
        case 4: // Rayin
            chimpoco [1] = 15;
            chimpoco [2] = 85;
            chimpoco [3] = eleccion;
            chimpoco [5] = 0;
            chimpoco [7] = 0;
            chimpoco [10] = 0;
            nombreChimpoco = "RAYIN" ;
            break;
        default:
            break;
    }
}

// BATALLA GODMODE
int batallaGodMode(int chimpoco[], int enemigo[], string &nombreChimpoco, string &nombreEnemigo) {
    int rondaChimpoco, rondaEnemigo = 0;
    int salir = 1;
    bool tiomickey = false;
    while (true) {
        system("cls");

        pasivaBabyYorda(rondaEnemigo, chimpoco, enemigo, nombreChimpoco, nombreEnemigo);

        if (chimpoco[10] == 0) {
            salir = turnoJugadorGM(rondaChimpoco, chimpoco, enemigo, nombreChimpoco, nombreEnemigo, tiomickey, rondaEnemigo);
        } else {chimpoco[10] = 0;}

        if (salir == 0) {return 0;}  // Si el jugador decide salir, retorna 0 para salir al menú principal.

        if (enemigo[0] <= 0) {
            system("cls");
            colorsito(10); // VERDE
            cout << "***************************************" << endl;
            cout << "*                                     *" << endl;
            cout << "*         !Felicidades!               *" << endl;
            cout << "*     " << nombreEnemigo << " HA SIDO DERROTADO !   *" << endl;
            cout << "*                                     *" << endl;
            cout << "***************************************" << endl;
            colorsito(10); // VERDE
            system("pause");
            break;
        }

        pasivafreddy(chimpoco, enemigo, nombreEnemigo); // ACTIVA SU PASIVA INDEPENDIENTEMENTE DE SI ATACA O DEFIENDE

        if (enemigo[4] == 0) {
            turnoEnemigo(rondaEnemigo, chimpoco, enemigo, nombreChimpoco, nombreEnemigo, tiomickey, 0);
        } else {enemigo[4] = enemigo[4] - 1;}

        if (salir == 0) {return 0;}  // Si el jugador decide salir, retorna 0 para salir al menú principal.

        if (chimpoco[0] <= 0) {
            system("cls");
            colorsito(12); // ROJO FUERTE
            cout << "***************************************" << endl;
            cout << "*                                     *" << endl;
            cout << "*         !Lo Siento!                 *" << endl;
            cout << "*      Has Perdido el Juego...        *" << endl;
            cout << "*                                     *" << endl;
            cout << "***************************************" << endl;
            colorsito(10);
            system("pause");
            break;
        }
    }
    return 1;
}

// TURNO JUGADOR
int turnoJugadorGM(int &rondaChimpoco, int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo, bool &tiomickey, int &rondaEnemigo) {
    rondaChimpoco++;

    while (true) {
        system("cls");
        mostrarVida(chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
        colorsito(4);
        cout << "0. Salir al menu principal" << endl; // Nueva opción para salir
        colorsito(4);
        cout << "1. Atacar " << endl;
        colorsito(11);
        cout << "2. Usar item " << endl;
        colorsito(10);
        cout << "Elige tu accion: ";
        int opcion;
        cin >> opcion;

        if (opcion == 0) {
            return 0; // Retorna 0 para indicar que el jugador quiere salir al menú principal.
        } else if (opcion == 1) {
            int danoMin = chimpoco[1], danoMax = chimpoco[2];
            int danoRealizado = realizarAtaque(chimpoco, danoMin, danoMax);
            pasivaTioMickey(danoRealizado, enemigo, chimpoco, rondaEnemigo, tiomickey); // PRIMERA PARTE DE SU PASIVA, LA OTRA PARTE ESTA EN EL TURNO ENEMIGO

            if (chimpoco[5] > 0) { // Si hay turnos con el boost activado, se agrega el 30%
                danoRealizado += danoRealizado * 0.30;
                chimpoco[5]--;
                colorsito(9);
                cout << "Se ha consumido una carga de pocion de ataque. Restantes: " << chimpoco[5] << endl;
            }

            pasivaspicante(chimpoco, danoRealizado);
            pasivaHelloCathy(rondaChimpoco, danoRealizado, enemigo);
            enemigo[0] -= danoRealizado;
            colorsito(4);
            cout << nombreChimpoco << " ha infligido " << danoRealizado << " de dano a " << nombreEnemigo << endl;
            colorsito(10);
            pasivarayin(chimpoco, enemigo, nombreEnemigo);
            system("pause");
            break;

        } else if (opcion == 2) {
            int resultado = usaritem(chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
            if (resultado == 0) {
            } else { break;}

        } else {
            colorsito(4);
            cout << "Opcion invalida." << endl;
            colorsito(7);
            system("pause");
        }
    }
    return 1; // Continúa en el juego
}

/// ESTADISTICAS
void estadisticas (int danoRecibido [], int danoRealizado [], int pocionesUsadas[], int turnosSob[]){
    int opcion;
    do{ system("cls");
        colorsito (5);
        cout<<"================================================="<<endl; colorsito (10);
        cout<<"                   ESTADISTICA                   "<<endl; colorsito (5);
        cout<<"================================================="<<endl; colorsito (10);
        cout<<"1. Ver ultimas  partidas                         "<<endl;
        cout<<"0. Salir                                         "<<endl; colorsito (5);
        cout<<"================================================="<<endl; colorsito (10);
        cout<<"Ingrese la opcion deseada: ";
        cin >> opcion;

        if (opcion == 1) {
            system ("cls");
            for (int i=1 ; i<6 ; i++ ){
                colorsito (47);
                cout << "PARTIDA " << i << " ;" << endl; colorsito (10);
                cout << "Dano recibido;" << danoRecibido [i-1] << endl;
                cout << "Dano realizado;" << danoRealizado [i-1] << endl;
                cout << "Pociones usadas;" << pocionesUsadas [i-1] << endl;
                cout << "Turnos sobrevividos;" << turnosSob [i-1] << endl; colorsito (8);
            }   system ("pause");
        }
    } while (opcion !=0);
}

void cargarEstadisticas (int partidaActual[], int danoRecibido[], int danoRealizado[], int pocionesUsadas[], int turnosSob[]){ // FUNCION PARA CARGAR LA PARTIDA ACTUAL
    for (int i=1 ; i<6 ; i++){
        if (danoRecibido [i-1] == 0){
            danoRecibido [i-1] = partidaActual [0];
            danoRealizado [i-1] = partidaActual [1];
            pocionesUsadas [i-1] = partidaActual [2];
            turnosSob [i-1] = partidaActual [3];
            return;
        }
    }

    if (danoRecibido[4]!=0){
        //CORRE TODO UNA POCICION PARA ATRAS, PERDIENDO LA ULTIMA
        danoRecibido [0] = danoRecibido [1]; danoRealizado [0] = danoRealizado [1]; pocionesUsadas [0] = pocionesUsadas [1]; turnosSob [0] = partidaActual [1];
        danoRecibido [1] = danoRecibido [2]; danoRealizado [1] = danoRealizado [2]; pocionesUsadas [1] = pocionesUsadas [2]; turnosSob [1] = partidaActual [2];
        danoRecibido [2] = danoRecibido [3]; danoRealizado [2] = danoRealizado [3]; pocionesUsadas [2] = pocionesUsadas [3]; turnosSob [2] = partidaActual [3];
        danoRecibido [3] = danoRecibido [4]; danoRealizado [3] = danoRealizado [4]; pocionesUsadas [3] = pocionesUsadas [4]; turnosSob [3] = partidaActual [4];
        // GUARDA LA ULTIMA PARTIDA COMO ULIMA PARTIDA
        danoRecibido [4] = partidaActual [0];
        danoRealizado [4] = partidaActual [1];
        pocionesUsadas [4] = partidaActual [2];
        turnosSob [4] = partidaActual [3];
    }
}

// MOSTRAR VIDA
void mostrarVida (int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo){
    colorsito(5);
    cout << "========================================" << endl;
    colorsito(10);
    cout << "         " << nombreChimpoco << " vs " << nombreEnemigo << endl;
    colorsito(5);
    cout << "========================================" << endl;
    colorsito(13);
    cout << "         " << nombreChimpoco << " >> Vida: " << chimpoco[0] << "    " << endl; cout << "              ";
    colorsito(10);
    mostrarBarraVida(chimpoco);
    colorsito(13);
    cout << "         " << nombreEnemigo << " >> Vida: " << enemigo[0] << endl; cout << "              ";
    colorsito(10);
    mostrarBarraVidaEnemigo(enemigo);
    colorsito(5);
    cout << "========================================" << endl;
    colorsito(10);
}

// REALIZAR ATAQUE
int realizarAtaque(int chimpoco[], int danoMin, int danoMax){
    int danoRealizado, diferenciaDano;
    diferenciaDano = danoMax - danoMin + 1;
    danoRealizado = danoMin + (rand() % diferenciaDano);
    return danoRealizado;
}

// MOSTRAR BARRA DE VIDA
void mostrarBarraVida(int chimpoco[]){
    int porcentajeVida;
    porcentajeVida = chimpoco[0]*100/chimpoco[9];
    porcentajeVida = porcentajeVida/10;
    cout << "[ " ;
    for (int i = 0 ; i < porcentajeVida ; i++){
        cout << char(254);
    }
    for (int i = 0 ; i < (10-porcentajeVida) ; i++){
        cout << char(174);
    }
    cout << " ]" << endl;
}

void mostrarBarraVidaEnemigo(int enemigo[]){
    int porcentajeVida;
    porcentajeVida = enemigo[0]*100/enemigo[9];
    porcentajeVida = porcentajeVida/10;
    cout << "[ " ;
    for (int i = 0 ; i < porcentajeVida ; i++){
        cout << char(254);
    }
    for (int i = 0 ; i < (10-porcentajeVida) ; i++){
        cout << char(174);
    }
    cout << " ]" << endl;
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

// COUT FINAL
void coutFinal (string nombreChimpoco, string nombreEnemigo) {
    system("cls");
    colorsito(5);
    cout << "===========================================================" << endl;
    colorsito(10);
    cout << R"(
                 !Felicitaciones, )" << nombreChimpoco << R"(!
       Has derrotado a )" << nombreEnemigo << R"( en una epica batalla!

         !Gracias por jugar a ChimpocoFight!

        )" << endl;
    colorsito(5);
    cout << "===========================================================" << endl;
    colorsito(10);
    system ("pause");
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


/// PASIVAS ENEMIGO
void pasivaStitchard (int enemigo [], int rondaEnemigo){
    if (enemigo[3]==1){
        if (rondaEnemigo == 0){rondaEnemigo = 1;}
        if (rondaEnemigo == 3) {
            enemigo[0] = 150;
            enemigo[1] = 15;
            enemigo[2] = 45;
        }
    }
}

void pasivaFurbyZhor (int rondaEnemigo, int enemigo[], int chimpoco[], string nombreChimpoco){
    if (enemigo[3]==2){
        if (rondaEnemigo == 0){rondaEnemigo = 1;}
        if (rondaEnemigo % 4 == 0) {
            chimpoco[10] = 1;
        }
    }
}

void pasivaHelloCathy (int rondaChimpoco, int &danoRecibido, int enemigo []){
    if (rondaChimpoco % 2 == 0 && enemigo[3] == 3) {
        cout << "HELLOCATHY REDUCE EL DANO RECIBIDO EN UN 30%!" << endl;
        danoRecibido *= 0.7;
    } else if (enemigo[3] == 3){
        cout << "HELLOCATHY RECIBE EN 15% MAS DE DANO!" << endl;
        danoRecibido *= 1.15;
    }
}

void pasivaBabyYorda (int &rondaEnemigo, int chimpoco[], int enemigo [], string nombreChimpoco, string nombreEnemigo){
    if (enemigo[3]==4){
        if (rondaEnemigo == 0){rondaEnemigo = 1;}
        if (rondaEnemigo % 3 == 0){
            mostrarVida (chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
            int accionAleatoria = rand() % 4; // 0: atacar, 1: poción, 2: boost ataque, 3: boost defensa
            cout << "BABYYORDA CONTROLA EL TURNO DE " << nombreChimpoco << "!" << endl;

            if (accionAleatoria == 1 && chimpoco[8] > 0) {
                // Simula el uso de una poción
                pocionvida (chimpoco);
                colorsito (9);
                cout << "Se ha utilizado una pocion de vida!"<<endl;
                colorsito (10);
            } else if (accionAleatoria == 2 && chimpoco[4] > 0) {
                // Activa el boost de ataque
                boostataque(chimpoco);
                colorsito (9);
                cout << "Se ha utilizado un boost de ataque!"<<endl;
                colorsito (10);
            } else if (accionAleatoria == 3 && chimpoco [6] > 0) {
                // Activa el boost de defensa
                boostdefensa (chimpoco, enemigo);
                colorsito (9);
                cout << "Se ha utilizado un boost de defensa!"<<endl;
                colorsito (10);
            } else if (accionAleatoria == 0) {
                // Simula un ataque
                int danoMin = chimpoco[1], danoMax = chimpoco[2];
                int danoRealizado = realizarAtaque(chimpoco, danoMin, danoMax);
                enemigo[0] -= danoRealizado;
                cout << nombreChimpoco << " ataca sin control y hace " << danoRealizado << " de dano!" << endl;
            }
            chimpoco [10] = 1;
            system("pause");
        }
    }
}

void pasivaTioMickey(int &danoRealizado, int enemigo[], int chimpoco[], int &rondaEnemigo, bool &tiomickey) {
    if (enemigo[3] == 5){
        if (rondaEnemigo == 0){rondaEnemigo = 1;}
        if (rondaEnemigo % 2 == 0) {
            danoRealizado *= 0.80;
            tiomickey = true;
            cout << "TioMickey se rie con maldad, reduciendo el ataque de tu Chimpoco!" << endl;
        }
    }
}

void coutpasivas (int rondaEnemigo, int enemigo[]){
    colorsito (9);
    if (rondaEnemigo == 3 && enemigo[3] == 1) { cout << "STITCHARD HA ACTIVADO SU PASIVA! SU DANO Y SU VIDA AUMENTO!" << endl; }
    if (rondaEnemigo % 4 == 0 && enemigo[3] == 2) { cout << "FURBYZHOR CANTA UNA CANCION HIPNOTICA, Y HACE QUE PIERDAS TU PROXIMO TURNO!" << endl; }

}


/// POCIONES
int usaritem(int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo) {
    int opcion;
    while (true) {
        opcion = menuitems(chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
        switch (opcion) {
            case 1:  // Boost de ataque
                if (chimpoco[4] > 0) {
                    boostataque(chimpoco);
                    return 1;
                } else {
                    system("cls");
                    cout << "No tienes suficientes boosts de ataque. Reintenta con otro." << endl;
                    system("pause");
                } break;
            case 2:  // Boost de defensa
                if (chimpoco[6] > 0) {
                    boostdefensa(chimpoco, enemigo);
                    return 1;
                } else {
                    system("cls");
                    cout << "No tienes suficientes boosts de defensa. Reintenta con otro." << endl;
                    system("pause");
                } break;
            case 3:  // Poción de vida
                if (chimpoco[8] > 0) {
                    pocionvida(chimpoco);
                    return 1;
                } else {
                    system("cls");
                    cout << "No tienes suficientes pociones de vida. Reintenta con otro." << endl;
                    system("pause");
                } break;
            case 0: //VOLVER
                return 0 ;
            default:
                cout << "Opcion invalida. Reintenta con otra." << endl;
                system("pause");
                system("cls");
                break;
        }
    }
}

// MENU ITEMS
int menuitems(int chimpoco[], int enemigo[], string nombreChimpoco, string nombreEnemigo){
    int opcion ;
    system("cls");
    mostrarVida (chimpoco, enemigo, nombreChimpoco, nombreEnemigo);
    colorsito(5);
    cout << endl;
    cout << char(201) <<"================================================================================" << char(187) <<endl; colorsito (5);
    cout << char (186); colorsito(9); cout << " 1. Boost de ataque: Incrementa tu dano por 30% << CANTIDAD; " << chimpoco [4] << "                  " ; colorsito(5); cout << char(186) << endl;
    cout << char (186); colorsito(9); cout << " 2. Boost de defensa: Reduce el dano recibido un 20% << CANTIDAD; " << chimpoco [6]<< "             " ; colorsito(5); cout << char(186) << endl;
    cout << char (186); colorsito(9); cout << " 3. Pocion de vida: Recupera el 50% de tu vida total << CANTIDAD; " << chimpoco [8] << "             " ; colorsito(5); cout << char(186) << endl;
    cout << char (200) <<"================================================================================" << char(188) << endl << endl;
    colorsito (7);
    cout << "                0. Volver               " << endl << endl;
    colorsito (10);
    cout << "Elige tu accion: ";
    cin >> opcion;
    return opcion;
}

// BOOST ATAQUE
void boostataque (int chimpoco[]){
    chimpoco [4]--;
    chimpoco [5] = chimpoco [5] + 2;
}

// BOOTS DEFENSA
void boostdefensa (int chimpoco[], int enemigo[]){
    chimpoco [6]--;
    chimpoco [7] = 2;
}

// POTI VIDA
void pocionvida (int chimpoco[]){
    chimpoco [8]--;
    chimpoco[0] = chimpoco [0] + (chimpoco [9]/2);
    if (chimpoco [0] > chimpoco [9]){
        chimpoco[0] = chimpoco [9] ;
    }
}


/// MANUAL
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
