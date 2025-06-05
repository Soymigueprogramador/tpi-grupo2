#pragma once
#include <string>

struct Jugadores {
    std::string nombre;
    int suma_dados;
};

int decidirQuienEmpieza(Jugadores jugadores[]);
int menuOpciones();
void reglamento();
void creditos();