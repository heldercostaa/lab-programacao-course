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
		case VIA_INDICES:
			if(debug) { std::cout << "Quicksort: Recursivo via indices\n"; }
			qs_via_indices(i, f);
			break;
		case VIA_PONTEIROS:
			if(debug) { std::cout << "Quicksort: Recursivo via ponteiros\n"; }
			qs_via_ponteiros(i, f);
			break;
//		case OTIMIZANDO_TEMPO:
//			if(debug) { std::cout << "Quicksort: Otimizando tempo\n"; }
//			qs_tempo(i, f);
//			break;
		case MEMORIA:
			if(debug) { std::cout << "Quicksort: Otimizando tempo e memoria\n"; }
			qs_memoria(i, f);
			break;
		default:
			std::cout << "Quicksort invalido\n";
			break;
	}
}

void Quicksort::qs_via_indices(int* i, int* f) {

	int a = 0;
	int b = (int) (f-i);

    if(a >= b) { return; }

	int meio = ceil((b-a)/2.0);
	int pivo = (int) (selecao.selecionar(i+a, i+b, meio)-i);

    auto iguais = particionamento.particionar(i+a, i+b, i+pivo);
	int inicio_iguais = (int) (std::get<0>(iguais)-i);
	int fim_iguais = (int) (std::get<1>(iguais)-i);
	
    qs_via_indices(i+a, i+inicio_iguais-1);
    qs_via_indices(i+fim_iguais+1, i+b);
}

void Quicksort::qs_via_ponteiros(int* i, int* f) {
	
    if(i >= f) { return; }

	int meio = ceil((f-i)/2.0);
	int* pivo = selecao.selecionar(i, f, meio);

    auto iguais = particionamento.particionar(i, f, pivo);
	int* inicio_iguais = std::get<0>(iguais);
	int* fim_iguais = std::get<1>(iguais);
	
    qs_via_ponteiros(i, inicio_iguais-1);
    qs_via_ponteiros(fim_iguais+1, f);
}

//void Quicksort::qs_tempo(int* i, int* f) {
//
//    while(i < f) {
//		int meio = ceil((f-i)/2.0);
//		int* pivo = selecao.selecionar(i, f, meio);
//
//		auto iguais = particionamento.particionar(i, f, pivo);
//		int* inicio_iguais = std::get<0>(iguais);
//		int* fim_iguais = std::get<1>(iguais);
//
//		qs_tempo(i, inicio_iguais-1);
//		i = fim_iguais+1;
//    }
//}

void Quicksort::qs_memoria(int* i, int* f) {

    while(i < f) {
		int meio = ceil((f-i)/2.0);
		int* pivo = selecao.selecionar(i, f, meio);

		auto iguais = particionamento.particionar(i, f, pivo);
		int* inicio_iguais = std::get<0>(iguais);
		int* fim_iguais = std::get<1>(iguais);
		
		long esquerdo = inicio_iguais-i;
		long direito = f-fim_iguais;
		
		if(esquerdo < direito) {
			qs_memoria(i, inicio_iguais-1);
			i = fim_iguais+1;
		} else {
			qs_memoria(fim_iguais+1, f);
			f = inicio_iguais-1;
		}
    }
}

std::ostream& operator<<(std::ostream &os, const Quicksort& quicksort) {
	switch (quicksort.tipo) {
		case VIA_INDICES:
//			std::cout << "Recursivo via indices";
			std::cout << "Indices";
			break;
		case VIA_PONTEIROS:
//			std::cout << "Recursivo via ponteiros";
			std::cout << "Ponteiros";
			break;
//		case TEMPO:
////			std::cout << "Otimizando tempo";
//			std::cout << "Tempo";
//			break;
		case MEMORIA:
//			std::cout << "Otimizando tempo e memoria";
			std::cout << "Memoria";
			break;
		default:
			std::cout << "Quicksort inválido";
			break;
			
	}
	return os;
}
