#include <iostream>
#include <string>
#include "Jugador.h"
#include "Juego.h"

using namespace std;

Jugador jugador1, jugador2;
Jugador jugadores[2] = {jugador1, jugador2};
string anfitrion, descifrador;
int opcionJuego;

void saludo();
void crearJugador();
void crearJugadores();
void jugar();
void despedida();

void saludo()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   BIENVENIDO AL JUEGO 'ADIVINA LA PALABRA'   " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void crearJugador(Jugador &jugador, int nJugador)
{
    string nombre;
    bool verificacion = false;

    do
    {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "JUGADOR " << nJugador;
        cout << "\nIngrese su nombre: ";
        cin >> nombre;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        jugador.setNombre(nombre);
        cout << "\nProcesando registro ..." << endl;

        if (jugador.getNombre() != "No definido")
        {
            cout << "Registro exitoso" << endl;
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

void crearJugadores()
{
    cout << "\nEste juego requiere de 2 jugadores" << endl;
    cout << "\n====================================" << endl;
    cout << "REGÍSTRESE: " << endl;
    for (int i = 0; i < 2; i++)
    {
        crearJugador(jugadores[i], i + 1);
    }

    cout << "\nPresiona Enter para continuar...";
    cin.ignore();
    cin.get(); // Espera a que el usuario presione Enter
}

void escogerJugadorAnfitrion()
{
    // Inicializa la semilla con el tiempo actual
    srand(static_cast<unsigned>(time(nullptr)));

    // Genera un número aleatorio entre 0 y 1
    double random = static_cast<double>(rand()) / RAND_MAX;

    // Imprime el número aleatorio
    // cout << "Número aleatorio entre 0 y 1: " << random << endl;

    // Jugador seleccionado
    cout << "El jugador que definirá la palabra es: ";
    if (random == 0)
    {
        anfitrion = jugadores[0].getNombre();
        descifrador = jugadores[1].getNombre();
    }
    else
    {
        anfitrion = jugadores[1].getNombre();
        descifrador = jugadores[0].getNombre();
    }
    cout << anfitrion << endl;
}

void conteo()
{
    cout << "\nIniciemos el juego..." << endl;

    system("clear");
    cout << "3" << endl;
    system("clear");
    cout << "2" << endl;
    system("clear");
    cout << "1" << endl;
}

void jugarOpcion1()
{
    Juego juego1;

    system("clear");
    cout << "TURNO DEL JUGADOR " << anfitrion << ":" << endl;
    juego1.establecerPalabra();
    juego1.definirPista();

    system("clear");
    cout << "TURNO DEL JUGADOR " << descifrador << ":" << endl;
    juego1.jugar(jugadores[0], jugadores[1]);
}

void jugarOpcion2()
{
    Juego juego1;

    for (int i = 0; i < 3; i++)
    {
        system("clear");
        cout<<"TANDA "<<i+1<<":"<<endl;
        cout << "TURNO DEL JUGADOR " << jugadores[0].getNombre() << ":" << endl;
        juego1.establecerPalabra();
        juego1.definirPista();

        system("clear");
        cout << "TURNO DEL JUGADOR " << jugadores[1].getNombre() << ":" << endl;
        juego1.jugar(jugadores[1], jugadores[0]);

        cout << "Presiona Enter para continuar...";
        cin.ignore();
        cin.get(); // Espera a que el usuario presione Enter

        system("clear");
        cout << "TURNO DEL JUGADOR " << jugadores[1].getNombre() << ":" << endl;
        juego1.establecerPalabra();
        juego1.definirPista();

        system("clear");
        cout << "TURNO DEL JUGADOR " << jugadores[0].getNombre() << ":" << endl;
        juego1.jugar(jugadores[0], jugadores[1]);

        cout << "Presiona Enter para continuar...";
        cin.ignore();
        cin.get(); // Espera a que el usuario presione Enter
    }
}

void despedida()
{
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   GRACIAS POR PARTICIPAR   " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "Presiona Enter para continuar...";
    cin.ignore();
    cin.get(); // Espera a que el usuario presione Enter
}

void menu()
{

    cout << "\nSELECCIONE UN MODO DE JUEGO" << endl;
    cout << "1. Solo una partida" << endl;
    cout << "2. Versus de 3 partidas" << endl;
}

void modoJuego1()
{
    cout << "\nMODO DE JUEGO: SOLO UNA PARTIDA";
    escogerJugadorAnfitrion();
    jugarOpcion1();
}

void mostrarPuntajes()
{
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "PUNTAJES:" << endl;
    cout << "Jugador " << jugadores[0].getNombre() << ": " << jugadores[0].getPuntaje() << endl;
    cout << "Jugador " << jugadores[1].getNombre() << ": " << jugadores[1].getPuntaje() << endl;
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void modoJuego2()
{
    cout << "\nMODO DE JUEGO: VERSUS DE 3 PARTIDAS" << endl;
    jugarOpcion2();
    mostrarPuntajes();
}

int validarOpcion()
{
    int opcion;

    do
    {
        cout << "\nDigite su opción: ";
        cin >> opcion;
    } while (opcion != 1 && opcion != 2);

    return opcion;
}

void seleccionarModoDeJuego(int opcion)
{
    switch (opcion)
    {
    case 1:
        modoJuego1();
        break;

    case 2:
        modoJuego2();
        break;
    }
}

int main()
{
    saludo();
    crearJugadores();
    menu();
    opcionJuego = validarOpcion();
    seleccionarModoDeJuego(opcionJuego);
    despedida();
    return 0;
}