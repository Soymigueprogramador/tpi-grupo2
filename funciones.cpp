#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
#include <string>
#include "vectores.h"
using namespace std;

void tirarDados(int dados[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        dados[i] = (rand() % 6) + 1;
    }
}

void mostrarMensajeYEsperar(string mensaje = "Presione cualquier tecla para continuar...")
{
    cout << mensaje << endl;
    rlutil::msleep(1000);
    rlutil::anykey();
}

void jugarPartida(string jugadorInicial, string jugadorOponente, int dadosInicial[], int dadosOponente[], int &cantDadosInicial, int &cantDadosOponente, int &puntosInicial, int &puntosOponente)
{
    for (int ronda = 1; ronda <= 3; ronda++)
    { // Itera 3 rondas
        rlutil::cls();
        mostrarEstadoDeRonda(ronda, jugadorInicial, jugadorOponente, puntosInicial, puntosOponente, cantDadosInicial, cantDadosOponente);
        rlutil::msleep(2000);
        rlutil::cls();

        // Turno del jugador inicial
        if (realizarTurno(jugadorInicial, jugadorOponente, dadosInicial, dadosOponente, cantDadosInicial, cantDadosOponente, puntosInicial) == true)
        {
            return; // Primero se realiza el turno del jugador que empieza. Para ello, se hace un if. Este if, además de corroborar si es true o false, va a ejecutar la función. Es decir, hace: "Si.. *ejecuta y muestra la función* es true... entonces
        } // termina inmediatamente la función y vuelve al main.cpp

        // Turno del jugador oponente
        if (realizarTurno(jugadorOponente, jugadorInicial, dadosOponente, dadosInicial, cantDadosOponente, cantDadosInicial, puntosOponente) == true)
        {
            return; // Si es falso y nadie ha ganado la partida, se sigue con esta linea para el turno del oponente

            // Cuando termina de leer esos dos if, simulando los turnos, como es un for "va" hacia la segunda ronda y se repite lo mismo
        }
    }
}

