//
//  quicksort.cpp
//  class-09
//
//  Created by Helder Costa (github: heldercostaa) on 30/04/19.
//  Copyright © 2019. All rights reserved.
//

#include "quicksort.hpp"

#include <iostream>
#include <math.h>

Quicksort::Quicksort(enum_tipo t_tipo, enum_selecao t_selecao, enum_particionamento t_particionamento) {
	tipo = t_tipo;
	selecao = Selecao(t_selecao, t_particionamento);
	particionamento = Particionamento(t_particionamento);
}

void Quicksort::iniciar(int* i, int* f) {
	switch (tipo) {
		case RECURSIVO:
			if(debug) { std::cout << "Quicksort: Recursivo\n"; }
			quicksort_recursivo(i, f);
			break;
		case RECURSIVO_COM_LOOP:
			if(debug) { std::cout << "Quicksort: Recursivo com loop\n"; }
			quicksort_loop(i, f);
			break;
		case RECURSIVO_COM_LOOP_NA_MENOR_PARTE:
			if(debug) { std::cout << "Quicksort: Recursivo com loop na menor parte\n"; }
			quicksort_loop_menor_parte(i, f);
			break;
		default:
			std::cout << "Quicksort inválido\n";
			break;
	}
}

// Todo recursivo
void Quicksort::quicksort_recursivo(int* i, int* f) {
    
    if(i >= f) { return; }

	int meio = ceil((f-i)/2.0);
	int* pivo = selecao.selecionar(i, f, meio);

    auto iguais = particionamento.particionar(i, f, pivo);
	int* iguaisInicio = std::get<0>(iguais);
	int* iguaisFim = std::get<1>(iguais);
	
    quicksort_recursivo(i, iguaisInicio-1);
    quicksort_recursivo(iguaisFim+1, f);
}

// Trocando a chamada a direita por loop
void Quicksort::quicksort_loop(int* i, int* f) {

    while(true) {
        if(i < f) {

			int meio = ceil((f-i)/2.0);
			int* pivo = selecao.selecionar(i, f, meio);

            auto iguais = particionamento.particionar(i, f, pivo);
			int* iguaisInicio = std::get<0>(iguais);
			int* iguaisFim = std::get<1>(iguais);
			
            quicksort_loop(i, iguaisInicio-1);
            i = iguaisFim+1;
            pivo = iguaisFim+1;
        } else {
            break;
        }
    }
}

// Recursivo pelo menor lado
void Quicksort::quicksort_loop_menor_parte(int* i, int* f) {

    while(true) {
        if(i < f) {

			int meio = ceil((f-i)/2.0);
			int* pivo = selecao.selecionar(i, f, meio);

            auto iguais = particionamento.particionar(i, f, pivo);
            int* iguaisInicio = std::get<0>(iguais);
            int* iguaisFim = std::get<1>(iguais);
            
            long ladoEsquerdo = iguaisInicio-i;
            long ladoDireito = f-iguaisFim;
            
            if(ladoEsquerdo < ladoDireito) {
                quicksort_loop_menor_parte(i, iguaisInicio-1);
                i = iguaisFim+1;
                f = f;
                pivo = iguaisFim+1;
            }
            else {
                quicksort_loop_menor_parte(iguaisFim+1, f);
                i = i;
                f = iguaisInicio-1;
                pivo = i;
            }
        } else {
            break;
        }
    }
}

std::ostream& operator<<(std::ostream &os, const Quicksort& quicksort) {
	switch (quicksort.tipo) {
		case RECURSIVO:
			std::cout << "(RECURSIVO," << quicksort.selecao << "," << quicksort.particionamento << ")";
			break;
		case RECURSIVO_COM_LOOP:
			std::cout << "(RECURSIVO+LOOP," << quicksort.selecao << "," << quicksort.particionamento << ")";
			break;
		case RECURSIVO_COM_LOOP_NA_MENOR_PARTE:
			std::cout << "(RECURSIVO+LOOP MENOR," << quicksort.selecao << "," << quicksort.particionamento << ")";
			break;
	}
	return os;
}
