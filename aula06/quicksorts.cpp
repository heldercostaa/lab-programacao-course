#include "quicksorts.hpp"
#include "particoes.hpp"

#include <iostream>

void quicksort_recursivo(int* i, int* f, int* p) {
    
    if(i >= f) { return; }
    auto iguais = particao_tripla(i, f, p);
	int* iguaisInicio = std::get<0>(iguais);
	int* iguaisFim = std::get<1>(iguais);
	
    quicksort_recursivo(i, iguaisInicio-1, i);
    quicksort_recursivo(iguaisFim+1, f, iguaisFim+1);
}

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