bool realizarTurno(string jugadorActual, string oponente, int dadosActual[], int dadosOponente[], int &cantDadosActual, int &cantDadosOponente, int &puntosActual)
{
    rlutil::cls();
    cout << "Turno de " << jugadorActual << endl;
    cout << jugadorActual << " tira el dado de 12 caras..." << endl;
    rlutil::msleep(2000);

    int dado1 = rand() % 12 + 1; // Crea un numero entre el 1 y el 12.
    cout << dado1 << endl;
    cout << "Tirando otro dado de 12 caras..." << endl;
    rlutil::msleep(2000);
    int dado2 = rand() % 12 + 1;
    cout << dado2 << endl;
    int numeroObjetivo = dado1 + dado2;
    cout << "El número objetivo es " << numeroObjetivo << " del jugador " << jugadorActual << endl;
    rlutil::msleep(2000);
    cout << "Ahora " << jugadorActual << " tira los " << cantDadosActual << " dados de 6 caras..." << endl;

    tirarDados(dadosActual, cantDadosActual); // tira los dados

    rlutil::msleep(2000);

    cout << "Dados obtenidos: ";
    mostrarVector(dadosActual, cantDadosActual); // muestra los dados
    cout << endl;
    rlutil::msleep(2000);

    int dadosElegidos[cantDadosActual]; // e.g al principio esto va a ser dadosElegidos[0] = 0 ya que no elegimos nada, pero va cambiando en el turno
    int sumaParcial = 0;
    int cantDadosElegidos = 0;
    bool usado[cantDadosActual] = {false}; // Se ponen todos los dados en false. si se usa uno, se cambia a true
    bool pasoDeTurno = false;              // si apretamos 0, se cambia a true y cumple el if de terminar turno

    while (cantDadosElegidos < cantDadosActual)
    { // mientras la cantidad de dados elegidos sea menor a lo que tenemos, podemos elegir los dados
        rlutil::msleep(500);
        rlutil::cls();
        cout << "TURNO DE: " << jugadorActual << endl;
        cout << "NÚMERO OBJETIVO: " << numeroObjetivo << endl;
        cout << "Tu suma actual es de: " << sumaParcial << endl;
        cout << "Dados disponibles: ";
        mostrarVector(dadosActual, cantDadosActual);
        cout << "  " << endl;
        cout << "Ingresá el número del dado #" << (cantDadosElegidos + 1) << " que querés usar (del 1 a " << cantDadosActual << "): " << endl;
        cout << "Si querés pasar de turno, ingresá 0." << endl;

        int ind; // Indice del dado
        cin >> ind;
        if (cin.fail())
        { // Si se ingresa un tipo de dato incorrecto al preestablecido...
            cout << "Entrada inválida. Debe ser un número." << endl;
            cin.clear();             // Borra el error de buffer, pero todavia queda lo que se escribió, para eso...
            cin.ignore(10000, '\n'); // Descarta todo lo que escribimos.
            rlutil::msleep(1000);
            rlutil::cls();
            continue; // continue significa continuar hacia el final del while, y repetir el while
        }

        if (ind == 0)
        { // Lo que dije anteriormente, si se cambia a 0 se rompe el while
            pasoDeTurno = true;
            break;
        }

        ind--; // Ajustar índice para el array. Como los arrays son de 0 a 6 (e.g), al elegir ind 2 estariamos eligiendo el espacio 3 del array y no el 2

        if (ind < 0 or ind >= cantDadosActual)
        { // si el indice es menor, o si es mayor o igual que el ultimo valor que guardamos (inutilizado por arrays)
            cout << "Posición inválida. Intente de nuevo." << endl;
            rlutil::msleep(1000);
            rlutil::cls();
            continue;
        }
        if (usado[ind] == true)
        { // Si usamos el dado..
            cout << "No podés repetir el dado, volvé a elegir" << endl;
            rlutil::msleep(1000);
            rlutil::cls();
            continue;
        }

        dadosElegidos[cantDadosElegidos] = dadosActual[ind]; // Guardamos los dados y su valor que elegimos para posteriormente mostrarlos con la función mostrarVector y/o dárselos al rival
        sumaParcial += dadosActual[ind];                     // Guarda el valor del dado que elegimos en suma parcial
        usado[ind] = true;                                   // Lo cambia si usamos
        cantDadosElegidos++;                                 // Suma la cantidad, y tambien sirve para seguir con el proximo espacio del array
        rlutil::cls();
        cout << "Elegiste el dado " << dadosActual[ind] << endl;

        if (sumaParcial == numeroObjetivo)
        { // Si llegamos justo al numero objetivo, se rompe el while (se termina)
            rlutil::msleep(2000);
            break;
        }
    }

    if (pasoDeTurno == true)
    {
        cout << "El jugador " << jugadorActual << " ha pasado su turno y finaliza su ronda como no exitosa" << endl;
        if (cantDadosOponente > 1)
        {
            cantDadosActual++;   // Le suma un dado al actual
            cantDadosOponente--; // Le resta al oponente, siguiendo la logica que el oponente se lo da
            cout << jugadorActual << " recibió un dado de " << oponente << "." << endl;
            rlutil::msleep(2000);
        }
        else
        {
            cout << oponente << " no tiene suficientes dados para entregar." << endl;
            rlutil::msleep(2000);
        }
    }
    else if (sumaParcial == numeroObjetivo)
    {
        cout << "Combinación elegida: ";
        mostrarVector(dadosElegidos, cantDadosElegidos);
        cout << " ¡Es correcta!" << endl;
        puntosActual += sumaParcial * cantDadosElegidos; // Calcula el puntaje
        cantDadosOponente += cantDadosElegidos;          // Le suma a los dados que tiene el oponente los dados que elegimos
        cantDadosActual -= cantDadosElegidos;            // Restamos de nuestros dados los que elegimos para darselos al oponente
        cout << jugadorActual << " entrega " << cantDadosElegidos << " dado(s) a " << oponente << "." << endl;
        rlutil::msleep(2000);

        if (cantDadosActual <= 0)
        { // Si no tenemos dados...
            cout << jugadorActual << " se quedó sin dados y Ganó la partida!" << endl;
            puntosActual += 10000;
            rlutil::msleep(2000);
            rlutil::anykey();
            return true; // Indica que la partida terminó. Vuelve a la funcion jugarPartida y como ahora el if se cumple, rompe esa funcion de jugarPartida y va hacia el main
        }
    }
    else
    {
        cout << "Combinación elegida: ";
        mostrarVector(dadosElegidos, cantDadosElegidos);
        rlutil::msleep(2000);
        cout << " Es incorrecta." << endl;
        if (cantDadosOponente > 1)
        {                        // Si tiene mas de un dado el oponente
            cantDadosActual++;   // Le suma uno al actual
            cantDadosOponente--; // Y se lo resta dando la logica de que se lo da de su repositorio
            cout << jugadorActual << " recibió un dado de " << oponente << "." << endl;
            rlutil::msleep(2000);
        }
        else
        {
            cout << oponente << " no tiene suficientes dados para entregar." << endl;
            rlutil::msleep(2000);
        }
    }

    mostrarMensajeYEsperar();

    return false; // Indica que la partida no terminó. Vuelve al jugarPartida y sigue la otra linea, siguiendo para el turno del oponente
}

