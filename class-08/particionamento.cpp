//
//  particionamento.cpp
//  class-08
//
//  Created by Helder Costa (github: heldercostaa) on 30/04/19.
//  Copyright © 2019. All rights reserved.
//

#include "particionamento.hpp"
#include "array_helper.hpp"

#include <iostream>

Particionamento::Particionamento(enum_particionamento t_particionamento) {
	particionamento = t_particionamento;
}

std::tuple<int*, int*> Particionamento::particionar(int *i, int *f, int *p) {
	switch (particionamento){
		case DUPLO:
			if(debug) { std::cout << "Particionamento: Duplo\n"; }
			return particionamento_duplo(i, f, p);
			break;
		case TRIPLO:
			if(debug) { std::cout << "Particionamento: Triplo\n"; }
			return particionamento_triplo(i, f, p);
			break;
		default:
			if(debug) { std::cout << "Particionamento inválido\n"; }
			break;
	}
}

std::tuple<int*, int*> Particionamento::particionamento_duplo(int* i, int* f, int* p) {

    int* m = i;
    
    trocar_elementos(i, p);
    for (int* j = i; j != f+1; j++) {
        if(*j < *i) {
            trocar_elementos(j, m+1);
            m++;
        }
    }
    trocar_elementos(i, m);
    
    return std::make_tuple(m, m);
}

std::tuple<int*, int*> Particionamento::particionamento_triplo(int* i, int* f, int* p) {

    int* m = i;
    int* ig = i;
    
    trocar_elementos(i, p);
    for (int* j = i+1; j != f+1; j++) {
        
        int pivo = *i;
        
        if(*j == pivo) {
            ig++;
            trocar_elementos(j, ig);
        } else if(*j < pivo) {
            m++;
            ig++;
            trocar_elementos(ig, j);
            trocar_elementos(m, ig);
        }
    }
    trocar_elementos(i, m);
    
    return std::make_tuple(m, ig);
}

std::ostream& operator<<(std::ostream &os, const Particionamento& particionamento) {
	switch (particionamento.particionamento){
		case DUPLO:
			std::cout << "DUPLO";
			break;
		case TRIPLO:
			std::cout << "TRIPLO";
			break;
	}
	return os;
}
