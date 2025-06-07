
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
#include <vector>
#include "funciones.cpp"
#include "vectores.h"

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
    const int TAM = 6;
int dadosStockJ1[TAM] = {};
int dadosStockJ2[TAM] = {}; // El corchete pone todos los elementos (los de 6) en 0

    int opcion;
    bool finalizar = false;

    /*
        1- Mientras sea diferente a finalizar se mostrara el menu con las opciones.
        2- Se usa un switch como condicional para que se ejecute la opcion ingresada por el usuario.
        3- A medida de que el juego sea desarrollado se debera ir modificando el menu de iociones.
    */
    while (!finalizar)
    {
        rlutil::cls();
        opcion = menuOpciones();

        switch (opcion)
        {
        case 0:
            cout << " Saliste del juego " << endl;
            finalizar = true;
            break;

        case 1:
            rlutil::cls();
                        
            cout << " Comenzará el juego " << endl;
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
                    jugarPartida(nombreJugador1, nombreJugador2, dadosStockJ1, dadosStockJ2, puntajeJugador1, puntajeJugador2);
                    
                } else {
                    cout << nombreJugador2 << " empieza el juego." << endl;
                    jugarPartida(nombreJugador2, nombreJugador1, dadosStockJ1, dadosStockJ2, puntajeJugador1, puntajeJugador2);
                    
                }
                rlutil::msleep(2000); 
                rlutil::cls();
                ;
                break;

        case 2:
            cout << " Se mostraran las estadisticas del juego " << endl;
            rlutil::cls();
            break;

        case 3:
            creditos();
            rlutil::cls();
            break;

        case 4:
            reglamento();
            rlutil::cls();
            break;

        
        
        }
    }

    int decidirQuienEmpieza();


    return 0;
}

