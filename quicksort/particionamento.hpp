#ifndef PARTICIONAMENTO_HPP
#define PARTICIONAMENTO_HPP

#include "enum.hpp"

#include <tuple>
#include <iostream>

extern bool debug;

class Particionamento {
	enum_particionamento particionamento;
	
public:
	Particionamento(enum_particionamento t_particionamento);
	std::tuple<int*, int*> particionar(int* i, int* f, int* p);

	std::tuple<int*, int*> particionamento_duplo(int* i, int* f, int* p);
	std::tuple<int*, int*> particionamento_triplo(int* i, int* f, int* p);
	
	friend std::ostream& operator<<(std::ostream &os, const Particionamento& n);
};

#endif /* PARTICIONAMENTO_HPP */