// Funcion que crea y muestra las estadisticas del juego.

void estadisticasDelJuego(string jugador1, string jugador2, int puntos1, int puntos2, int dados1, int dados2, string nombreMejorHistorico, int puntosMejorHistorico, bool huboPartidaJugada)
{

    if (huboPartidaJugada == false)
    {
        rlutil::setColor(rlutil::YELLOW);
        cout << "==========================================================" << endl;
        cout << "               NO SE HA JUGADO NINGUNA PARTIDA.       " << endl;
        cout << "       ¡JUEGA UNA PARTIDA PARA VER LAS ESTADÍSTICAS!      " << endl;
        cout << "==========================================================" << endl;
        rlutil::setColor(rlutil::WHITE); // Restaurar color por
        mostrarMensajeYEsperar();
    }
    else
    {

        cout << "================ ESTADÍSTICAS DE LA ÚLTIMA PARTIDA ================" << endl;

        cout << "Jugador: " << jugador1 << " | Puntos: " << puntos1 << " | Dados restantes: " << dados1 << endl;
        cout << "Jugador: " << jugador2 << " | Puntos: " << puntos2 << " | Dados restantes: " << dados2 << endl;

        cout << "--------------------------------------------------------" << endl;

        // Condicional para validar qué jugador ganó o si hay un empate
        if (puntos1 > puntos2)
        {
            cout << "¡El ganador de la ÚLTIMA PARTIDA es: " << jugador1 << "!" << endl;
        }
        else if (puntos2 > puntos1) // Si los puntos del jugador 2 son mayores
        {
            cout << "¡El ganador de la ÚLTIMA PARTIDA es: " << jugador2 << "!" << endl;
        }
        else
        { // Si los puntos son iguales
            cout << "¡La ÚLTIMA PARTIDA TERMINÓ EN EMPATE!" << endl;
        }
        cout << "-------------------------------------------------------------------" << endl;
        mostrarMensajeYEsperar();
    }

    if (puntosMejorHistorico > 0)
    { // Solo si ya se jugó al menos una partida y hay un record > 0
        cout << "============= RÉCORD HISTÓRICO EN ESTA SESIÓN DE JUEGO =============" << endl;
        cout << "MEJOR JUGADOR: " << nombreMejorHistorico << " con " << puntosMejorHistorico << " puntos." << endl;
        mostrarMensajeYEsperar();
    }
    else
    {
        cout << "Aún no se ha registrado ningún récord en esta sesión." << endl;
        mostrarMensajeYEsperar();
    }
    cout << "===================================================================" << endl;
}

