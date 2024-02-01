#include <iostream>
#include <string>
#include "Jugador.h"

using namespace std;

Jugador jugador1, jugador2;

void saludo();
void crearJugador();
void crearJugadores();
void jugar();
void despedida();

void saludo(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"   BIENVENIDO AL JUEGO 'ADIVINA LA PALABRA'   "<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void crearJugador(Jugador jugador, int nJugador){
    string nombre;
    bool verificacion=false;
    
    do
    {
        cout << "JUGADOR "<<nJugador;
        cout << "\nIngrese su nombre: ";
        cin >> nombre;
        jugador.setNombre(nombre);

        if (jugador1.getNombre() != "No definido")
        {
            cout << "¡Bienvenido " << jugador.getNombre() << "!" << endl;
            verificacion = true;
        }
        else
        {
            cout << "Error en el registro" << endl
                 << "Vuelva a intentarlo" << endl;
        }
    } while (verificacion == false);
}

void crearJugadores(){
    for (int i=0; i<2; i++){
        crearJugador(jugador1, 1);
        crearJugador(jugador2, 2);
    }
}

void jugar(){
    
}

void despedida(){
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"   GRACIAS POR PARTICIPAR   "<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

/*void crearJugadores()
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
            cout << "¡Bienvenido " << jugador1.getNombre() << "!" << endl;
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
            cout << "¡Bienvenido " << jugador2.getNombre() << "!" << endl;
            verificacion2 = true;
        }
        else
        {
            cout << "Error en el registro" << endl
                 << "Vuelva a intentarlo" << endl;
        }
    } while (verificacion2 == false);
}*/

int main()
{
    saludo();
    crearJugadores();
    despedida();
    return 0;
}