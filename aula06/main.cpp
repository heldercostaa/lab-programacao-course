#include "array_helper.hpp"
#include "quicksorts.hpp"

#include <iostream>
#include <ctime>

int main() {
	
	// Caso1: Recursivo
	// Caso2: Loop e Recursivo
	// Caso3: Loop e Recursivo na Menor Parte
	bool caso1 = true;
	bool caso2 = true;
	bool caso3 = true;
	
	int qtd = 0;
	caso1 ? qtd++ : qtd;
	caso2 ? qtd++ : qtd;
	caso3 ? qtd++ : qtd;
	
    int tam = 10000;
    int** v = criar_array(qtd, tam);
	
	//std::cout << "Antes: "; printar_array(v[1], tam);
	
	for(int c = 1; c <= qtd; c++) {
		
		int* i = v[c];
		int* f = v[c]+tam-1;
		int* p = v[c];
		
		std::string nomeCaso;
		int execucaoPorLoop = 0;
		
		clock_t inicio;
		clock_t fim;
		
		inicio = clock();
		if(caso1 && execucaoPorLoop < 1) {
			nomeCaso = "1";
			quicksort_recursivo(i, f, p);
			caso1 = false;
			execucaoPorLoop++;
		}
		if(caso2 && execucaoPorLoop < 1) {
			nomeCaso = "2";
			quicksort_loop(i, f, p);
			caso2 = false;
			execucaoPorLoop++;
		}
		if(caso3 && execucaoPorLoop < 1) {
			nomeCaso = "3";
			quicksort(i, f, p);
			caso3 = false;
			execucaoPorLoop++;
		}
		fim = clock();
		
		double tempo;
		std::string medida;
		if(tam > 287000) {
			tempo = double(fim - inicio) / CLOCKS_PER_SEC;
			medida = " segundos.";
		} else {
			tempo = double(fim - inicio);
			medida = " clocks.";
		}
		
		std::cout << "Caso '" << nomeCaso << "' executou em " << tempo << medida << std::endl;
	}
	
//	std::cout << "Depois: "; printar_array(v[1], tam);
}
