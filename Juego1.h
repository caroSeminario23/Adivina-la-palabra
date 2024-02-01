#include <iostream>
#include <string>
#include "Juego.h"
#include <stdlib.h>

using namespace std;

#ifndef JUEGO1.H
#define JUEGO1 .H

class Juego1 : Juego
{
public:
    Juego1()
    {
        setNombre("Adivina la palabra");
        nErrores = 0;
    }

    void establecerPalabra()
    {
        string palabra;
        char rpta;
        bool confirmacion;

        do
        {
            cout << "Ingrese la palabra a adivinar: ";
            cin >> palabra;
            cout << "Su palabra es: " << palabra << " ? (S/N)";
            cin >> rpta;

            if (rpta == 'S')
            {
                this->palabra = palabra;
                cout << "Palabra guardada exitósamente" << endl;
                system("clear");
            }else if (rpta == 'N')
            {
                cout<< "Ingrese nuevamente la información";
            }else{
                cout<< "Caracter no reconocido";
            }
            
        } while (rpta != 'S');
    }

private:
    string palabra;
    int nErrores;
};

#endif