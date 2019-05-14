//
//  main.cpp
//  pattern-search
//
//  Created by Helder Costa on 12/05/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#include "array_helper.hpp"
#include "search.hpp"
#include "enum.hpp"
#include "instancias_Reais_Trabalho_2.hpp"
#include "console_helper.hpp"

#include <thread>
#include <iostream>
#include <random>

int main() {
	
	bool print_input = false;
	int instance_type = 0;
	
	begin_application();
	std::cout << "\nEnter the way to generate the instances\n";
	std::cout << "   (1) - Random instances\n";
	std::cout << "   (2) - Worst Case 1 / ex: Text='aaaa..aa' and pattern='aa..ab'\n";
	std::cout << "   (3) - Worst Case 2 / ex: Text='aaaa..aa' and pattern='aa..aa'\n";
	std::cout << "   (4) - Real instance\n";
	while (instance_type < 1 or instance_type > 4) {
		std::cout << "\nEnter mode (1-4): ";
		std::cin >> instance_type;
	}
	
	
	int n = 20;
	int m = 3;
	int l = 3;
	// number between [0..35129]
	int word = 24234;
	std::string instance_name = "";
	
	std::tuple<char*, char*> wc1, wc2;
	
	const char* text = "";
	const char* pattern = "";
	
	
	switch (instance_type) {
		case 1: // Random instance
			text = random_text(n, l);
			std::this_thread::sleep_for(std::chrono::seconds(1));
			pattern = random_text(m, l);
			
			instance_name = "Random";
			break;
			
		case 2: // Worst case 1
			wc1 = worst_case_1(n, m);
			text = std::get<0>(wc1);
			pattern = std::get<1>(wc1);
			
			instance_name = "Worst case 1";
			break;
			
		case 3: // Worst case 2
			wc2 = worst_case_2(n, m);
			text = std::get<0>(wc2);
			pattern = std::get<1>(wc2);
			
			instance_name = "Worst case 2";
			break;
			
		case 4: // Real instance
			text = Texto_Livros;
			pattern = Padroes_Palavras[word];
			n = 66;
			m = (int) strlen(pattern);
			
			instance_name = "Real";
			break;
			
		default:
			std::cout << "Invalid input" << std::endl;
			return 0;
	}
	
	if (print_input) {
		std::cout << "Text: ";
		print_text(text, n);
		std::cout << "Pattern: ";
		print_text(pattern, m);
	}
	
	Search intuitive_search = Search(INTUITIVE);
	Search kmp_search = Search(KMP);
	
	int* intuitive_output = new int[n+1];
	intuitive_output[0] = -1;
	
	int* kmp_output = new int[n+1];
	kmp_output[0] = -1;
	
	std::chrono::steady_clock::time_point intuitive_begin = std::chrono::steady_clock::now();
	intuitive_search.search(text, pattern, intuitive_output);
	std::chrono::steady_clock::time_point intuitive_end = std::chrono::steady_clock::now();
	
	std::chrono::steady_clock::time_point kmp_begin = std::chrono::steady_clock::now();
	kmp_search.search(text, pattern, kmp_output);
	std::chrono::steady_clock::time_point kmp_end = std::chrono::steady_clock::now();
	
	bool equal_output = equal(intuitive_output, kmp_output);
	
	long intuitive_time = std::chrono::duration_cast<std::chrono::milliseconds>(intuitive_end - intuitive_begin).count();
	long kmp_time = std::chrono::duration_cast<std::chrono::milliseconds>(kmp_end - kmp_begin).count();

	std::cout << "Instance type: " << instance_name << std::endl;
	std::cout << "Intuitive time: " << intuitive_time << std::endl;
	std::cout << "KMP time: " << kmp_time << std::endl;
	std::cout << "Equal: " << (equal_output ? "Yes" : "No") << std::endl;
	
}
