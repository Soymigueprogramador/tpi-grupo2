#pragma once
#include <string>



int decidirQuienEmpieza(std::string nombre1, std::string nombre2);
int menuOpciones();
void reglamento();
void creditos();
int dadoDoceCaras();
void tirarDados();
void jugarPartida(std::string jugadorInicial, std::string jugadorOponente, int dadosInicial[], int dadosOponente[], int& cantDadosInicial, int& cantDadosOponente, int& puntosInicial, int& puntosOponente);