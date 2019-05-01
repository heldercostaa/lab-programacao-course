//
//  main.cpp
//  class-15
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

/*
 Examples of pi[] construction:
 For the pattern "AAAA",
 pi[] is [0, 1, 2, 3]
 
 For the pattern "ABCDE",
 pi[] is [0, 0, 0, 0, 0]
 
 For the pattern "AABAACAABAA",
 pi[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
 
 For the pattern "AAACAAAAAC",
 pi[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4]
 
 For the pattern "AAABAAA",
 pi[] is [0, 1, 2, 0, 1, 2, 3]
 */
int* calcula_pi(const char* padrao) {
	
	long m = strlen(padrao);
	int* pi = new int[m];
	
	pi[0] = 0;
	for (int i = 1; i <= m-1; i++) {
		int k = i-1;
		while (true) {
			int l = pi[k];
			if (l == 0) {
				if (padrao[0] == padrao[i]) {
					pi[i] = 1; break;
				} else {
					pi[i] = 0; break;
				}
			} else {
				if (padrao[i] == padrao[l]) {
					pi[i] = l+1; break;
				} else {
					k = l - 1;
				}
			}
		}
	}
	
	return pi;
}

void kmp(const char* texto, const char* padrao, int* saida) {
	
	int* pi = calcula_pi(padrao);
	//printar_array(pi, strlen(padrao));
	
	long n = strlen(texto);
	long m = strlen(padrao);
	
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
