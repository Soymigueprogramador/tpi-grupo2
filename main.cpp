
#include <iostream>
#include <cstring>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
#include "funciones.cpp"
using namespace std;

// Funcion para mostrar el menu.
int menuOpciones();


int main()
{
    //Declaro estructura para jugadores
    Jugadores jugadores[2];

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
                cin >> jugadores[0].nombre;
                cout << "Ingrese nombre del jugador 2: ";
                cin >> jugadores[1].nombre;

                        // Decidir qui�n empieza
                int quienEmpieza;
                quienEmpieza = decidirQuienEmpieza(jugadores);

                cout << "Comienza el jugador: " << jugadores[quienEmpieza].nombre << endl;

                system("pause");
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

