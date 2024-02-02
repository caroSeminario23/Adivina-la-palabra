#include <iostream>
#include <string>

using namespace std;

#ifndef JUEGO.H
#define JUEGO .H

class Juego
{
public:
    Juego()
    {
        nErrores = 0;
        cout << "Juego creado" << endl;
    };

    ~Juego()
    {
        cout << "Juego destruido" << endl;
    }

    void establecerPalabra()
    {
        string palabra;
        bool verificacion;

        do
        {
            cout << "Ingrese la palabra a adivinar: ";
            cin >> palabra;
            cout << "Palabra: " << palabra;

            verificacion = confirmacion("palabra", this->palabra, palabra);
        } while (confirmacion);
    }

    void
    definirPista()
    {
        string pista;
        bool verificacion;

        do
        {
            cout << "Escriba una pista que permita adivinar la palabra: ";
            cin >> pista;

            verificacion = confirmacion("pista", this->pista, pista);
        } while (confirmacion);
    }

    void aumentarError()
    {
        cout << "\nHa cometido un error" << endl;
        nErrores++;
        contabilizarErrores();
    }

    void solicitarLetra(){
        char letra;

        cout<<"Escriba la letra que cree está contenida en la palabra: ";
        cin>>letra;

        buscarLetra(letra);
    }

private:
    string palabra, pista;
    int nErrores, *arregloPos;
    char *completando;

    bool confirmacion(string cuestion, string original, string verificando)
    {
        char rpta;
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

    void crearArregloDeVerificacion()
    {
        int nPalabras;
        nPalabras = palabra.size();

        completando = new char[nPalabras];

        for(int i=0; i<nPalabras; i++){
            completando[i]='-';
        }
    }

    void crearArregloPosiciones(){
        int nPalabras;

        nPalabras = palabra.size();
        arregloPos = new int[nPalabras];

        for(int i=0; i<nPalabras; i++){
            arregloPos[i]=i;
        }
    }

    void contabilizarErrores()
    {
        cout << "\nNúmero de errores: " << nErrores << endl;
    };

    void buscarLetra(char letra)
    {
       for (int i=0; i<sizeof(arregloPos); i++){
        if (palabra[arregloPos[i]]==letra){
            completando[arregloPos[i]] = letra;
        }
       }
    }

    void reducirArregloPos(int tamaño){

    }
};

#endif