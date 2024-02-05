#include <iostream>
#include <string>
#include "Jugador.h"
#include "Juego.h"

using namespace std;

Jugador jugador1, jugador2;
Jugador jugadores[2]={jugador1, jugador2};

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

void crearJugador(Jugador &jugador, int nJugador){
    string nombre;
    bool verificacion=false;
    
    do
    {
        cout << "JUGADOR "<<nJugador;
        cout << "\nIngrese su nombre: ";
        cin >> nombre;
        jugador.setNombre(nombre);

        if (jugador.getNombre() != "No definido")
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
        crearJugador(jugadores[i], i+1);
    }
}

void jugar(){
    Juego juego1;
    juego1.establecerPalabra();
    juego1.definirPista();
    juego1.jugar();
}

void despedida(){
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"   GRACIAS POR PARTICIPAR   "<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    system("PAUSE");
}

int main()
{
    saludo();
    crearJugadores();
    jugar();
    despedida();
    return 0;
}