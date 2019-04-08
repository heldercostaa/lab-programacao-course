#include "array_helper.hpp"

#include <iostream>

void subseq_intuitivo(const char* texto, const char* padrao, int* saida) {
	
	int i = 0;
	int s = 0;
	
	while(texto[i] != '\0') {
		
		int t = i;
		int p = 0;
		
		while(padrao[p] != '\0' && (texto[t] == padrao[p])) {
			t++;
			p++;
		}
		
		if(padrao[p] == '\0') {
			saida[s] = i;
			s++;
		}
		
		i++;
	}
	
	saida[s] = -1;
}

int main() {
	
	const char* texto = "ABDABCDABCB";
	const char* padrao = "ABC";
	
	int tam = 11 + 1;
	int* saida = new int[tam];
	
	subseq_intuitivo(texto, padrao, saida);
	
	for(int i = 0; saida[i] != -1; i++) {
		std::cout << "Padrão encontrado no índice: " << saida[i] << std::endl;
	}
	
}
