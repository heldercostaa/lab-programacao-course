//
//  main.cpp
//  class-13
//
//  Created by Helder Costa (github: heldercostaa) on 30/04/19.
//  Copyright © 2019. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <random>

void printar_texto(const char* i) {
	
	for (const char* q = i; *q != '\0'; q++) {
		std::cout << *q << " ";
	}
	std::cout << "\n";
}

void printar_array(int *i, int tam) {
	
	for (int* q = i; q != i + tam; q++) {
		std::cout << *q << " ";
	}
	std::cout << "\n";
}

char* texto_aleatorio(int tam) {
	
	srand(static_cast<unsigned int>(time(NULL)));
	
	char* texto = new char[tam];
	
	const char alfabeto[] =
	//"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	"abcdefghijklmnopqrstuvwxyz";
	//"0123456789"
	//"!@#$%&*()_-+=,./\\|'\"";
	
	for(int i = 0; i < tam; i++) {
		int indice_aleatorio = rand() % (sizeof(alfabeto) - 1);
		texto[i] = alfabeto[indice_aleatorio];
	}
	
	return texto;
}

void subseq_intuitivo(const char* texto, const char* padrao, int* saida) {
	
	int s = 0;
	
	for (int i = 0; texto[i] != '\0'; i++) {
		bool achou = true;
		for (int j = 0; padrao[j] != '\0'; j++) {
			if (texto[i+j] != padrao[j]) {
				achou = false;
				break;
			}
		}
		if (achou) {
			saida[s] = i;
			s++;
		}
	}
	
	saida[s] = -1;
}

int* calcula_pi(const char* padrao) {
	
	int m = strlen(padrao);
	int* pi = new int[m];
	
	return pi;
}

void kmp(const char* texto, const char* padrao, int* saida) {
	
	int* pi = calcula_pi(padrao);
	//printar_array(pi, strlen(padrao));
	
	int n = strlen(texto);
	int m = strlen(padrao);
	
	int i = 0, j = 0, s = 0;
	
	while (i < n) {
		if (texto[i] != padrao[j]) {
			if (j == 0) {
				i++;
			} else {
				j = pi[j-1];
			}
		} else {
			if (j == m-1) {
				saida[s] = i;
				s++;
				j = pi[j];
				i++;
			} else {
				i++;
				j++;
			}
		}
	}
	
	saida[s] = -1;
	
}

int main() {
	
	int tam = 10;
	const char* texto = "abaa";//texto_aleatorio(tam);
	const char* padrao = "a";
	
	std::cout << "Texto aleatório: ";
	printar_texto(texto);
	std::cout << "Padrão: " << padrao << std::endl;
	
	int* saida = new int[tam+1];
	saida[0] = -1;
	
	//subseq_intuitivo(texto, padrao, saida);
	kmp(texto, padrao, saida);
	
	bool achou_padrao = false;
	for(int i = 0; saida[i] != -1; i++) {
		std::cout << "Padrão encontrado no índice: " << saida[i] << std::endl;
		achou_padrao = true;
	}
	
	if(!achou_padrao) { std::cout << "Padrão não encontrado no texto informado."; }
	
}
