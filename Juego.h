#include <iostream>
#include <string>

using namespace std;

#ifndef JUEGO.H
#define JUEGO.H

class Juego{
    public:
        Juego(){
            nErrores=0;
            cout<<"Juego creado"<<endl;
        };

        ~Juego(){
            cout<<"Juego destruido"<<endl;
        }

    void establecerPalabra()
    {
        string palabra;
        bool confirmacion;

        do
        {
            cout << "Ingrese la palabra a adivinar: ";
            cin >> palabra;
            cout << "Palabra: " << palabra;

            confirmacion = confirmacion("palabra", this->palabra, palabra);
        } while (confirmacion);
    }

    private:
        string palabra, pista;
        int nErrores;
        char *completando;
    
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
    

};

#endif