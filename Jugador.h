#include <string>
#include <iostream>

using namespace std;

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador {
    public:
        Jugador();
        void definirNombre(){
            cout<<"Ingrese su nombre: ";
            cin>>nombre;
            cout<<"Nombre: "<<nombre;
        };
    private:
        string nombre;
        int puntaje;

};
#endif