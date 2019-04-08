#include <iostream>

using namespace std;

void printar_array(int *p, int n) {

	int* fim = p + n;
	for ( ; p != fim; ++p) {
		cout << *p;
	}
	cout << "\n";
}

bool sao_iguais(const char *r, const char *s) {

	while(*r != '\0' || *s != '\0') {
		if (*s != *r) { return false; }
		r++;
		s++;
	}

	return true;
}

void inverter(int* v, int n) {

	// Cria ponteiro para um array vazio de tamanho n
	int* p_copia = new int[n];
	int* u = v;

	int* fim = v + n;

	// Copia o array v em um outro array, que é apontado pelo ponteiro p_copia
	while(u != fim) {
		*p_copia = *u;
		u++;
		p_copia++;
	}

	// Precisamos disso pois no final do while acima, o array p_copia apontará para a posição n, que não existe
	p_copia--;

	// Substitui os elementos que v aponta pelos elementos que p_copia aponta.
	// Porém v sobe do indice 0 a n-1 e p_copia desce do indice n-1 a 0
	while(v != fim) {
		*v = *p_copia;
		v++;
		p_copia--;
	}
	
}


int main() {
	// Faz imprimir True ou False ao invés de 1 ou 0.
	cout.setf(ios::boolalpha);
	//std::cout.setf(std::ios::boolalpha);

	// Questão 01
	cout << "\n" << "\n";

	const char* r = "helder";
	const char* s = "helder";
	bool igual = sao_iguais(r, s);

	cout << "### PRIMEIRA QUESTÃO ###" "\n";
	printf("'%s' é igual a '%s'?\n", r, s);
	cout << igual << "\n";


	// Questão 02
	cout << "\n" << "\n";

	int n = 10;
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	int* v = array;
	
	cout << "### SEGUNDA QUESTÃO ###" "\n";
	cout << "Array a ser invertido: ";
	printar_array(v, n);
	inverter(v, n);
	cout << "Array invertido: ";
	printar_array(v, n);


	// Fim
	cout << "\n" << "\n";
}
