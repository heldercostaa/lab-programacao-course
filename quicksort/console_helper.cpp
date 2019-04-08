#include "console_helper.hpp"
#include "table_printer.h"

#include <iostream>
#include <algorithm> 
#include <thread>

void limpa_tela() {
	std::cout << std::string( 100, '\n' );
}

void inicia_programa() {
	
	std::cout << "\n";
	std::cout << "          +============================================+\n";
	std::cout << "          |                                            |\n";
	std::cout << "          |     Bem-vindo ao programa de ordenação     |\n";
	std::cout << "          |             --> Quicksort <--              |\n";
	std::cout << "          |                                            |\n";
	std::cout << "          +============================================+\n";
	std::cout << "                                                        \n";
	std::cout << "                           Helder Costa                 \n";
	std::cout << "                   Universidade Federal do Ceará        \n";
	std::cout << "                        Prof: Pablo Mayckon             \n\n\n";
	
	std::cout << "O modo de construir o vetor, o tamanho do vetor e o intervalo\n";
	std::cout << "dos números aleatórios (caso necessário), serão determinados por você.\n\n";
}

void anuncia_comeco(int instancia, int tam, int min, int max) {
	
	std::string nome_instancia;
	
	if (instancia == 1) {
		nome_instancia = "instâncias aleatórias";
	} else {
		nome_instancia = "instâncias ruins para seleção fixa";
	}
	std::cout << "\nOrdenando um vetor de tamanho " << tam << " com números gerados por\n";
	std::cout << nome_instancia << " no intervalo de [" << min << "," << max << "]\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "Iniciando ordenação...\n";
}

void barra_de_progresso(int progresso, int progresso_maximo) {
	double porcentagem = round(((double) progresso / (double) progresso_maximo)*100)/100;
	std::cout << porcentagem*100 << "% - ";
	std::cout << "[";
	for(int i = 0; i < progresso; i++) {
		std::cout << "#";std::cout << "#";
	}
	for(int i = progresso; i < progresso_maximo; i++) {
		std::cout << ".";std::cout << ".";
	}
	std::cout << "]\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
}

bool ordenar_por_tempo(const std::tuple<Quicksort, long, bool>& qs1, const std::tuple<Quicksort, long, bool>& qs2) {
	return (std::get<1>(qs1) < std::get<1>(qs2));
}

void mostrar_resultados(std::vector<std::tuple<Quicksort,long,bool>> resultado) {
	
	std::cout << "\nOrdenação finalizada.\n\n";
	std::cout << "Gerando tabela...\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Abaixo, a tabela de comparação dos tempos dos algoritmos.\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	
	sort(resultado.begin(), resultado.end(), ordenar_por_tempo);
	bprinter::TablePrinter tp(&std::cout);
//	tp.AddColumn("QUICKSORT", 16);
	tp.AddColumn("QUICKSORT", 10);
	tp.AddColumn("SELECAO", 10);
	tp.AddColumn("PARTICIONAMENTO", 16);
	tp.AddColumn("TEMPO", 15);
	tp.AddColumn("ORDENOU?", 9);
	
	tp.PrintHeader();
	for (auto tupla : resultado) {
		Quicksort qs = std::get<0>(tupla);
		Selecao selecao = qs.selecao;
		Particionamento particionamento = qs.particionamento;
		std::string tempo = std::to_string(std::get<1>(tupla)) + "ms";
		std::string ordenado = std::get<2>(tupla) ? "Sim" : "Não";

		tp << qs << selecao << particionamento << tempo << ordenado;
	}
	tp.PrintFooter();
}
