#include "array_helper.hpp"
#include "quicksort.hpp"
#include "particionamento.hpp"
#include "console_helper.hpp"
#include "instancias_ruins_Quicksort.hpp"

#include <iostream>
#include <chrono>
#include <map>
#include <vector>
#include <tuple>
#include <string.h>

bool debug = false;

int main() {
	while (true) {
		
		int tam, min, max, instancia = 0;
		
		inicia_programa();
		std::cout << "Digite o tamanho do vetor: ";
		std::cin >> tam;
		std::cout << "\nAgora, o modo de geração de instâncias\n";
		std::cout << "   (1) - Instâncias aleatórias (definir intervalo)\n";
		std::cout << "   (2) - Instâncias ruins para seleção fixa\n";
		while (instancia != 1 and instancia != 2) {
			std::cout << "\nDigite o modo (1/2): ";
			std::cin >> instancia;
		}
		
		int* array;
		if (instancia == 1) {
			std::cout << "\nO limite inferior do intervalo: ";
			std::cin >> min;
			std::cout << "\nPor fim, o limite superior: ";
			std::cin >> max;
			array = criar_array(tam, min, max);
		} else {
			min = 0;
			max = tam-1;
			array = new int[tam];
			if (escrever_instancia(array, tam)) {
				std::cout << "Falta de memória";
				return 0;
			}
		}
		anuncia_comeco(instancia, tam, min, max);
		
		std::vector<std::tuple<Quicksort,long,bool>> resultado;
		
		int progresso = 0;
		int maximo_progresso = (tipo_ultimo-1)*(selecao_ultimo-1)*(particionamento_ultimo-1);
		
		barra_de_progresso(progresso++, maximo_progresso);
		
		for (int t_tipo = tipo_primeiro+1; t_tipo < tipo_ultimo; t_tipo++) {
			for (int t_selecao = selecao_primeiro+1; t_selecao < selecao_ultimo; t_selecao++) {
				for (int t_particionamento = particionamento_primeiro+1; t_particionamento < particionamento_ultimo; t_particionamento++) {
					
					enum_tipo tipo = (enum_tipo) t_tipo;
					enum_selecao selecao = (enum_selecao) t_selecao;
					enum_particionamento particionamento = (enum_particionamento) t_particionamento;
					
					Quicksort qs = Quicksort(tipo, selecao, particionamento);
					
					int* i = new int[tam];
					int* f = i+(tam-1);
					memcpy(i, array, tam*sizeof(int));
					
					std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
					qs.iniciar(i, f);
					std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
					
					long tempo = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
					bool ordenado = array_ordenado(i, tam);
					
					std::tuple<Quicksort,long,bool> tupla = std::make_tuple(qs, tempo, ordenado);
					resultado.push_back(tupla);
					
					barra_de_progresso(progresso, maximo_progresso);
					progresso++;
				}
			}
		}
		
		mostrar_resultados(resultado);
		
		std::cout << "\nDeseja realizar outra ordenação? (S/N)\n>> ";
		std::string repete;
		std::cin >> repete;
		
		if (repete == "N" or repete == "n") {
			return 0;
		} else {
			limpa_tela();
			continue;
		}
	}
}
