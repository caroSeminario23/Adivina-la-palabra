#include <iostream>
#include <string>

using namespace std;

#ifndef JUEGO_H
#define JUEGO_H

class Juego
{
public:
    Juego()
    {
        nErrores = 0;
        cout << "Juego creado" << endl;
    }

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
            cout << "\nIngrese la palabra a adivinar: ";
            cin >> palabra;

            verificacion = confirmacion("palabra", this->palabra, palabra);
        } while (verificacion==false);
    }

    void definirPista()
    {
        string pista;
        bool verificacion;

        do
        {
            cout << "\nEscriba una pista que permita adivinar la palabra: ";
            cin.ignore();
            getline(cin, pista);
            //cin >> pista;

            verificacion = confirmacion("pista", this->pista, pista);
        } while (verificacion==false);
    }

    void jugar()
    {
        solicitarLetra();
        decisionFinal();
    }

private:
    string palabra, pista;
    int nErrores, *arregloPos, encontrados;
    char *completando;

    bool confirmacion(string cuestion, string &original, string verificando)
    {
        char rpta;
        cout << "¿Su " << cuestion << " es: " << verificando << "? (S/N)" << endl;
        cout << "Respuesta: ";
        cin >> rpta;

        if ((rpta == 'S')||(rpta =='s'))
        {
            original = verificando;
            cout << "\nGuardado exitoso" << endl;
            system("clear");
            return true;
        }
        else if ((rpta == 'N') || (rpta == 'n'))
        {
            cout << "\nIngrese nuevamente la información";
            return false;
        }
        else
        {
            cout << "\nCaracter no reconocido";
            return false;
        }
    }

    void crearArregloDeVerificacion()
    {
        int nPalabras;
        nPalabras = palabra.size();

        completando = new char[nPalabras];

        for (int i = 0; i < nPalabras; i++)
        {
            completando[i] = '-';
        }
    }

    void crearArregloPosiciones()
    {
        int nPalabras;

        nPalabras = palabra.size();
        arregloPos = new int[nPalabras];

        for (int i = 0; i < nPalabras; i++)
        {
            arregloPos[i] = i;
        }
    }

    void aumentarError()
    {
        cout << "\nHa cometido un error" << endl;
        nErrores++;
    }

    void contabilizarErrores()
    {
        cout << "\nNúmero de errores: " << nErrores << endl;
    };

    bool buscarLetra(char letra)
    {
        bool verificador;
        int acertados = 0;

        for (int i = 0; i < sizeof(arregloPos); i++)
        {
            if (palabra[arregloPos[i]] == letra)
            {
                completando[arregloPos[i]] = letra;
                arregloPos[i] = palabra.size() + 1;
                encontrados++;
                acertados++;
            }
        }

        if (acertados == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void reducirArregloPos(int tamaño, int encontrados)
    {
        int *arregloPos2 = new int[palabra.size() - encontrados];

        for (int i = 0; i < sizeof(arregloPos); i++)
        {
            int m = 0;
            if (arregloPos[i] != (palabra.size() + 1))
            {
                arregloPos2[m] = arregloPos[i];
                m++;
            }
        }

        arregloPos = arregloPos2;
    }

    void decisionFinal()
    {
        if (nErrores == 3 && (palabra.size() > encontrados))
        {
            cout << "------------------" << endl;
            cout << "   GAME OVER :(   " << endl;
            cout << "------------------" << endl;
        }
        else
        {
            cout << "------------------" << endl;
            cout << "    ¡VICTORIA!    " << endl;
            cout << "------------------" << endl;
        }
    }

    void solicitarLetra()
    {
        char letra;
        bool encontrada;

        while (nErrores < 3 && (palabra.size() > encontrados))
        {
            cout << "Escriba la letra que cree está contenida en la palabra: ";
            cin >> letra;

            encontrada = buscarLetra(letra);

            if (encontrada)
            {
                reducirArregloPos(palabra.size(), encontrados);
            }
            else
            {
                aumentarError();
                contabilizarErrores();
            }
        }
    }
};

#endif