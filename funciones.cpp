#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
#include <string>
#include "vectores.h"
using namespace std;
// se puede confundir, pero cantDadosInicial, jugadorInicial, dadosInicial y todo lo que sea Inicial se refiere al primer jugador (contrario al oponente)
void jugarPartida(string jugadorInicial, string jugadorOponente, int dadosInicial[], int dadosOponente[], int& cantDadosInicial, int& cantDadosOponente, int& puntosInicial, int& puntosOponente) { 

    // dadosInicial es el array, y cantDadosInicial es cuántos dados tiene



    for (int ronda = 1; ronda <= 3; ronda++) {
        rlutil::msleep(2000); 
        rlutil::cls(); 
        cout << "Ronda " << ronda << endl;
        cout << "----------------------------------------------------------------" << endl; // puntosInicial y puntosOponente es el total en todas las rondas
        cout << "Puntajes de " << jugadorInicial << ": " << puntosInicial << endl;
        
        cout << "Puntajes de " << jugadorOponente << ": " << puntosOponente << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Dados de " << jugadorInicial << " (" << cantDadosInicial << "): " << endl;
        cout << "Dados de " << jugadorOponente << " (" << cantDadosOponente << ")" << endl;
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
        dadosInicial[i] = (rand() % 6) + 1; // Genera X (depende cuántos dados tiene el jugador) de números aleatorios entre 1 y 6 simulando la tirada de 6 dados. Se guardan en el array
        }

        cout << "Dados obtenidos: ";
        for (int i = 0; i < cantDadosInicial; i++) {
        cout << dadosInicial[i] << " "; // Muestra los dados obtenidos
        
        }
        cout << " " << endl;
        rlutil::anykey();
        int cantASumar;
do {
    cout << "¿Cuántos dados querés sumar? (no podés elegir 1 solo): ";

    cin >> cantASumar; // El usuario mismo pone un valor a la variable, por lo que no hay valor basura

} while (cantASumar < 2 || cantASumar > cantDadosInicial);



// cantASumar abarca la cantidad de dados que el usuario eligió, y por lo tanto lo que se le va a sumar al oponente si es que la tirada es existosa



int indices[cantASumar]; // las posiciones de los dados elegidos por el usuario
bool usado[cantDadosInicial] = {false}; // para marcar si un dado ya fue usado inicializamos todos en false
int dadosElegidos[cantASumar]; // para guardar los dados elegidos por el usuario


for (int i = 0; i < cantASumar; i++) {
    int ind; // ind de indice, pero referido a la posicion. indices abarcaría todos los indices
    do {
        cout << "Ingresá el número del dado #" << (i + 1) << " que querés usar (del 1 a 6): ";
        cin >> ind;
        ind--;  // Al comenzar los arrays desde 0, y por ejemplo el usuario ve del 1 al 6, le restamos 1 para que coincida con el índice del array

        if (ind < 0 or ind >= cantDadosInicial) {
            cout << "Posición inválida. Debe ser un número entre 1 y 6. ";
        } else if (usado[ind]) {    /* Como inicializamos todos los arrays en falso, 
                                    si el dado fue elegido (por ejemplo elegimos la posicion 2, que es ind = 1) se pone en true,
                                     y si se vuelve a elegir, usado[ind] sera true, por lo que se cumple el if */
            cout << "Ese dado ya fue usado. ";
        }

    } while (ind < 0 or ind >= cantDadosInicial or usado[ind]);

    indices[i] = ind; // Por ejemplo, si pasamos por la iteración 2, y el usuario elige el dado de la posición 2, entonces queda indices[2] = 1 (por el ind-- que hicimos)

    usado[ind] = true;  // Acá se pone en true como dije, para que no se repita y cumpla el if

    dadosElegidos[i] = dadosInicial[ind];
     /* Guardamos el dado elegido en el array dadosElegidos. 
     Por ejemplo, dadosElegidos[0] (de la iteracción) va a valer lo que valga dadosInicial[ de la posicion 1 del indice], que puede valer 3 
     */

    
}

     int sumaSeleccionada = sumarVector(dadosElegidos, cantASumar); // Llama a la funcion de vectores.h y suma los dados elegidos por el usuario
        if (sumaSeleccionada == numeroObjetivo) {
            cout << "Combinación elegida: ";
            mostrarVector(dadosElegidos, cantASumar);
            rlutil::msleep(2000);
            cout << " Es correcta" << endl;
            int puntosRonda = numeroObjetivo * cantASumar; // Puntos de la ronda es el numero objetivo por la cantidad de dados que se eligieron
            puntosInicial += puntosRonda; // Se suman los puntos de la ronda al puntaje total del jugador inicial
            



                // En este if verdadero, se debe desarrollar la logica de que el jugador inicial le da los dados elegidos al oponente, y se los suma a su stock
                // y tambien, de que si se queda sin dados, es victoria y se termina el juego







        
        }                                           // Corrobora si la suma seleccionada es igual al numero objetivo
        else {
            cout << "Combinación elegida: ";
            mostrarVector(dadosElegidos, cantASumar);
            rlutil::msleep(2000);
            cout << " Es incorrecta" << endl;




            // en este else, hay que desarrollar la logica de que el jugador recibe un dado del oponente SI es que tiene más de uno





        }



        // Acá se repite todo lo anterior, pero para el jugador oponente
        // es mas que nada reemplazar las variables



        rlutil::anykey();
        cout << "Fin de la ronda " << ronda << endl;
        
    }
    cout << "Fin del juego. ¡Gracias por jugar!" << endl;
}





