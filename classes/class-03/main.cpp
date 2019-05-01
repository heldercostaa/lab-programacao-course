//
//  main.cpp
//  class-03
//
//  Created by Helder Costa (github: heldercostaa) on 30/04/19.
//  Copyright © 2019. All rights reserved.
//

// Dica: Usar memcpy para copiar eficientemente um vetor para outro

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printar_array(int* p, int n) {
    if (*p == '\0') {
        cout << "Array vazio\n";
        return;
    }
    
    for (int* q = p; q != p + n; q++) {
        cout << *q << " ";
    }
    cout << "\n";
}

int main() {
	
	// PRIMEIRA QUESTÃO
    int n = 1;
    int *v = new int[n];
    int x;
    int qtdElementos = 0;

    while(true) {
        cout << "Entre número: ";
        cin >> x;
        if (x < 0) { break; }

        *(v+qtdElementos) = x;
        qtdElementos++;

        if (qtdElementos == n) {
            cout << "\nDobrando array de " << n << " para " << 2*n << "\n\n";
            n *= 2;
            int* q = new int[n];
            memcpy(q, v, qtdElementos*sizeof(int));
            delete[] v;
            v = q;
        }
    };

    printar_array(v, qtdElementos);
	
	// SEGUNDA QUESTÃO
	int m;
//	cout << "Informe 'm': ";
//	cin >> m;
//	
//	int** T = new int*[3];
//	
//	*T[0] = {0};
//	*T[1] = {1};
//	*T[2] = {2};
//	
//	cout << *T[0] << *T[1] << *T[1];
	
}
