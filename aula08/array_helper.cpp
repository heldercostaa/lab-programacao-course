#include "array_helper.hpp"

#include <iostream>
#include <cstring>

int* criar_array(int tam) {
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    int* rand = new int[tam];
    for(int* p = rand; p != rand+tam; p++) {
        *p = std::rand() % 99 + 1;
    }
    
    return rand;
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
