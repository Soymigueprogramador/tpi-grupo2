
#include <iostream>
#include <cstring>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
#include "funciones.cpp"
using namespace std;


// Funcion para mostrar el menu.
int menuOpciones();

// Funcion para crear los dados de 12 caras.
int dadoDoceCaras();


int main()
{
    srand(time(0)); // Inicializa la semilla para los n��meros aleatorios.
    //Declaro estructura para jugadores

    string nombreJugador1, nombreJugador2;
    int puntajeJugador1 = 0, puntajeJugador2 = 0;
    int dadosStockJugador1 = 6, dadosStockJugador2 = 6;

    int opcion;
    bool finalizar = false;

    /*
        1- Mientras sea diferente a finalizar se mostrara el menu con las opciones.
        2- Se usa un switch como condicional para que se ejecute la opcion ingresada por el usuario.
        3- A medida de que el juego sea desarrollado se debera ir modificando el menu de iociones.
    */
    while (!finalizar)
    {
        system("cls");
        opcion = menuOpciones();

        switch (opcion)
        {
        case 0:
            cout << " Saliste del juego " << endl;
            finalizar = true;
            break;

        case 1:
            cout << " Comenzara el juego " << endl;
                        // Pedir nombres
                cout << "Ingrese nombre del jugador 1: ";
                cin >> nombreJugador1;
                cout << "Ingrese nombre del jugador 2: ";
                cin >> nombreJugador2;

                        // Decidir quién empieza
                int quienEmpieza;
                quienEmpieza = decidirQuienEmpieza(nombreJugador1, nombreJugador2);

                if (quienEmpieza == 0) {
                    cout << nombreJugador1 << " empieza el juego." << endl;
                } else {
                    cout << nombreJugador2 << " empieza el juego." << endl;
                }


                system("pause");
                tirarDados();
                break;

        case 2:
            cout << " Se mostraran las estadisticas del juego " << endl;
            system(" pause ");
            break;

        case 3:
            creditos();
            system("pause");
            break;

        case 4:
            reglamento();
            system("pause");
            break;

        
        
        }
    }

    int decidirQuienEmpieza();


    return 0;
}

