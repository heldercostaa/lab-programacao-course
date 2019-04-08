#ifndef SELECAO_HPP
#define SELECAO_HPP

#include "enum.hpp"
#include "particionamento.hpp"

#include <iostream>

extern bool debug;

class Selecao {
	
	Particionamento particionamento = Particionamento(TRIPLO);
	
public:
	enum_selecao selecao;
	
	Selecao(enum_selecao t_selecao, enum_particionamento t_particionamento);
	int* selecionar(int* i, int* f, int k);

	static int* selecao_fixa(int* i, int* f);
	int* selecao_aleatoria(int* i, int* f);
	int* selecao_hoare(int* i, int* f, int k);
	int* selecao_bfprt(int* i, int* f, int k);

	friend std::ostream& operator<<(std::ostream &os, const Selecao& n);
};

#endif /* SELECAO_HPP */
