//
//  selecao.cpp
//  class-08
//
//  Created by Helder Costa (github: heldercostaa) on 30/04/19.
//  Copyright © 2019. All rights reserved.
//

#include "selecao.hpp"
#include "array_helper.hpp"

#include <math.h>
#include <iostream>

Selecao::Selecao(enum_selecao t_selecao, enum_particionamento t_particionamento) {
	selecao = t_selecao;
	particionamento = Particionamento(t_particionamento);
}

int* Selecao::selecionar(int *i, int *f, int k) {
	switch (selecao) {
		case FIXA:
			if(debug) { std::cout << "Seleção: Fixa\n"; }
			return selecao_fixa(i);
			break;
		case HOARE:
			if(debug) { std::cout << "Seleção: Hoare\n"; }
			return selecao_hoare(i, f, k);
			break;
		case BFPRT:
			if(debug) { std::cout << "Seleção: BFPRT\n"; }
			return selecao_bfprt(i, f, k);
			break;
		default:
			std::cout << "Seleção inválida\n";
			break;
	}
}

int* Selecao::selecao_fixa(int* i) {

	return i;
}

int* Selecao::selecao_hoare(int* i, int* f, int k) {
	
	auto p = particionamento.particionar(i, f, i);
	int* pos1 = std::get<0>(p);
	int* pos2 = std::get<1>(p);

	if(k < (pos1-i)+1) {
		pos1--;
		return selecao_hoare(i, pos1, k);
	}
	if(k > (pos2-i)+1) {
		pos2++;
		return selecao_hoare(pos2, f, (int) (k-(pos2-i)));
	}

	return (k+i)-1;
}

int* Selecao::selecao_bfprt(int* i, int* f, int k) {

	int tam = (int)(f-i)+1;
	int* ultima_mediana = i;

	// Passo a
	if(tam <= 5) {
		selecao_hoare(i, f, k);
		return i+(k-1);
	} 
	// Passo b e c
	else {
		int* i_intervalo = i;
		int* f_intervalo = i+4;
		while(i_intervalo <= f) {
			int tam_intervalo = (int)(f_intervalo-i_intervalo)+1;
			int meio_intervalo = ceil(tam_intervalo/2.0);
			selecao_hoare(i_intervalo, f_intervalo, meio_intervalo);
      
			int* posicaoMediana = i_intervalo+(meio_intervalo-1);
			trocar_elementos(ultima_mediana, posicaoMediana);
			
			++ultima_mediana;
			i_intervalo += 5;
			f_intervalo += 5;
			if(f_intervalo > f) { f_intervalo = f; } 
		}
	}
	--ultima_mediana;

	// Passo d
	int tam_medianas = (int)(ultima_mediana-i)+1;
	int meio_medianas = ceil(tam_medianas/2.0);
	int* pivo = selecao_bfprt(i, ultima_mediana, meio_medianas);

	// Passo e
	auto p = particionamento.particionar(i, f, pivo);
	int* pos1 = std::get<0>(p);
	int* pos2 = std::get<1>(p);
	
	// Passo f
	if(k < (pos1-i)+1) {
		return selecao_bfprt(i, pos1-1, k);
	}
	if(k > (pos2-i)+1) {
		return selecao_bfprt(pos2+1, f, (int) (k-(pos2+1-i)));
	}

	return i+(k-1);
}

std::ostream& operator<<(std::ostream &os, const Selecao& selecao) {
	switch (selecao.selecao) {
		case FIXA:
			std::cout << "FIXA";
			break;
		case HOARE:
			std::cout << "HOARE";
			break;
		case BFPRT:
			std::cout << "BFPRT";
			break;
	}
	return os;
}
