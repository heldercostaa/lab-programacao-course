#include "array_helper.hpp"

#include <iostream>
#include <cstring>
#include <random>

int* criar_array(int tam, int min, int max) {
	
	std::random_device rd;
	std::mt19937 ger(rd());
	std::uniform_int_distribution<int> gerar(min, max);
	
    srand(static_cast<unsigned int>(time(NULL)));
    
    int* rand = new int[tam];
    for(int* p = rand; p != rand+tam; p++) {
        *p = gerar(ger);
    }
    
    return rand;
}

bool array_ordenado(int *i, int tam) {
	
	for(int* p = i; p < i+tam-1; p++) {
		if(*p > *(p+1)) { return false; }
	}
	return true;
}

void printar_array(int *i, int tam) {
    
    for (int* q = i; q != i + tam; q++) {
        *q < 10 ? std::cout << " " : std::cout << "";
        std::cout << *q << " ";
    }
    std::cout << "\n";
}

void trocar_elementos(int* p, int* q) {
    
    int temp = *p;
    *p = *q;
    *q = temp;
}
