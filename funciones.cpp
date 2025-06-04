#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
#include <limits>
#include <limits>
using namespace std;

int decidirQuienEmpieza(Jugadores jugadores[]) {
    srand(time(NULL)); // semilla aleatoria

    // Dados jugador 1
    int dado1_j1 = rand() % 6 + 1;
    int dado2_j1 = rand() % 6 + 1;
    int dado3_j1 = rand() % 6 + 1;
    jugadores[0].suma_dados = dado1_j1 + dado2_j1 + dado3_j1;

    // Dados jugador 2
    int dado1_j2 = rand() % 6 + 1;
    int dado2_j2 = rand() % 6 + 1;
    int dado3_j2 = rand() % 6 + 1;
    jugadores[1].suma_dados = dado1_j2 + dado2_j2 + dado3_j2;

    cout << jugadores[0].nombre << " sacó " << dado1_j1 << ", " << dado2_j1 << " y " << dado3_j1
         << " (Total: " << jugadores[0].suma_dados << ")\n";
    cout << jugadores[1].nombre << " sacó " << dado1_j2 << ", " << dado2_j2 << " y " << dado3_j2
         << " (Total: " << jugadores[1].suma_dados << ")\n";

    if (jugadores[0].suma_dados > jugadores[1].suma_dados)
        return 0;
    else if (jugadores[1].suma_dados > jugadores[0].suma_dados)
        return 1;
    else {
        // Empate
        int desempate_j1 = rand() % 6 + 1;
        int desempate_j2 = rand() % 6 + 1;
        cout << "Empate! Tirando dado de desempate...\n";
        cout << jugadores[0].nombre << " sacó " << desempate_j1 << "\n";
        cout << jugadores[1].nombre << " sacó " << desempate_j2 << "\n";
        return (desempate_j1 > desempate_j2) ? 0 : 1;
    }
}

int menuOpciones() {
    int opciones;
    bool opcionValida = false;

    do {
        cout << "\n--- MENU DE OPCIONES ---\n";
        cout << "1. Jugar\n";
        cout << "2. Estadistica\n";
        cout << "3. Creditos\n";
        cout << "4. Reglamento\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opciones;

        if (opciones >= 0 && opciones <= 4) {
            opcionValida = true;
        } else {
            cout << "La opcion " << opciones << " no es valida. Intente nuevamente.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!opcionValida);

    return opciones;

}
void reglamento() {
    std::cout << "\n=================  REGLAMENTO DEL JUEGO: ENFRENDADOS  =================\n";
    std::cout << "Enfrendados es un juego de dados para dos jugadores que combina el azar\n";
    std::cout << "con las matemáticas. El objetivo es sumar la mayor cantidad de puntos\n";
    std::cout << "en un total de tres rondas.\n\n";

    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "REGLAS GENERALES:\n";
    std::cout << "- Cada jugador tiene seis dados de seis caras (dados stock).\n";
    std::cout << "- Adicionalmente, hay dos dados de doce caras que se usan entre rondas.\n";
    std::cout << "- Al comenzar el juego, cada jugador lanza un dado de 6 caras.\n";
    std::cout << "  Quien saque el valor más alto comienza la partida.\n";
    std::cout << "  En caso de empate, se repite la tirada.\n";

    std::cout << "\nDINÁMICA DE CADA RONDA:\n";
    std::cout << "- El jugador que inicia lanza los dos dados de 12 caras.\n";
    std::cout << "- Luego lanza los dados stock (dados de 6 caras que tenga en su poder).\n";
    std::cout << "- Los dados que tiene cada jugador se denominan \"dados stock\" y pueden\n";
    std::cout << "  variar de una ronda a otra.\n";

    std::cout << "\nPUNTAJE:\n";
    std::cout << "- Después de ambos lanzamientos, se determina el puntaje basado en\n";
    std::cout << "  condiciones que combinan el azar y el uso de operaciones matemáticas.\n";

    std::cout << "\nIMPORTANTE:\n";
    std::cout << "- El juego finaliza después de 3 rondas y gana quien tenga más puntos.\n";
    std::cout << "- Las reglas completas de puntuación se explican durante el juego.\n";
    std::cout << "=======================================================================\n\n";
}



