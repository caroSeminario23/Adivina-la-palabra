#include <iostream>
#include <string>
#include "Jugador.h"
#include "Juego.h"

using namespace std;

Jugador jugador1, jugador2;
Jugador jugadores[2]={jugador1, jugador2};
string anfitrion, descifrador;

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
        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout << "JUGADOR "<<nJugador;
        cout << "\nIngrese su nombre: ";
        cin >> nombre;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

        jugador.setNombre(nombre);
        cout<<"\nProcesando registro ..."<<endl;

        if (jugador.getNombre() != "No definido")
        {
            cout<<"Registro exitoso"<<endl;
            cout << "\n¡Bienvenido " << jugador.getNombre() << "!" << endl;
            verificacion = true;
        }
        else
        {
            cout << "\nError en el registro" << endl
                 << "Vuelva a intentarlo" << endl;
        }
    } while (verificacion == false);
}

void crearJugadores(){
    cout<<"\nEste juego requiere de 2 jugadores"<<endl;
    cout<<"\n===================================="<<endl;
    cout<<"REGÍSTRESE: "<<endl;
    for (int i=0; i<2; i++){
        crearJugador(jugadores[i], i+1);
    }

    cout << "\nPresiona Enter para continuar...";
    cin.ignore();
    cin.get(); // Espera a que el usuario presione Enter
}

void escogerJugadorAnfitrion(){
    // Inicializa la semilla con el tiempo actual
    srand(static_cast<unsigned>(time(nullptr)));

    // Genera un número aleatorio entre 0 y 1
    double random = static_cast<double>(rand()) / RAND_MAX;

    // Imprime el número aleatorio
    //cout << "Número aleatorio entre 0 y 1: " << random << endl;

    //Jugador seleccionado
    cout<<"El jugador que definirá la palabra es: ";
    if (random==0){
        anfitrion = jugadores[0].getNombre();
        descifrador = jugadores[1].getNombre();
    }else{
        anfitrion=jugadores[1].getNombre();
        descifrador = jugadores[0].getNombre();
    }
    cout<<anfitrion<<endl;
}

void jugar(){
    Juego juego1;

    cout<<"\nIniciemos el juego..."<<endl;

    system("clear");
    cout<<"3"<<endl;
    system("clear");
    cout<<"2"<<endl;
    system("clear");
    cout<<"1"<<endl;

    system("clear");
    cout<<"TURNO DEL JUGADOR "<<anfitrion<<" :"<<endl;
    juego1.establecerPalabra();
    juego1.definirPista();

    system("clear");
    cout<<"TURNO DEL JUGADOR "<<descifrador<<" :"<<endl;
    juego1.jugar();
}

void despedida(){
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"   GRACIAS POR PARTICIPAR   "<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    cout << "Presiona Enter para continuar...";
    cin.ignore();
    cin.get(); // Espera a que el usuario presione Enter
}

int main()
{
    saludo();
    crearJugadores();
    escogerJugadorAnfitrion();
    jugar();
    despedida();
    return 0;
}