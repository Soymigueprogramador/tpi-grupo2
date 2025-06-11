
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
#include <vector>
#include "vectores.h"
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
    mostrarPantallaInicio();

    string nombreJugador1, nombreJugador2;
    int puntajeJugador1 = 0, puntajeJugador2 = 0;
    const int TAM = 250; // La cantidad de dados de todos los jugadores, que es 250, pero no se usa todo normalmente por eso el numero grande
    int dadosStockJ1[TAM] = {};
    int dadosStockJ2[TAM] = {}; // El corchete pone todos los elementos (los de 6) en 0
    int cantDadosJ1 = 6; // Cantidad de dados que tiene cada jugador (se empieza con 6, pero va cambiando)
    int cantDadosJ2 = 6;

    // Lo de arriba parece ser lo mismo, pero dadosStock guarda QUÉ dados tiene, y cantDados guarda CUÁNTOS dados tiene cada jugador.
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
                puntajeJugador1 = 0;
                puntajeJugador2 = 0;
                cantDadosJ1 = 6;
                cantDadosJ2 = 6;
                // Son todos reinicios de variables para cada vez que se inicia la partida

                if (quienEmpieza == 0) {
                    cout << nombreJugador1 << " empieza el juego." << endl;
                    jugarPartida(nombreJugador1, nombreJugador2, dadosStockJ1, dadosStockJ2, cantDadosJ1, cantDadosJ2, puntajeJugador1, puntajeJugador2);

                } else {
                    cout << nombreJugador2 << " empieza el juego." << endl;
                    jugarPartida(nombreJugador2, nombreJugador1, dadosStockJ1, dadosStockJ2, cantDadosJ1, cantDadosJ2, puntajeJugador1, puntajeJugador2);

                }
                rlutil::msleep(2000);
                rlutil::cls();

                // Acá podemos hacer el if de si la cantidad de dados es 0, gana el que no tiene dados y tambien se muestra todo el puntaje final y eso
                ;
                break;

        case 2:
            cout << " Se mostraran las estadisticas del juego " << endl;
            rlutil::anykey();  // Espera a que el usuario lea el contenido
            rlutil::cls();     // Recién ahora limpia
            break;

        case 3:
            creditos();
            rlutil::anykey();
            rlutil::cls();
            break;

        case 4:
            reglamento();
            rlutil::anykey();
            rlutil::cls();
            break;



        }
    }

    int decidirQuienEmpieza();


    return 0;
}

