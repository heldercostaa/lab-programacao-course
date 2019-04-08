#include "quicksorts.hpp"
#include "particoes.hpp"
#include "selecoes.hpp"

#include <iostream>

// Todo recursivo
void quicksort_recursivo(int* i, int* f) {
    
    if(i >= f) { return; }

	int meio = (f-i+1) % 2 == 0 ? (int) ((f-i+1)/2) : (int) ((f-i+2)/2);
	//int* p = i; // Pivo sempre o primeiro elemento - Mais rápido
	int* p = selecao_hoare(i, f, meio); // Pivo pego apartir do algoritmo de Hoare - Mais lento

    auto iguais = particao_tripla(i, f, p);
	int* iguaisInicio = std::get<0>(iguais);
	int* iguaisFim = std::get<1>(iguais);
	
    quicksort_recursivo(i, iguaisInicio-1);
    quicksort_recursivo(iguaisFim+1, f);
}

// Trocando a chamada a direita por loop
void quicksort_loop(int* i, int* f, int* p) {
    
    while(true) {
        if(i < f) {
            auto iguais = particao_tripla(i, f, p);
			int* iguaisInicio = std::get<0>(iguais);
			int* iguaisFim = std::get<1>(iguais);
			
            quicksort_loop(i, iguaisInicio-1, i);
            i = iguaisFim+1;
            p = iguaisFim+1;
        } else {
            break;
        }
    }
}

// Recursivo pelo menor lado
void quicksort(int* i, int* f, int* p) {
    
    while(true) {
        if(i < f) {
            auto iguais = particao_tripla(i, f, p);
            int* iguaisInicio = std::get<0>(iguais);
            int* iguaisFim = std::get<1>(iguais);
            
            long ladoEsquerdo = iguaisInicio-i;
            long ladoDireito = f-iguaisFim;
            
            if(ladoEsquerdo < ladoDireito) {
                quicksort(i, iguaisInicio-1, i);
                i = iguaisFim+1;
                f = f;
                p = iguaisFim+1;
            }
            else {
                quicksort(iguaisFim+1, f, iguaisFim+1);
                i = i;
                f = iguaisInicio-1;
                p = i;
            }
        } else {
            break;
        }
    }
}
