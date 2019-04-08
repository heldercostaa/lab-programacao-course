#ifndef CONSOLE_HELPER_HPP
#define CONSOLE_HELPER_HPP

#include "quicksort.hpp"

#include <tuple>
#include <iostream>
#include <vector>

void limpa_tela();
void inicia_programa();
void anuncia_comeco(int instancia, int tam, int min, int max);

void barra_de_progresso(int progresso, int progresso_maximo);
bool ordenar_por_tempo(const std::tuple<Quicksort, long, bool>& a, const std::tuple<Quicksort, long, bool>& b);
void mostrar_resultados(std::vector<std::tuple<Quicksort,long,bool>> resultado);

#endif /* CONSOLE_HELPER_HPP */
