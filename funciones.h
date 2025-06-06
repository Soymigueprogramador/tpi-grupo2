#pragma once
#include <string>

struct Jugadores {
    std::string nombre;
    int puntajeTotal = 0; 
    int dadosStock = 6;   
};

int decidirQuienEmpieza(Jugadores jugadores[]);
int menuOpciones();
void reglamento();
void creditos();
int dadoDoceCaras();
void tirarDados();