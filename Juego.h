#include <iostream>
#include <string>

using namespace std;

#ifndef JUEGO.H
#define JUEGO.H

class Juego{
    public:
        Juego();

        string getNombre(){
            return nombre;
        }

        int getNJugadores(){
            return nJugadores;
        }

    protected:
        string nombre;
        int nJugadores;
    
        void setNombre(string nombre){
            this->nombre=nombre;
        }

        void setNJugadores(int n){
            nJugadores=n;
        }

};

#endif