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
        setNJugadores(2);
        nErrores = 0;
    }

    void establecerPalabra()
    {
        string palabra;
        bool confirmacion;

        do
        {
            cout << "Ingrese la palabra a adivinar: ";
            cin >> palabra;

            confirmacion = confirmacion("palabra", this->palabra, palabra)

            /*
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
            */

        } while (confirmacion);
    }

    
}

void
definirPista()
{
    string pista;
    bool confirmacion;

    do
    {
        cout << "Escriba una pista que permita adivinar la palabra: ";
        cin >> pista;

        confirmacion = confirmacion("palabra", this->palabra, palabra)
    } while (confirmacion);

    /*
    cout << "Pista: " << pista << endl;

    cout << "Su pista es: " << palabra << " ? (S/N)";
    cin >> rpta;

    if (rpta == 'S')
    {
        this->pista = pista;
        cout << "Pista guardada exitósamente" << endl;
        system("clear");
    }
    else if (rpta == 'N')
    {
        cout << "Ingrese nuevamente la información";
    }
    else
    {
        cout << "Caracter no reconocido";
    }
    */
}

void aumentarError()
{
    cout << "\nHa cometido un error" << endl;
    nErrores++;
    contabilizarErrores();
}

private:
string palabra, pista;
int nErrores;

void contabilizarErrores()
{
    cout << "\nNúmero de errores: " << nErrores << endl;
}

bool confirmacion(string cuestion, string original, string verificando)
    {
        cout << "¿Su " << cuestion << " es: " << palabra << " ? (S/N)";
        cin >> rpta;

        if (rpta == 'S')
        {
            original = verificando;
            cout << "Guardado exitoso" << endl;
            system("clear");
            return true;
        }
        else if (rpta == 'N')
        {
            cout << "Ingrese nuevamente la información";
            return false;
        }
        else
        {
            cout << "Caracter no reconocido";
            return false;
        }
    }

}
;

#endif