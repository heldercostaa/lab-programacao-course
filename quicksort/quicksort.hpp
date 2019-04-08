#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "enum.hpp"
#include "selecao.hpp"
#include "particionamento.hpp"

#include <iostream>

extern bool debug;

class Quicksort {
	enum_tipo tipo;
public:
	Selecao selecao = Selecao(BFPRT, TRIPLO);
	Particionamento particionamento = Particionamento(TRIPLO);
	Quicksort(enum_tipo t_tipo, enum_selecao t_selecao, enum_particionamento t_particionamento);
	void iniciar(int* i, int* f);

	void qs_via_indices(int* i, int* f);
	void qs_via_ponteiros(int* i, int* f);
	void qs_tempo(int* i, int* f);
	void qs_memoria(int* i, int* f);
	
	friend std::ostream& operator<<(std::ostream &os, const Quicksort& n);
};

#endif /* QUICKSORT_HPP */