int decidirQuienEmpieza(string nombre1, string nombre2)
{
    int dado_j1, dado_j2;

    do
    {
        rlutil::msleep(2000);
        cout << "Tirando dados para ver quien empieza..." << endl;

        // Cada jugador tira UN solo dado de 6 caras
        dado_j1 = (rand() % 6) + 1;
        dado_j2 = (rand() % 6) + 1;

        cout << nombre1 << " sacó un " << dado_j1 << endl;
        rlutil::msleep(2000);
        cout << nombre2 << " sacó un " << dado_j2 << endl;

        if (dado_j1 == dado_j2)
        {
            cout << "¡Empate! Se vuelve a tirar." << endl
                 << endl;
            rlutil::msleep(2000);
        }

    } while (dado_j1 == dado_j2); // El bucle se repite si los dados son iguales

    if (dado_j1 > dado_j2)
    {
        return 0;
        // Gana el jugador 1
    }
    else
    {
        return 1; // Gana el jugador 2
    }
}

int menuOpciones()
{ // Funcion que muestra el menu principal dl juego.
    int opciones;
    bool opcionValida = false;

    do
    {
        // Paredes verticales, las imprimimos en una sola línea para evitar pisar
        rlutil::cls();
        rlutil::setColor(rlutil::LIGHTGREEN);
        /// PAREDES VERTICALES DEL MENU
        for (int j = 2; j <= 20; j++)
        { // for (va de LA PRIMERA LINEA (6 en este caso) hasta (LA 20 EN ESTE CASO) ejecutando una linea de pared (|)
            rlutil::locate(15, j);
            cout << "|"; // Recuadro del cartel (x, y) x = columnas / y = filas
            rlutil::locate(103, j);
            cout << "|";
        }

        rlutil::locate(15, 1);
        cout << "=========================================================================================";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(25, 2);
        cout << "           __  __ ______ _  _ _   _";
        rlutil::locate(25, 3);
        cout << "          |  \\/  |  ____| \\ | | |  | |";
        rlutil::locate(25, 4);
        cout << "          | \\  / | |__  |  \\| | |  | |";
        rlutil::locate(25, 5);
        cout << "          | |\\/| |  __| | . ` | |  | |";
        rlutil::locate(25, 6);
        cout << "          | |  | | |____| |\\  | |__| |";
        rlutil::locate(25, 7);
        cout << "          |_|  |_|______|_| \\_|\\____/";
        rlutil::setColor(rlutil::LIGHTGREEN);
        rlutil::locate(16, 9);
        cout << "=======================================================================================";
        rlutil::setColor(rlutil::MAGENTA);
        rlutil::locate(25, 11);
        cout << "                1. Jugar";
        rlutil::locate(25, 13);
        cout << "                2. Estadistica";
        rlutil::locate(25, 15);
        cout << "                3. Creditos";
        rlutil::locate(25, 17);
        cout << "                4. Reglamento";
        rlutil::locate(25, 19);
        cout << "                0. Salir";
        rlutil::setColor(rlutil::LIGHTGREEN);
        rlutil::locate(15, 21);
        cout << "=========================================================================================";

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(26, 26);
        cout << "                   Ingrese una opcion: " << endl
             << endl
             << endl
             << endl;

        rlutil::setColor(rlutil::LIGHTGREEN);

        for (int t = 25; t <= 27; t++)
        { // for (va de LA PRIMERA LINEA (6 en este caso) hasta (LA 20 EN ESTE CASO) ejecutando una linea de pared (|)
            rlutil::locate(43, t);
            cout << "|"; // Recuadro del cartel (x, y) x = columnas / y = filas
            rlutil::locate(74, t);
            cout << "|";
        }

        rlutil::locate(43, 24);
        cout << "================================";
        rlutil::locate(43, 28);
        cout << "================================";
        rlutil::locate(67, 26);

        cin >> opciones;
        // rlutil::cls();
        if (cin.fail())
        {
            rlutil::locate(41, 26);
            cout << "Entrada invalida. Intente nuevamente\n";
            cin.clear();
            cin.ignore(); // Limpia el buffer de entrada para que no afecte a la siguiente entrada
            rlutil::msleep(1000);
            rlutil::cls(); // Duerme 1 segundo y limpia la pantalla (no afecta al menu)
        }
        else if (opciones >= 0 && opciones <= 4)
        {
            opcionValida = true;
            rlutil::cls();
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            rlutil::locate(75, 26);
            cout << "        La opcion " << opciones << " no es valida." << endl;
            rlutil::locate(79, 27);
            cout << "      Intente nuevamente." << endl;
            rlutil::msleep(1500);
            rlutil::cls(); // Lo mismo que arriba
        }
    } while (!opcionValida);

    return opciones;
}

