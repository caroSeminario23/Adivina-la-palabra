#include <iostream>
#include <string>
#include "Jugador.h"

using namespace std;

Jugador jugador1, jugador2;

void crearJugadores();

void crearJugadores()
{
    string nombre;
    bool verificacion1 = false, verificacion2 = false;

    cout << "---------------------------" << endl;
    cout << "-- REGISTRO DE JUGADORES --" << endl;
    cout << "---------------------------" << endl
         << endl;

    // REGISTRO DE JUGADOR 1
    do
    {
        cout << "JUGADOR 1";
        cout << "\nIngrese su nombre: ";
        cin >> nombre;
        jugador1.setNombre(nombre);

        if (jugador1.getNombre() != "No definido")
        {
            cout << "¡Bienvenido " << jugador1.getNombre() << " !" << endl;
            verificacion1 = true;
        }
        else
        {
            cout << "Error en el registro" << endl
                 << "Vuelva a intentarlo" << endl;
        }
    } while (verificacion1 == false);


    // REGISTRO DE JUGADOR 2
    do
    {
        cout << "JUGADOR 2";
        cout << "\nIngrese su nombre: ";
        cin >> nombre;
        jugador2.setNombre(nombre);

        if (jugador2.getNombre() != "No definido")
        {
            cout << "¡Bienvenido " << jugador2.getNombre() << " !" << endl;
            verificacion2 = true;
        }
        else
        {
            cout << "Error en el registro" << endl
                 << "Vuelva a intentarlo" << endl;
        }
    } while (verificacion2 == false);
}

int main()
{
    cout << "ADIVINA LA PALABRA" <<endl;
    crearJugadores();
    return 0;
}