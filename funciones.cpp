#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
#include <string>
#include "vectores.h"
using namespace std;

// se puede confundir, pero cantDadosInicial, jugadorInicial, dadosInicial y todo lo que sea Inicial se refiere al primer jugador (contrario al oponente)

// se puede confundir, pero cantDadosInicial, jugadorInicial, dadosInicial y todo lo que sea Inicial se refiere al primer jugador (contrario al oponente)
void jugarPartida(string jugadorInicial, string jugadorOponente, int dadosInicial[], int dadosOponente[], int& cantDadosInicial, int& cantDadosOponente, int& puntosInicial, int& puntosOponente) {

    // dadosInicial es el array, y cantDadosInicial es cuántos dados tiene

    for (int ronda = 1; ronda <= 3; ronda++) // entra en una ronda de 3
     {
        rlutil::msleep(2000);
        rlutil::cls();
        cout << "Ronda " << ronda << endl;
        cout << "----------------------------------------------------------------" << endl; // puntosInicial y puntosOponente es el total en todas las rondas
        cout << "Puntajes de " << jugadorInicial << ": " << puntosInicial << endl;

        cout << "Puntajes de " << jugadorOponente << ": " << puntosOponente << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Dados de " << jugadorInicial << ": " << cantDadosInicial   << endl;
        cout << "Dados de " << jugadorOponente << ": " << cantDadosOponente   << endl;
        cout << "----------------------------------------------------------------" << endl;
        rlutil::msleep(2000);
        cout << "Turno de " << jugadorInicial << endl;
        cout << jugadorInicial << " tira el dado de 12 caras..." << endl;

        rlutil::msleep(2000);

        int dado1 = dadoDoceCaras();
        cout << dado1 << endl; // Primer dado de 12 caras

        cout << "Tirando otro dado de 12 caras..." << endl;
        rlutil::msleep(2000);
        int dado2 = dadoDoceCaras();
        cout << dado2 << endl; // Segundo dado de 12 caras
        cout << "Se sumará los dados para saber el numero objetivo..." << endl;
        rlutil::msleep(2000);
        int numeroObjetivo = dado1 + dado2; // Numero objetivo es la suma de los dos dados de 12 caras
        cout << "El numero objetivo es: " << numeroObjetivo << " del jugador " << jugadorInicial << endl;
        rlutil::msleep(2000);
        cout << "Ahora " << jugadorInicial << " tira el dado de 6 caras..." << endl;
        rlutil::msleep(2000);
        for (int i = 0; i < cantDadosInicial; i++) {
        dadosInicial[i] = (rand() % 6) + 1; // Genera los dados aleatorios y los va guardando en el array
        }

        cout << "Dados obtenidos: ";
        for (int i = 0; i < cantDadosInicial; i++) {
        cout << dadosInicial[i] << " "; // Muestra los dados obtenidos

        }
        cout << " " << endl;
        rlutil::anykey();
        rlutil::cls();

        int dadosElegidos[cantDadosInicial]; // inicializamos dadosElegidos para saber qué eligio y el cantDadosInicial es para que lo maximo sea la cantidad de dados que se tiene.
        int sumaParcial = 0; // en cada ronda se reinicia
        int cantDadosElegidos = 0; // lo mismo que arriba
        bool usadoInicial[cantDadosInicial] = {false}; // pone todos los dados en falso, para que no se repitan al elegirlos. el {} pone todos los elementos en false
        bool pasoDeTurno = false; // variable para saber si el jugador paso el turno, y no eligio ningun dado

        while (sumaParcial < numeroObjetivo) // Mientras la suma parcial sea menor al numero objetivo, se sigue eligiendo dados
        {
            cout << "NÚMERO OBJETIVO: " << numeroObjetivo << endl;
            cout << "Tu suma actual es de: " << sumaParcial << endl;
            cout << "Dados disponibles: ";
            for (int i = 0; i < cantDadosInicial; i++)
            {
                cout << dadosInicial[i] << " "; // Muestra los dados disponibles
            }
            
            int ind; // ind, de índice, es la variable que se usa para elegir el dado. Es como un selector
            cout << "   " << endl;
            cout << "Ingresá el número del dado #" << (cantDadosElegidos + 1) << " que querés usar (del 1 a " << cantDadosInicial << "): " << endl;
            cout << "Si ingresás 0, se da por perdida la ronda" << endl;
            cin >> ind;
             if (ind == 0) {
                pasoDeTurno = true; // Si el usuario ingresa 0, pasa al turno del oponente
                break; 
              
                } // Si se ingresa otra cosa, como una letra, se vuelve a pedir el dado a elegir
                if (cin.fail()) {
                cout << "Entrada inválida. Debe ser un número entre 1 y " << cantDadosInicial << ". " << endl;
                cin.clear();
                cin.ignore(10000, '\n'); 
                  rlutil::msleep(1000);
                rlutil::cls();
                continue; }
            ind--; // Resta 1 al índice para que empiece desde 0, ya que los arrays empiezan desde 0 y el usuario empieza desde 1
            if (usadoInicial[ind] == true) // Si el dado ya fue usado, no se puede volver a elegir ya que más adelante lo ponemos en true
            {
                cout << "No puedes repetir el dado, vuelve a elegir" << endl;
                rlutil::msleep(1000);
                rlutil::cls();
                continue ; // Continue va hacia el final del while, y vuelve a pedir el dado a elegir
            }

            
            
            if (ind < 0 or ind >= cantDadosInicial) {
                cout << "Posición inválida. Debe ser un número entre 1 y " << cantDadosInicial << ". " << endl;
                  rlutil::msleep(1000);
                rlutil::cls();
            } else {
                dadosElegidos[cantDadosElegidos] = dadosInicial[ind]; // Guarda el dado elegido con el valor exacto del dado que elegió el usuario
                sumaParcial += dadosInicial[ind]; // Suma el valor del dado elegido a la suma parcial
                usadoInicial[ind] = true; // Es lo que dije antes, pone el dado en true para que no se pueda volver a elegir
                cantDadosElegidos++; // Cuenta la cantidad de dados elegidos. Fundamental para pasar o restar los dados
                rlutil::cls();
                cout << "Elegiste el dado " << dadosInicial[ind] << endl;




            }

            if (sumaParcial == numeroObjetivo) {
            break; } // verifica siempre que si es igual, el usuario no tiene que seguir eligiendo dados, y se salta el while

        }


        // En primer lugar hicimos que pida la cantidad de dados y luego allí elegir el dado, pero luego se hizo que el usuario elija el dado directamente, y no la cantidad de dados, ya que es más intuitivo

       int sumaSeleccionada = sumaParcial; // No era necesario esta línea, pero como tenía escrito la mayoria del siguiente código con esa variable, lo asigné
       if (pasoDeTurno == true) {
        cout << "El jugador " << jugadorInicial << " ha pasado su turno." << endl;
        cout << "La ronda finaliza como no exitosa." << endl;
        // Se aplica la penalidad por fallo.
        if (cantDadosOponente > 1) {
            dadosInicial[cantDadosInicial] = dadosOponente[cantDadosOponente - 1];
            cantDadosInicial++;
            cantDadosOponente--;
            cout << jugadorInicial << " recibió un dado de su oponente." << endl;
        } else {
            cout << "El oponente no tiene dados suficientes para entregar." << endl;
        } // Pasa al siguiente turno. Si no se pasaTurno, se sigue con el código de abajo
    } else 
        if (sumaSeleccionada == numeroObjetivo) { // Verifica si es igual al numeroObjetivo para saber si es tirada correcta o no
            cout << "Combinación elegida: ";
            mostrarVector(dadosElegidos, cantDadosElegidos);
            rlutil::msleep(2000);
            cout << " Es correcta" << endl;
            puntosInicial += sumaSeleccionada * cantDadosElegidos; // Puntos de la ronda es el numero objetivo por la cantidad de dados que se eligieron


            // Transferir los dados al oponente.
            for (int i = 0; i < cantDadosElegidos; i++)
            {
                dadosOponente[cantDadosOponente] = dadosElegidos[i]; // Le pasas los dados al oponente, y copias su valor
                // El cantDadosOponente++ está después porque la lógica de arrays, por ejemplo si tenemos 8 cantDadosOponente, va de 0 a 7. Al posicionarnos en 8, estamos en la siguiente posición del array
                cantDadosOponente++;
            }

            cantDadosInicial -= cantDadosElegidos; // El jugador inicial pierde sus dados.

            if (cantDadosInicial <= 0)
            {
                cout << jugadorInicial << " se quedó sin dados y ganó la partida!" << endl;
                puntosInicial += 10000; // Los suma al puntaje final
                rlutil::anykey();
                rlutil::cls();
                
                
                return; // Vuelve al main, y verifica la victoria, que será verdadera
            }

      

        }         // Abajo, si la combinación es tirada fallida                           
        else {
            cout << "Combinación elegida: ";
            mostrarVector(dadosElegidos, cantDadosElegidos);
            rlutil::msleep(2000);
            cout << " Es incorrecta" << endl;
            if (cantDadosOponente > 1)
            {
                dadosInicial[cantDadosInicial] = dadosOponente[cantDadosOponente - 1];
                cantDadosInicial++; // Al jugador inicial se le da 1 dado.
                cantDadosOponente--; // El oponente se queda con 1 dado menos.
                cout << jugadorInicial << " recibió un dado de su oponente." << endl;
            }
            else
            {
                cout << "El oponente no tiene dados suficientes para entregar." << endl;
            }
            


            // A continuacion, todo lo anterior pero para el oponente. Es solo cambios de variables, pero misma logica y estructura


        }

       rlutil::anykey();
rlutil::cls();
cout << "Turno de " << jugadorOponente << endl;
cout << jugadorOponente << " tira el dado de 12 caras..." << endl;
rlutil::msleep(2000);
int dadoOponente1 = dadoDoceCaras();
cout << dadoOponente1 << endl;
cout << "Tirando otro dado de 12 caras..." << endl;
rlutil::msleep(2000);
int dadoOponente2 = dadoDoceCaras();
cout << dadoOponente2 << endl;
cout << "Se sumará los dados para saber el numero objetivo..." << endl;
rlutil::msleep(2000);
int numeroObjetivoOponente = dadoOponente1 + dadoOponente2;
cout << "El numero objetivo es: " << numeroObjetivoOponente << " del jugador " << jugadorOponente << endl;
rlutil::msleep(2000);
cout << "Ahora " << jugadorOponente << " tira el dado de 6 caras..." << endl;
rlutil::msleep(2000);
for (int i = 0; i < cantDadosOponente; i++) {
    dadosOponente[i] = (rand() % 6) + 1;
}
cout << "Dados obtenidos: ";
for (int i = 0; i < cantDadosOponente; i++) {
    cout << dadosOponente[i] << " ";
}
cout << " " << endl;
rlutil::anykey();
rlutil::cls();

int dadosElegidosOponente[cantDadosOponente];
int sumaParcialOponente = 0;
int cantDadosElegidosOponente = 0;
bool usadoOponente[cantDadosOponente] = {false};
bool pasoDeTurnoOponente = false;

while (sumaParcialOponente < numeroObjetivoOponente)
{
    cout << "NÚMERO OBJETIVO: " << numeroObjetivoOponente << endl;
    cout << "Tu suma actual es de: " << sumaParcialOponente << endl;
    cout << "Dados disponibles: ";
    for (int i = 0; i < cantDadosOponente; i++)
    {
        cout << dadosOponente[i] << " ";
    }
    
    int indOponente;
    cout << "   " << endl;
    cout << "Ingresá el número del dado #" << (cantDadosElegidosOponente + 1) << " que querés usar (del 1 a " << cantDadosOponente << "): " << endl;
    cout << "Si ingresás 0, se da por perdida la ronda" << endl;
    cin >> indOponente;
     if (indOponente == 0) {
        pasoDeTurnoOponente = true;
        break; 
        }
        if (cin.fail()) {
        cout << "Entrada inválida. Debe ser un número entre 1 y " << cantDadosOponente << ". " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
            rlutil::msleep(1000);
        rlutil::cls();
        continue; }
    indOponente--;
    if (usadoOponente[indOponente] == true)
    {
        cout << "No puedes repetir el dado, vuelve a elegir" << endl;
        rlutil::msleep(1000);
        rlutil::cls();
        continue ;
    }
    
    if (indOponente < 0 or indOponente >= cantDadosOponente) {
        cout << "Posición inválida. Debe ser un número entre 1 y " << cantDadosOponente << ". " << endl;
            rlutil::msleep(1000);
        rlutil::cls();
    } else {
        dadosElegidosOponente[cantDadosElegidosOponente] = dadosOponente[indOponente];
        sumaParcialOponente += dadosOponente[indOponente];
        usadoOponente[indOponente] = true;
        cantDadosElegidosOponente++;
        rlutil::cls();
        cout << "Elegiste el dado " << dadosOponente[indOponente] << endl;
    }
    if (sumaParcialOponente == numeroObjetivoOponente) {
        break; } // verifica siempre que si es igual, el usuario no tiene que seguir eligiendo dados, y se salta el while
}

int sumaSeleccionadaOponente = sumaParcialOponente;
if (pasoDeTurnoOponente == true) {
    cout << "El jugador " << jugadorOponente << " ha pasado su turno." << endl;
    cout << "La ronda finaliza como no exitosa." << endl;
    // Se aplica la penalidad por fallo.
    if (cantDadosInicial > 1) {
        dadosOponente[cantDadosOponente] = dadosInicial[cantDadosInicial - 1];
        cantDadosOponente++;
        cantDadosInicial--;
        cout << jugadorOponente << " recibió un dado de su oponente." << endl;
    } else {
        cout << "El jugador inicial no tiene dados suficientes para entregar." << endl;
    }
}
else
if (sumaSeleccionadaOponente == numeroObjetivoOponente) {
    cout << "Combinación elegida: ";
    mostrarVector(dadosElegidosOponente, cantDadosElegidosOponente);
    rlutil::msleep(2000);
    cout << " Es correcta" << endl;
    puntosOponente += sumaSeleccionadaOponente * cantDadosElegidosOponente;

    for (int i = 0; i < cantDadosElegidosOponente; i++)
    {
        dadosInicial[cantDadosInicial] = dadosElegidosOponente[i];
        cantDadosInicial++;
    }

    cantDadosOponente -= cantDadosElegidosOponente;

    if (cantDadosOponente <= 0)
    {
        cout << jugadorOponente << " se quedó sin dados y ganó la partida!" << endl;
        puntosOponente += 10000;
              rlutil::anykey();
              rlutil::cls();
        return;
    }
}
else {
    cout << "Combinación elegida: ";
    mostrarVector(dadosElegidosOponente, cantDadosElegidosOponente);
    rlutil::msleep(2000);
    cout << " Es incorrecta" << endl;
    if (cantDadosInicial > 1)
    {
        dadosOponente[cantDadosOponente] = dadosInicial[cantDadosInicial - 1];
        cantDadosOponente++;
        cantDadosInicial--;
        cout << jugadorOponente << " recibió un dado de su oponente." << endl;
    }
    else
    {
        cout << "El jugador inicial no tiene dados suficientes para entregar." << endl;
    }
    if (pasoDeTurnoOponente == true) {
        cout << "El jugador " << jugadorOponente << " ha pasado su turno." << endl;
        
    }
}
rlutil::anykey();

}

}