void reglamento()
{
    rlutil::cls();

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "\n=================   REGLAMENTO DEL JUEGO: ENFRENDADOS   =================\n";

    rlutil::setColor(rlutil::WHITE);
    cout << "Enfrendados es un juego de dados para dos jugadores que combina el azar\n";
    cout << "con las matemáticas. El objetivo es sumar la mayor cantidad de puntos\n";
    cout << "en un total de tres rondas.\n\n";

    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "-----------------------------------------------------------------------\n";

    rlutil::setColor(rlutil::YELLOW);
    cout << "REGLAS GENERALES:\n";

    rlutil::setColor(rlutil::WHITE);
    cout << "- Cada jugador tiene seis dados de seis caras (dados stock).\n";
    cout << "- Adicionalmente, hay dos dados de doce caras que se usan entre rondas.\n";
    cout << "- Al comenzar el juego, cada jugador lanza un dado de 6 caras.\n";
    cout << "   Quien saque el valor más alto comienza la partida.\n";
    cout << "   En caso de empate, se repite la tirada.\n";

    rlutil::setColor(rlutil::YELLOW);
    cout << "\nDINÁMICA DE CADA RONDA:\n";

    rlutil::setColor(rlutil::WHITE);
    cout << "- El jugador que inicia lanza los dos dados de 12 caras.\n";
    cout << "- Luego lanza los dados stock (dados de 6 caras que tenga en su poder).\n";
    cout << "- Los dados que tiene cada jugador se denominan dados stock y pueden\n";
    cout << "   variar de una ronda a otra.\n";

    rlutil::setColor(rlutil::YELLOW);
    cout << "\nPUNTAJE:\n";

    rlutil::setColor(rlutil::WHITE);
    cout << "- Después de ambos lanzamientos, se determina el puntaje basado en\n";
    cout << "   en matemáticas o si el jugador se quedó sin dados.\n";

    rlutil::setColor(rlutil::YELLOW);
    cout << "\nIMPORTANTE:\n";

    rlutil::setColor(rlutil::WHITE);
    cout << "- El juego finaliza después de 3 rondas y gana quien tenga más puntos.\n";
    cout << "- Las reglas completas de puntuación se explican durante el juego.\n";

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "=======================================================================\n\n";

    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Presione una tecla para volver al menú..." << endl;

    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
    rlutil::cls();
}

