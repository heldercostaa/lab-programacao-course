#include <iostream>

using namespace std;

int* criar_array(int n) {
    int *v = new int[n];
    for(int* p = v; p != v+n; p++) {
        *p = rand() % 99 + 1;
    }
    return v;
}

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

int* particionar(int* i, int* f, int* p) {
    
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

void quicksort_loop(int* i, int* f, int* p) {

    while(true) {
        if(i < f) {
            p = particionar(i, f, p);
            quicksort_loop(i, p-1, i);
            i = p+1;
            p = p+1;
        } else {
            break;
        }
    }
}

void quicksort_rec(int* i, int* f, int* p) {

     if(i >= f) { return; }
     p = particionar(i, f, p);
     quicksort_rec(i, p-1, i);
     quicksort_rec(p+1, f, p+1);
}

int main() {
    
    int n = 100000;
    int* v = criar_array(n);
    int* u = new int[n];
    memcpy(u, v, n*sizeof(int));
    
    int* i1 = v;
    int* f1 = v+n-1;
    int* p1 = v;
    
    int* i2 = u;
    int* f2 = u+n-1;
    int* p2 = u;

//    cout << "Vetor 'v' orignial: ";
//    printar_array(v, n);
//    cout << "Vetor 'u' original: ";
//    printar_array(u, n);

    clock_t t1 = clock();
    quicksort_rec(i1, f1, p1);
    t1 = clock() - t1;
    
    clock_t t2 = clock();
    quicksort_loop(i2, f2, p2);
    t2 = clock() - t2;

//    cout << "Vetor 'v' ordenado: ";
//    printar_array(v, n);
//    cout << "Vetor 'u' ordenado: ";
//    printar_array(u, n);
//
    cout << "Tempo (em clocks) para todo recursivo: " << t1 << endl;
    cout << "Tempo (em clocks) para recursivo e loop: " << t2 << endl;
}

// 123621
