#ifndef SELECAO_HPP
#define SELECAO_HPP

#include "enum.hpp"
#include "particionamento.hpp"

#include <iostream>

extern bool debug;

class Selecao {
	enum_selecao selecao;
	Particionamento particionamento = Particionamento(TRIPLO);
	
public:
	Selecao(enum_selecao t_selecao, enum_particionamento t_particionamento);
	int* selecionar(int* i, int* f, int k);

	int* selecao_fixa(int* i);
	int* selecao_aleatoria(int* i, int* f);
	int* selecao_hoare(int* i, int* f, int k);
	int* selecao_bfprt(int* i, int* f, int k);

	friend std::ostream& operator<<(std::ostream &os, const Selecao& n);
};

#endif /* SELECAO_HPP */