void creditos()
{ // Funcion que muestra los creditos del juego.
    // Guardo los nombres, apellidos y numero de legajo de los participantes.
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "===================== CREDITOS DEL JUEGO =====================\n\n";

    // Nombre del grupo
    rlutil::setColor(rlutil::YELLOW);
    cout << "Nombre del grupo: ";

    rlutil::setColor(rlutil::WHITE);
    cout << "Grupo 2\n\n";

    // Participantes
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Nombres, apellidos y legajos de los participantes\n\n";

    rlutil::setColor(rlutil::WHITE);
    cout << "   - Miguel Guimar Salazar: 32530\n";
    cout << "   - Ramiro Joel Kriguer: 33446\n";
    cout << "   - Fernando Gabriel Quiroga: 33404\n";
    cout << "   - Federico Wachenschwan: 22561\n\n";

    // Menciones especiales
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "MENCIONES ESPECIALES para:\n\n";

    rlutil::setColor(rlutil::WHITE);
    cout << "   - Íconos obtenidos de Freepik y logo hecho en Logo Maker.\n";
    cout << "   - Juego inventado por Angel Simón. Levemente inspirado en el juego Mafia.\n\n";

    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=========================== ANEXO ============================\n";
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << "Presione cualquier tecla para continuar..." << endl;
    rlutil::anykey();
}

void mostrarPortada()
{
    while (true)
    {
        for (int i = 1; i < 20; i++)
        {

            if (i % 2 == 0)
            {                                              // Dependiendo de si el numero del recorrido de la i del for es par o impar, alterna entre un color y fondo de letra y otro
                rlutil::setColor(rlutil::RED);             // Hace que a partir del comando para abajo las letras se pongan de cierto color
                rlutil::setBackgroundColor(rlutil::WHITE); // Pone el color de fondo de las letras de cierto color
            }
            else
            {
                rlutil::setColor(rlutil::WHITE);                // Hace que a partir del comando para abajo las letras se pongan de cierto color
                rlutil::setBackgroundColor(rlutil::LIGHTGREEN); // Pone el color de fondo de las letras de cierto color
            }

            rlutil::hidecursor(); // Hace que no titile el cursor (no aparece en la terminal)

            // Recuadro del cartel (x, y) x = columnas / y = filas
            rlutil::locate(15, 6);
            cout << "=========================================================================================";

            // Paredes verticales, las imprimimos en una sola línea para evitar pisar
            for (int j = 7; j <= 20; j++)
            {
                rlutil::locate(15, j);
                cout << "|";
                rlutil::locate(103, j);
                cout << "|";
            }
            rlutil::locate(15, 20);
            cout << "=========================================================================================";

            // Texto dentro del recuadro
            rlutil::locate(25, 11);
            cout << " _______   ____________  _______   ______  ___     ____  ____  _____ ";
            rlutil::locate(25, 12);
            cout << "/ ____/ | / / ____/ __ \\/ ____/ | / / __ \\/   |   / __ \\/ __ \\/ ___/ ";
            rlutil::locate(25, 13);
            cout << "/ __/ /  |/ / /_  / /_/ / __/ /  |/ / / / / /| |  / / / / / / /\\__ \\ ";
            rlutil::locate(25, 14);
            cout << "/ /___/ /|  / __/ / _, _/ /___/ /|  / /_/ / ___ | / /_/ / /_/ /___/ /";
            rlutil::locate(25, 15);
            cout << "/_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/\\____//____/ ";

            rlutil::locate(40, 25);
            cout << " Presione una tecla para continuar";

            rlutil::msleep(700); // Detiene la ejecucion del programa un determinado tiempo

            // Si se presionó una tecla, salir del bucle
            if (kbhit())
            {                       // Determina si se ha pulsado el teclado
                getch();            // Consume la tecla
                system("color 07"); // Deja la terminal y el texto en el color por defecto
                rlutil::cls();      // Limpia la pantalla
                return;
            }
        }
    }
}

void mostrarEstadoDeRonda(int ronda, string jugador1, string jugador2, int puntos1, int puntos2, int dados1, int dados2)
{
    cout << "Ronda " << ronda << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Puntajes de " << jugador1 << ": " << puntos1 << endl;
    cout << "Puntajes de " << jugador2 << ": " << puntos2 << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Dados de " << jugador1 << ": " << dados1 << endl;
    cout << "Dados de " << jugador2 << ": " << dados2 << endl;
    cout << "----------------------------------------------------------------" << endl;
    rlutil::msleep(2000);
}