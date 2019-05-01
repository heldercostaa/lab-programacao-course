//
//  quicksort.hpp
//  class-09
//
//  Created by Helder Costa (github: heldercostaa) on 30/04/19.
//  Copyright © 2019. All rights reserved.
//

#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "enum.hpp"
#include "selecao.hpp"
#include "particionamento.hpp"

#include <iostream>

extern bool debug;

class Quicksort {
	enum_tipo tipo;
	Selecao selecao = Selecao(BFPRT, TRIPLO);
	Particionamento particionamento = Particionamento(TRIPLO);
public:
	Quicksort(enum_tipo t_tipo, enum_selecao t_selecao, enum_particionamento t_particionamento);
	void iniciar(int* i, int* f);

	void quicksort_recursivo(int* i, int* f);
	void quicksort_loop(int* i, int* f);
	void quicksort_loop_menor_parte(int* i, int* f);
	
	friend std::ostream& operator<<(std::ostream &os, const Quicksort& n);
};

#endif /* QUICKSORT_HPP */
