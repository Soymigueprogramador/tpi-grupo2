#pragma once
#include <string>


void mostrarPortada();
int decidirQuienEmpieza(std::string nombre1, std::string nombre2);
int menuOpciones();
void reglamento();
void creditos();
int dadoDoceCaras();
void tirarDados();
void jugarPartida(std::string jugadorInicial, std::string jugadorOponente, int dadosInicial[], int dadosOponente[], int& cantDadosInicial, int& cantDadosOponente, int& puntosInicial, int& puntosOponente);

void estadisticasDelJuego(std::string jugador1, std::string jugador2, int puntos1, int puntos2, int dados1, int dados2, std::string nombreMejorHistorico, int puntosMejorHistorico, bool huboPartidaJugada);
