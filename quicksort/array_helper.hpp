#ifndef ARRAY_HELPER_HPP
#define ARRAY_HELPER_HPP

extern bool debug;

int* criar_array(int tam, int min, int max);
bool array_ordenado(int *i, int tam);
void printar_array(int *i, int tam);
void trocar_elementos(int* p, int* q);

#endif /* ARRAY_HELPER_HPP */
