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
        //cout << "Juego creado" << endl;
    }

    ~Juego()
    {
        //cout << "Juego destruido" << endl;
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
        crearArregloDeVerificacion();
        //mostrarArregloDeVerificacion();
        crearArregloPosiciones();
        solicitarLetra();
        decisionFinal();
    }

private:
    string palabra, pista;
    int nErrores, *arregloPos, nLetrasAPos, encontrados=0;
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
            //system("clear");
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
        //cout<<"Creando arreglo de verificación"<<endl;
        int nPalabras;
        //cout<<"Palabra: "<<palabra<<endl;
        nPalabras = palabra.size();
        //cout<<"N de palabras: "<<nPalabras<<endl;

        completando = new char[nPalabras];
        //cout<<"Tamaño de arreglo: "<<sizeof(completando)<<endl;

        for (int i = 0; i < nPalabras; i++)
        {
            completando[i] = '-';
        }

        //cout<<"Prueba de arreglo: "<<completando[2]<<endl;
        //cout<<"Tamaño de arreglo: "<<nPalabras<<endl;
        /*for (int i = 0; i < nPalabras; i++)
        {
            cout<<completando[i];
        }*/
    }

    void mostrarArregloDeVerificacion(){
        cout<<"/n"<<endl;
        cout<<"/nProgreso:"<<endl;
        for (int i = 0; i < palabra.size(); i++)
        {
            cout<<completando[i];
        }
    }

    void crearArregloPosiciones()
    {
        //cout<<"\nCreando arreglo de posiciones"<<endl;
        int nPalabras;

        nPalabras = palabra.size();
        //cout<<"N de letras: "<<nPalabras<<endl;
        arregloPos = new int[nPalabras];
        nLetrasAPos = nPalabras;
        //cout<<"N de letras 2: "<<nLetrasAPos<<endl;

        for (int i = 0; i < nLetrasAPos; i++)
        {
            arregloPos[i] = i;
        }

        //cout<<"Posicion: "<<arregloPos[2]<<endl;
        //cout<<"Tamaño de arregloPos: "<<nLetrasAPos<<endl;
        /*for (int i = 0; i < nLetrasAPos; i++)
        {
            cout<<arregloPos[i];
        }*/
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
        cout<<"Buscando la letra..."<<endl;
        bool verificador;
        int acertados = 0;

        //cout<<"Tamaño del arreglo de posiciones: "<<nLetrasAPos<<endl;

        for (int i = 0; i < nLetrasAPos; i++)
        {
            //cout<<"Letra: "<<palabra[arregloPos[i]]<<endl;
            if (palabra[arregloPos[i]] == letra)
            {
                completando[arregloPos[i]] = letra;
                arregloPos[i] = palabra.size() + 1;
                encontrados++;
                acertados++;
            }
        }

        cout<<"N° de certados: "<<acertados<<endl;
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
        //cout<<"Reduciendo arreglo de posiciones"<<endl;
        int *arregloPos2 = new int[palabra.size() - encontrados];

        int marcados = 0;
        int m = 0;

        for (int i = 0; i < nLetrasAPos; i++)
        {
            if (arregloPos[i] != (palabra.size() + 1))
            {
                arregloPos2[m] = arregloPos[i];
                m++;
            }else{
                marcados++;
            }
        }

        arregloPos = arregloPos2;
        nLetrasAPos = nLetrasAPos-marcados;

        //cout<<"n marcados: "<<marcados<<endl;
        //cout<<"n letras en arreglo de pos: "<<nLetrasAPos<<endl;
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
        cout<<"\nSolicitud de letras"<<endl;
        cout<<"N de errores: "<<nErrores<<endl;
        cout<<"Tamaño de la palabra: "<<palabra.size()<<endl;
        cout<<"Letras encontradas: "<<encontrados<<endl;

        mostrarArregloDeVerificacion();

        char letra;
        bool encontrada;

        while (nErrores < 3 && (palabra.size() > encontrados))
        {
            cout << "\nEscriba la letra que cree está contenida en la palabra: ";
            cin >> letra;

            encontrada = buscarLetra(letra);
            //cout<<"Se encontró? "<<encontrada<<endl;
            cout<<"¿Se encontró? ";

            if (encontrada)
            {
                cout<<"Sí"<<endl;
                reducirArregloPos(palabra.size(), encontrados);
                
            }
            else
            {
                cout<<"No"<<endl;
                aumentarError();
                contabilizarErrores();
                
            }
            mostrarArregloDeVerificacion();
        }
    }
};

#endif