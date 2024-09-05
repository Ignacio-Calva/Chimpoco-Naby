#include <iostream>
#include "funciones.h"
using namespace std;

//MENU PRINCIPAL
void menuPrincipal (){
    int opcion = 1;
    while (opcion !=0){
        mostrarMenu();
        cin>>opcion;
        switch (opcion) {
        case 1:
            modoAventura ();
        case 2:
            modoVersus ();
        case 3:
            godMode ();
        case 4:
            estadisticas ();
        case 5:
            manual ();
        case 0:
            cout<<"Saliedo del programa..."<<endl;
        default:
            cout<<"Ingrese una opcion correcta."<<endl;
            system ("pause");
            break;

}}}

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
}

void modoAventura() {

}

void modoVersus (){

}

void godMode() {

}

void estadisticas() {

}

void manual () {

}
