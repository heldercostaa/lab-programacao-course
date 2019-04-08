#include "array_helper.hpp"

#include <iostream>
#include <cstring>

int** criar_array(int qtd, int tam) {
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    int *rand = new int[tam];
    for(int* p = rand; p != rand+tam; p++) {
        *p = std::rand() % 99 + 1;
    }
    
    int** vetores = new int*[qtd];
    for(int** v = vetores; v != vetores+qtd+1; v++) {
        int* copia = new int[tam];
        memcpy(copia, rand, tam*sizeof(int));
        *v = copia;
    }
    
    return vetores;
}

void printar_array(int *p, int tam) {
    
    for (int* q = p; q != p + tam; q++) {
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
