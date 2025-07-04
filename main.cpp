
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



int main()
{
    srand(time(0)); // Inicializa la semilla para los nímeros aleatorios.
    //Declaro estructura para jugadores
    SetConsoleOutputCP(65001); //Muestra todo en UTF-8, así se ven bien los tildes, la ñ y los caracteres especiales
    mostrarPortada();

    string nombreJugador1, nombreJugador2;
    int puntajeJugador1 = 0, puntajeJugador2 = 0;
   // " 70" es La cantidad de dados de todos los jugadores, que es 250, pero no se usa todo normalmente por eso el numero grande
    int dadosStockJ1[70] = {};
    int dadosStockJ2[70] = {}; // El corchete pone todos los elementos (los de 6) en 0
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
    char opcionSalir; // caracter
    while (!finalizar)
    {

        rlutil::cls();
        opcion = menuOpciones();

        switch (opcion)
        {
        case 0:
                        cout << "¿ESstás seguro de salir del juego? S/N" << endl;
            cin >> opcionSalir;

            while (opcionSalir != 's' && opcionSalir != 'S' && opcionSalir != 'n' && opcionSalir != 'N') {
                cout << "Entrada inválida. Debe ser S o N." << endl;
                cin.clear();
                cin.ignore();
                rlutil::msleep(1000);
                rlutil::cls();
                cout << "¿Estás seguro de salir del juego? S/N" << endl;
                cin >> opcionSalir;
            }

            switch (opcionSalir) {
                case 's':
                case 'S':
                    cout << "Saliste del juego." << endl;
                    finalizar = true;
                    break;

                case 'n':
                case 'N':
                    rlutil::cls();
                    break;
            }

break;
        case 1:
            rlutil::cls();

            cout << " Comenzará el juego " << endl;
                        // Pedir nombres
                cin.ignore(); // Limpia el buffer
                cout << "Ingrese nombre del jugador 1: ";
                getline(cin, nombreJugador1);
                cout << "Ingrese nombre del jugador 2: ";
                getline(cin, nombreJugador2);
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
                mostrarMensajeYEsperar();
                // llama a la funcion orientada al primer jugador
                jugarPartida(nombreJugador1, nombreJugador2, dadosStockJ1, dadosStockJ2, cantDadosJ1, cantDadosJ2, puntajeJugador1, puntajeJugador2);
            } else {
                cout << nombreJugador2 << " empieza el juego." << endl;
                mostrarMensajeYEsperar();
                jugarPartida(nombreJugador2, nombreJugador1, dadosStockJ2, dadosStockJ1, cantDadosJ2, cantDadosJ1, puntajeJugador2, puntajeJugador1);
                // llama a la funcion orientada al segundo jugador
            }


        // termina la partida, y lo siguiente es calcular el puntaje para ver quién ganó




                rlutil::msleep(2000);
                if (puntajeJugador1 > puntajeJugador2) { // Si tiene mas puntaje el jugador que empezó
                if (puntajeJugador1 > maxPuntajeHistorico) { // Si tiene mas puntaje que el maximo historico, que empieza con 0
                maxPuntajeHistorico = puntajeJugador1; // Se le da ese titulo al que empezó
                nombreMejorJugadorHistorico = nombreJugador1; // y el nombre tambien
                cout << "RECORD HISTÓRICO EN LA SESIÓN: " << nombreMejorJugadorHistorico << " con " << maxPuntajeHistorico << " puntos." << endl;
                rlutil::msleep(2000);
                rlutil::cls();
                } } else // Si no se cumple el primer if, quiere decir que tiene más (o empate, que se verifica despues) el jugador 2
                if (puntajeJugador2 > maxPuntajeHistorico) { // lo mismo que para el jugador 1 si se gana
                maxPuntajeHistorico = puntajeJugador2;
                nombreMejorJugadorHistorico = nombreJugador2;
                cout << "RECORD HISTÓRICO EN LA SESIÓN: " << nombreMejorJugadorHistorico << " con " << maxPuntajeHistorico << " puntos." << endl;
                rlutil::msleep(2000);
                rlutil::cls();
                }



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
                } else { // si ni j1 ni j2 tienen mas puntaje que el otro, quiere decir empate
                    cout << "¡La partida ha terminado en empate!" << endl;
                }
                cout << "==========================================" << endl;
                mostrarMensajeYEsperar;
                break;

                case 2:
                estadisticasDelJuego(nombreJugador1, nombreJugador2, puntajeJugador1, puntajeJugador2, cantDadosJ1, cantDadosJ2, nombreMejorJugadorHistorico, maxPuntajeHistorico, partidaJugada);
                mostrarMensajeYEsperar;
                break;

                case 3:
                    creditos();

                    break;

                case 4:
                    reglamento();

                    break;



        }
    }



    return 0;
}