int decidirQuienEmpieza(string nombre1, string nombre2) {
    int dado_j1, dado_j2;

    
    do {
        rlutil::msleep(2000);
        cout << "Tirando dados para ver quien empieza..." << endl;
        

        // Cada jugador tira UN solo dado de 6 caras
        dado_j1 = (rand() % 6) + 1;
        dado_j2 = (rand() % 6) + 1;

        cout << nombre1 << " sacó un " << dado_j1 << endl;
        rlutil::msleep(2000);
        cout << nombre2 << " sacó un " << dado_j2 << endl;

        if (dado_j1 == dado_j2) {
            cout << "¡Empate! Se vuelve a tirar." << endl << endl;
            rlutil::msleep(2000);
        }

    } while (dado_j1 == dado_j2); // El bucle se repite si los dados son iguales

    
    if (dado_j1 > dado_j2) {
        return 0;
        // Gana el jugador 1
    } else {
        return 1; // Gana el jugador 2
        
    }
}

// Funcion para crear un dado de 12 caras.
int dadoDoceCaras() {
    return rand() % 12 + 1; // Crea un numero entre el 1 y el 12.

}

// Funcion para tirar los dados.
void tirarDados() { //Tira los dados, muestra el resultado y pregunta al jugador si quiere volver a tirar un dado.
    string opcion;

    do
    {
        int resultado = dadoDoceCaras();

        cout << " Al tirar un dado el resultado es: " << resultado << endl;
        cout << endl;

        cout << " ¿ Queres tirar otro dado ? " << endl;
        cin >> opcion;

    } while ( opcion == "s" || opcion == "S" );
}







int menuOpciones() { // Funcion que muestra el menu principal dl juego.
    int opciones;
    bool opcionValida = false;

    do {
        rlutil::cls();
        cout << "\n--- MENU DE OPCIONES ---\n";
        cout << "1. Jugar\n";
        cout << "2. Estadistica\n";
        cout << "3. Creditos\n";
        cout << "4. Reglamento\n";
        cout << "0. Salirl\n";
        cout << "Ingrese una opcion: ";
        cin >> opciones;

        if (cin.fail()) {
            cout << "Entrada invalida. Intente nuevamente.\n";
            cin.clear();
            cin.ignore(10000, '\n'); // Limpia el buffer de entrada para que no afecte a la siguiente entrada
            rlutil::msleep(1000);
            rlutil::cls();  // Duerme 1 segundo y limpia la pantalla (no afecta al menu)
        } else if (opciones >= 0 && opciones <= 4) {
            opcionValida = true;
        } else {
            cout << "La opcion " << opciones << " no es valida. Intente nuevamente.";
            rlutil::msleep(1000);
            rlutil::cls(); // Lo mismo que arriba
        }
    } while (!opcionValida);

    return opciones;

}








void reglamento() { // Funcion que muestra el reglamento del juego.
    std::cout << "\n=================  REGLAMENTO DEL JUEGO: ENFRENDADOS  =================\n";
    std::cout << "Enfrendados es un juego de dados para dos jugadores que combina el azar\n";
    std::cout << "con las matem�ticas. El objetivo es sumar la mayor cantidad de puntos\n";
    std::cout << "en un total de tres rondas.\n\n";

    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "REGLAS GENERALES:\n";
    std::cout << "- Cada jugador tiene seis dados de seis caras (dados stock).\n";
    std::cout << "- Adicionalmente, hay dos dados de doce caras que se usan entre rondas.\n";
    std::cout << "- Al comenzar el juego, cada jugador lanza un dado de 6 caras.\n";
    std::cout << "  Quien saque el valor m�s alto comienza la partida.\n";
    std::cout << "  En caso de empate, se repite la tirada.\n";

    std::cout << "\nDIN�MICA DE CADA RONDA:\n";
    std::cout << "- El jugador que inicia lanza los dos dados de 12 caras.\n";
    std::cout << "- Luego lanza los dados stock (dados de 6 caras que tenga en su poder).\n";
    std::cout << "- Los dados que tiene cada jugador se denominan \"dados stock\" y pueden\n";
    std::cout << "  variar de una ronda a otra.\n";

    std::cout << "\nPUNTAJE:\n";
    std::cout << "- Despu�s de ambos lanzamientos, se determina el puntaje basado en\n";
    std::cout << "  condiciones que combinan el azar y el uso de operaciones matem�ticas.\n";

    std::cout << "\nIMPORTANTE:\n";
    std::cout << "- El juego finaliza despu�s de 3 rondas y gana quien tenga m�s puntos.\n";
    std::cout << "- Las reglas completas de puntuaci�n se explican durante el juego.\n";
    std::cout << "=======================================================================\n\n";
}

void creditos() { // Funcion que muestra los creditos del juego.
    // Guardo los nombres, apellidos y numero de legajo de los participantes.
    cout << " CREDITOS DEL JUEGO " << endl;
    cout << endl;

    cout << " Nombre del grupo: Grupo 2 " << endl;
    cout << endl;

    cout << " Nombres, apellidos y legajos de los participantes " << endl;
    cout << endl;

    cout << " Miguel Guimar Salazar: 32530 " << endl;
    cout << " Ramiro Joel Kriguer: 33446 " << endl;
    cout << " Fernando Gabriel Quiroga: 33404 " << endl;
    cout << " Federico Wachenschwan: 22561 " << endl;

    cout << " MENCION ESPECIALES Para: " << endl;
    cout << endl;

    cout << " Íconos obtenidos de Freepik y logo hecho en Logo Maker. " << endl;
    cout << " Juego inventado por Angel Simón. Levemente inspirado en el juego Mafia. " << endl;
    cout << " Anexo " << endl;
}
