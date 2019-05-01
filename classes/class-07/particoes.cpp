//
//  particoes.cpp
//  class-07
//
//  Created by Helder Costa (github: heldercostaa) on 30/04/19.
//  Copyright © 2019. All rights reserved.
//

#include "particoes.hpp"
#include "array_helper.hpp"

#include <tuple>
#include <iostream>

std::tuple<int*, int*> particao_dupla(int* i, int* f, int* p) {
    
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

std::tuple<int*, int*> particao_tripla(int* i, int* f, int* p) {

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