// Funcion que crea y muestra las estadisticas del juego.
void estadisticasDelJuego(string jugador1, string jugador2, int puntos1, int puntos2, int dados1, int dados2, string nombreMejorHistorico, int puntosMejorHistorico) {

    // Información de la última partida (que ya tienes)
    cout << "================ ESTADÍSTICAS DE LA ÚLTIMA PARTIDA ================" << endl;
    cout << "Jugador: " << jugador1 << " | Puntos: " << puntos1 << " | Dados restantes: " << dados1 << endl;
    cout << "Jugador: " << jugador2 << " | Puntos: " << puntos2 << " | Dados restantes: " << dados2 << endl;
    cout << "-------------------------------------------------------------------" << endl;

    if (puntos1 > puntos2) {
        cout << "¡El ganador de la ÚLTIMA PARTIDA es: " << jugador1 << "!" << endl;
    } else if (puntos2 > puntos1) {
        cout << "¡El ganador de la ÚLTIMA PARTIDA es: " << jugador2 << "!" << endl;
    } else {
        cout << "¡La ÚLTIMA PARTIDA TERMINÓ EN EMPATE!" << endl;
    }
    cout << "-------------------------------------------------------------------" << endl;

    // AQUI AGREGAS LA PARTE DEL RECORD HISTÓRICO DE LA SESIÓN
    cout << "============= RÉCORD HISTÓRICO EN ESTA SESIÓN DE JUEGO =============" << endl;
    if (puntosMejorHistorico > 0) { // Solo si ya se jugó al menos una partida
        cout << "MEJOR JUGADOR: " << nombreMejorHistorico << " con " << puntosMejorHistorico << " puntos." << endl;
    } else {
        cout << "Aún no se ha registrado ningún récord en esta sesión." << endl;
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

// Funcion para crear un dado de 12 caras.
int dadoDoceCaras()
{
    return rand() % 12 + 1; // Crea un numero entre el 1 y el 12.
}

// Funcion para tirar los dados.
void tirarDados()
{ // Tira los dados, muestra el resultado y pregunta al jugador si quiere volver a tirar un dado.
    string opcion;

    do
    {
        int resultado = dadoDoceCaras();

        cout << " Al tirar un dado el resultado es: " << resultado << endl;
        cout << endl;

        cout << " ¿ Queres tirar otro dado ? " << endl;
        cin >> opcion;

    } while (opcion == "s" || opcion == "S");
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
    ///PAREDES VERTICALES DEL MENU
        for (int j = 2; j <= 20; j++) { // for (va de LA PRIMERA LINEA (6 en este caso) hasta (LA 20 EN ESTE CASO) ejecutando una linea de pared (|)
        rlutil::locate(15, j); cout << "|"; // Recuadro del cartel (x, y) x = columnas / y = filas
        rlutil::locate(103, j); cout << "|";
    }

    rlutil::locate(15,1); cout << "=========================================================================================";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(25, 2); cout << "           __  __ ______ _  _ _   _";
    rlutil::locate(25, 3); cout << "          |  \\/  |  ____| \\ | | |  | |";
    rlutil::locate(25, 4); cout << "          | \\  / | |__  |  \\| | |  | |";
    rlutil::locate(25, 5); cout << "          | |\\/| |  __| | . ` | |  | |";
    rlutil::locate(25, 6); cout << "          | |  | | |____| |\\  | |__| |";
    rlutil::locate(25, 7); cout << "          |_|  |_|______|_| \\_|\\____/";
    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(16, 9); cout << "=======================================================================================";
    rlutil::setColor(rlutil::MAGENTA);
    rlutil::locate(25, 11); cout << "                1. Jugar";
    rlutil::locate(25, 13); cout << "                2. Estadistica";
    rlutil::locate(25, 15); cout << "                3. Creditos";
    rlutil::locate(25, 17); cout << "                4. Reglamento";
    rlutil::locate(25, 19); cout << "                0. Salir";
    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(15, 21); cout << "=========================================================================================";

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(26, 26); cout << "                   Ingrese una opcion: " << endl << endl << endl << endl;

    rlutil::setColor(rlutil::LIGHTGREEN);

    for (int t = 25; t <= 27; t++) { // for (va de LA PRIMERA LINEA (6 en este caso) hasta (LA 20 EN ESTE CASO) ejecutando una linea de pared (|)
        rlutil::locate(43, t); cout << "|"; // Recuadro del cartel (x, y) x = columnas / y = filas
        rlutil::locate(74, t); cout << "|";
    }

    rlutil::locate(43,24); cout << "================================";
    rlutil::locate(43,28); cout << "================================";
    rlutil::locate(67, 26);

        cin >> opciones;
        // rlutil::cls();
        if (cin.fail())
        {
            rlutil::locate(41, 26);
            cout << "Entrada invalida. Intente nuevamente\n";
            cin.clear();
            cin.ignore(10000, '\n'); // Limpia el buffer de entrada para que no afecte a la siguiente entrada
            rlutil::msleep(1000);
            rlutil::cls(); // Duerme 1 segundo y limpia la pantalla (no afecta al menu)
        }
        else if (opciones >= 0 && opciones <= 4)
        {
            opcionValida = true;
            rlutil::cls();
        }
        else
        {   rlutil::setColor(rlutil::LIGHTRED);
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

void reglamento(){
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
    cout << "- Los dados que tiene cada jugador se denominan \"dados stock\" y pueden\n";
    cout << "   variar de una ronda a otra.\n";

    rlutil::setColor(rlutil::YELLOW);
    cout << "\nPUNTAJE:\n";

    rlutil::setColor(rlutil::WHITE);
    cout << "- Después de ambos lanzamientos, se determina el puntaje basado en\n";
    cout << "   condiciones que combinan el azar y el uso de operaciones matemáticas.\n";

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

    rlutil::anykey();   // Espera que el usuario presione una tecla
}


void mostrarPortada()
{
  while (true){
        for (int i=1; i<20; i++){

            if (i % 2 == 0){ //Dependiendo de si el numero del recorrido de la i del for es par o impar, alterna entre un color y fondo de letra y otro
                rlutil::setColor(rlutil::RED);//Hace que a partir del comando para abajo las letras se pongan de cierto color
                rlutil::setBackgroundColor(rlutil::WHITE); //Pone el color de fondo de las letras de cierto color
            } else {
                rlutil::setColor(rlutil::WHITE);//Hace que a partir del comando para abajo las letras se pongan de cierto color
                rlutil::setBackgroundColor(rlutil::LIGHTGREEN); //Pone el color de fondo de las letras de cierto color

            }

            rlutil::hidecursor(); //Hace que no titile el cursor (no aparece en la terminal)

            // Recuadro del cartel (x, y) x = columnas / y = filas
             rlutil::locate(15, 6); cout << "=========================================================================================";

            // Paredes verticales, las imprimimos en una sola línea para evitar pisar
            for (int j = 7; j <= 20; j++) {
                rlutil::locate(15, j); cout << "|";
                rlutil::locate(103, j); cout << "|";

            }
            rlutil::locate(15, 20); cout << "=========================================================================================";

            // Texto dentro del recuadro
            rlutil::locate(25, 11); cout << " _______   ____________  _______   ______  ___     ____  ____  _____ ";
            rlutil::locate(25, 12); cout << "/ ____/ | / / ____/ __ \\/ ____/ | / / __ \\/   |   / __ \\/ __ \\/ ___/ ";
            rlutil::locate(25, 13); cout << "/ __/ /  |/ / /_  / /_/ / __/ /  |/ / / / / /| |  / / / / / / /\\__ \\ ";
            rlutil::locate(25, 14); cout << "/ /___/ /|  / __/ / _, _/ /___/ /|  / /_/ / ___ | / /_/ / /_/ /___/ /";
            rlutil::locate(25, 15); cout << "/_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/\\____//____/ ";

            rlutil::locate(40, 25); cout << " Presione una tecla para continuar";

            rlutil::msleep(700); //Detiene la ejecucion del programa un determinado tiempo

            // Si se presionó una tecla, salir del bucle
            if (kbhit()) { //Determina si se ha pulsado el teclado
                getch(); // Consume la tecla
                system("color 07"); // Deja la terminal y el texto en el color por defecto
                rlutil::cls(); //Limpia la pantalla
                return;
            }

        }
    }
}