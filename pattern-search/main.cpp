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

#include <thread>
#include <iostream>
#include <random>

int main() {
	
	int n = 20;
	int m = 3;
	int l = 3;
	
	std::string choice = "wc2";
	
	const char* text = "";
	const char* pattern = "";
	
	if (choice == "random") {
		
		std::cout << "Running: Random instances." << std::endl;
		
		text = random_text(n, l);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		pattern = random_text(m, l);
		
	} else if (choice == "wc1") {
		
		std::cout << "Running: Worst Case 1." << std::endl;
		
		auto wc1 = worst_case_1(n, m);
		text = std::get<0>(wc1);
		pattern = std::get<1>(wc1);
		
	} else if (choice == "wc2") {
		
		std::cout << "Running: Worst Case 2." << std::endl;

		auto wc2 = worst_case_2(n, m);
		text = std::get<0>(wc2);
		pattern = std::get<1>(wc2);
		
	} else {
		
		std::cout << "Invalid input." << std::endl;
		return 0;
	}
	
	std::cout << "Text: ";
	print_text(text, n);
	std::cout << "Pattern: ";
	print_text(pattern, m);
	
	Search intuitive_search = Search(INTUITIVE);
	Search kmp_search = Search(KMP);
	
	int* intuitive_output = new int[n+1];
	intuitive_output[0] = -1;
	
	int* kmp_output = new int[n+1];
	kmp_output[0] = -1;
	
	intuitive_search.search(text, pattern, intuitive_output);
	
	bool pattern_found = false;
	for(int i = 0; intuitive_output[i] != -1; i++) {
		std::cout << "Pattern found on index: " << intuitive_output[i] << std::endl;
		pattern_found = true;
	}

	if(!pattern_found) { std::cout << "Could not find pattern on this text." << std::endl; }
	
	
	kmp_search.search(text, pattern, kmp_output);
	
	pattern_found = false;
	for(int i = 0; intuitive_output[i] != -1; i++) {
		std::cout << "Pattern found on index: " << intuitive_output[i] << std::endl;
		pattern_found = true;
	}
	
	if(!pattern_found) { std::cout << "Could not find pattern on this text." << std::endl; }


	
}
