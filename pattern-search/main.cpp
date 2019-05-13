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

#include <iostream>
#include <random>

int main() {
	
//	int size = 10;
//	const char* text = "abaa";//random_text(tam);
//	const char* pattern = "a";
//
//	std::cout << "Random text: : ";
//	print_text(text);
//	std::cout << "Pattern: " << pattern << std::endl;
//
//	int* output = new int[size+1];
//	output[0] = -1;
//
//	intuitive_search(text, pattern, output);
////	kmp(text, pattern, output);
//
//	bool pattern_found = false;
//	for(int i = 0; output[i] != -1; i++) {
//		std::cout << "Pattern found on index: " << output[i] << std::endl;
//		pattern_found = true;
//	}
//
//	if(!pattern_found) { std::cout << "Could not find pattern on this text."; }
//
	
	
	int size = 11;
	int l = 2;
	
	const char* text = random_text(size, l);
	const char* pattern = random_text(size/2, l);
	
	auto wc1 = worst_case_1(size, size/2);
	const char* wc1_text = std::get<0>(wc1);
	const char* wc1_pattern = std::get<1>(wc1);
	
	auto wc2 = worst_case_2(size, size/2);
	const char* wc2_text = std::get<0>(wc2);
	const char* wc2_pattern = std::get<1>(wc2);
	
	
	std::cout << "Random text: " << std::endl;
	print_text(text, size);
	std::cout << "Random pattern: " << std::endl;
	print_text(pattern, size/2);
	
	std::cout << "\n";
	
	std::cout << "WC1 Text: " << std::endl;
	print_text(wc1_text, size);
	std::cout << "WC1 Pattern: " << std::endl;
	print_text(wc1_pattern, size/2);
	
	std::cout << "\n";
	
	std::cout << "WC2 Text: " << std::endl;
	print_text(wc2_text, size);
	std::cout << "WC2 Text: " << std::endl;
	print_text(wc2_pattern, size/2);
	
	
}
