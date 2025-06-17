
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
#include "vectores.h"
#include "funciones.cpp"
#include <windows.h>
using namespace std;


// Funcion para mostrar el menu.
int menuOpciones();

// Funcion para crear los dados de 12 caras.
int dadoDoceCaras();


int main()
{
    srand(time(0)); // Inicializa la semilla para los n��meros aleatorios.
    //Declaro estructura para jugadores
    SetConsoleOutputCP(65001); //Muestra todo en UTF-8, así se ven bien los tildes, la ñ y los caracteres especiales
    mostrarPortada();

    string nombreJugador1, nombreJugador2;
    int puntajeJugador1 = 0, puntajeJugador2 = 0;
    int TAM = 250; // La cantidad de dados de todos los jugadores, que es 250, pero no se usa todo normalmente por eso el numero grande
    int dadosStockJ1[TAM] = {};
    int dadosStockJ2[TAM] = {}; // El corchete pone todos los elementos (los de 6) en 0
    int cantDadosJ1 = 6; // Cantidad de dados que tiene cada jugador (se empieza con 6, pero va cambiando)
    int cantDadosJ2 = 6;
    bool partidaJugada = false; // Para que no se muestre una estadistica nula

    // Lo de arriba parece ser lo mismo, pero dadosStock guarda QUÉ dados tiene, y cantDados guarda CUÁNTOS dados tiene cada jugador.
    int opcion;

    bool finalizar = false;

    /*
        1- Mientras sea diferente a finalizar se mostrara el menu con las opciones.
        2- Se usa un switch como condicional para que se ejecute la opcion ingresada por el usuario.
        3- A medida de que el juego sea desarrollado se debera ir modificando el menu de iociones.
    */
   string nombreMejorJugadorHistorico = "Nadie";
    int maxPuntajeHistorico = 0;
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
                if (partidaJugada == false) { // Solo la activamos una vez para indicar que al menos una partida se jugó
                partidaJugada = true;
                }

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
                if (puntajeJugador1 > maxPuntajeHistorico) {
                maxPuntajeHistorico = puntajeJugador1;
                nombreMejorJugadorHistorico = nombreJugador1;
                }
                if (puntajeJugador2 > maxPuntajeHistorico) { // Usamos 'if' y no 'else if' para contemplar que el jugador 2 pueda superar al jugador 1 si es que el jugador 1 no supero el puntaje historico antes.
                maxPuntajeHistorico = puntajeJugador2;
                nombreMejorJugadorHistorico = nombreJugador2;
                }

                cout << "RECORD HISTÓRICO EN LA SESIÓN: " << nombreMejorJugadorHistorico << " con " << maxPuntajeHistorico << " puntos." << endl;
                rlutil::anykey();
                break;
                rlutil::cls();

                // Acá podemos hacer que se muestra todo el puntaje final y eso
                // Después de la llamada a jugarPartida() y la actualización de estadísticas
                cout << "============ FIN DE LA PARTIDA ============" << endl;
                cout << "Puntaje final de " << nombreJugador1 << ": " << puntajeJugador1 << endl;
                cout << "Puntaje final de " << nombreJugador2 << ": " << puntajeJugador2 << endl;
                cout << "------------------------------------------" << endl;

                if (puntajeJugador1 > puntajeJugador2) {
                    cout << "¡El ganador es " << nombreJugador1 << "!" << endl;
                } else if (puntajeJugador2 > puntajeJugador1) {
                    cout << "¡El ganador es " << nombreJugador2 << "!" << endl;
                } else {
                    cout << "¡La partida ha terminado en empate!" << endl;
                }
                cout << "==========================================" << endl;
                rlutil::anykey();
                break;

                case 2:
                estadisticasDelJuego(nombreJugador1, nombreJugador2, puntajeJugador1, puntajeJugador2, cantDadosJ1, cantDadosJ2, nombreMejorJugadorHistorico, maxPuntajeHistorico, partidaJugada);
                rlutil::anykey(); 
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

    int decidirQuienEmpieza(); // s


    return 0;
}

