#include <string>
#include <iostream>

using namespace std;

#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador {
    public:
        //constructor
        Jugador(){
            nombre="No definido";
            puntaje=0;
            //cout<<"Jugador creado"<<endl;
        }
        
        //destructor
        ~Jugador(){
            //cout<<"Jugador destruido"<<endl;
        }

        //getter y setters
        string getNombre(){
            return nombre;
        }

        int getPuntaje(){
            return puntaje;
        }

        void setNombre(string nombre){
            this->nombre=nombre;
        }

        //otras funciones
        void sumarPuntaje(int puntos){
            puntaje+=puntos;
        }

    private:
        string nombre;
        int puntaje;

};
#endif