#ifndef REGLAMENTO_H_INCLUDED
#define REGLAMENTO_H_INCLUDED

#include <iostream>

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


#endif //REGLAMENTO_H_INCLUDED 