#include <iostream>
#include <cstring>
#include <random>

void printar_array(const char* i, int tam) {
    
    for (const char* q = i; q != i + tam; q++) {
        *q < 10 ? std::cout << " " : std::cout << "";
        std::cout << *q << " ";
    }
    std::cout << "\n";
}

char* texto_aleatorio(int tam) {

	srand(static_cast<unsigned int>(time(NULL)));
	
	char* texto = new char[tam];

	const char alfabeto[] = 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789"
		"!@#$%&*()_-+=,./\\|'\"";

	for(int i = 0; i < tam; i++) {
		int indice_aleatorio = rand() % (sizeof(alfabeto) - 1);
		texto[i] = alfabeto[indice_aleatorio];
	}

	return texto;
}

void subseq_intuitivo(const char* texto, const char* padrao, int* saida) {
	
	int s = 0;

	for(int i = 0; texto[i] != '\0'; i++) {

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
	}
	
	saida[s] = -1;
}

int main() {
	
	int tam = 10;
	const char* texto = texto_aleatorio(tam);
	const char* padrao = "a";
	
	std::cout << "Texto aleatório: ";
	printar_array(texto, tam);
	std::cout << "Padrão: " << padrao << std::endl;
	
	int* saida = new int[tam+1];
	
	subseq_intuitivo(texto, padrao, saida);
	
	bool achou_padrao = false;
	for(int i = 0; saida[i] != -1; i++) {
		std::cout << "Padrão encontrado no índice: " << saida[i] << std::endl;
		achou_padrao = true;
	}

	if(!achou_padrao) { std::cout << "Padrão não encontrado no texto informado."; }

}
