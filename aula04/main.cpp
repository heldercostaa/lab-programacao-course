#include <iostream>
#include <tuple>

using namespace std;

void printar_array(int *p, int n) {

	for (int* q = p; q != p + n; q++) {
		cout << *q << " ";
	}
	cout << "\n";
}

void trocar_elementos(int* p, int* q) {

	int temp = *p;
	*p = *q;
	*q = temp;
}

int* particionar_duplo(int* i, int* f, int* p) {

	trocar_elementos(i, p);
	int* m = i;

	for (int* j = i; j != f+1; j++) {
		if(*j < *i) {
			trocar_elementos(j, m+1);
			m++;
		}
	}
	trocar_elementos(i, m);
	
	return m;
}

tuple<int*, int*> particionar_triplo(int* i, int* f, int* p) {
    
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
    
    return make_tuple(m, ig);
}

int main() {

	int v[10] = {9,8,7,6,2,6,3,2,6,5};
	int n = sizeof(v)/sizeof(*v);

	int* i = v;
	int* f = v+n-1;
	int* p = &v[3];

	cout << "Pivô: " << *p << "\n";
	printar_array(i, n);
	
    auto iguais = particionar_triplo(i, f, p);
    int* iguaisInicio = get<0>(iguais);
    int* iguaisFim = get<1>(iguais);
	
    printar_array(i, n);
	cout << "Ponteiro para primeiro igual: " << *iguaisInicio << "\n";
    cout << "Ponteiro para último igual: " << *iguaisFim << "\n";
    cout << "Quantidade de iguais: " << iguaisFim-iguaisInicio+1 << endl;
	
}
