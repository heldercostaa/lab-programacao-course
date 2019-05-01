//
//  main.cpp
//  class-09
//
//  Created by Helder Costa (github: heldercostaa) on 30/04/19.
//  Copyright © 2019. All rights reserved.
//

#include "array_helper.hpp"
#include "quicksort.hpp"
#include "particionamento.hpp"

#include <iostream>
#include <chrono>
#include <map>

bool debug = false;

int main() {
	
	int tam = 1000000;
	int min = 0;
	int max = 9999999;
	int* array = criar_array(tam, min, max);
	
	for (int t_tipo = RECURSIVO; t_tipo <= RECURSIVO_COM_LOOP_NA_MENOR_PARTE; t_tipo++) {
		for (int t_selecao = FIXA; t_selecao <= BFPRT; t_selecao++) {
			for (int t_particionamento = DUPLO; t_particionamento <= TRIPLO; t_particionamento++) {
				
				enum_tipo tipo = (enum_tipo) t_tipo;
				enum_selecao selecao = (enum_selecao) t_selecao;
				enum_particionamento particionamento = (enum_particionamento) t_particionamento;
				
				Quicksort qs = Quicksort(tipo, selecao, particionamento);
				
				int* i = new int[tam];
				int* f = i+(tam-1);
				memcpy(i, array, tam*sizeof(int));
				
				std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
				qs.iniciar(i, f);
				std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
				
				long tempo = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
				std::cout << qs << " executou em: " << tempo << "ms\n";
				
				//printar_array(i, tam);
			}
		}
	}
}
