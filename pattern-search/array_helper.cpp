//
//  array_helper.cpp
//  pattern-search
//
//  Created by Helder Costa on 12/05/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#include "array_helper.hpp"

#include <iostream>

void print_text(const char* text, int size) {

	for (const char* q = text; q != text+size; q++) {
		std::cout << *q;
	}
	
	std::cout << "\n";
}

void print_array(int *arr, int size) {
	
	for (int* q = arr; q != arr+size; q++) {
		std::cout << *q << " ";
	}
	
	std::cout << "\n";
}

char* random_text(int size, int l) {
	
	srand(static_cast<unsigned int>(time(NULL)));
	
	char* text = new char[size];
	
	const char alphabet[] =	"abcdefghijklmnopqrstuvwxyz";
	
	for(int i = 0; i < size; i++) {
		int random_index = rand() % l;
		text[i] = alphabet[random_index];
	}
	
	return text;
}

std::tuple<char*, char*> worst_case_1(int n, int m) {
	
	char* text = new char[n];
	char* pattern = new char[m];
	
	for (int i = 0; i < n; i++) {
		text[i] = 'a';
	}
	
	for (int i = 0; i < m-1; i++) {
		pattern[i] = 'a';
	}
	pattern[m-1] = 'b';
	
	return std::make_tuple(text, pattern);
}

std::tuple<char*, char*> worst_case_2(int n, int m) {
	
	char* text = new char[n];
	char* pattern = new char[m];
	
	for (int i = 0; i < n; i++) {
		text[i] = 'a';
	}
	
	for (int i = 0; i < m; i++) {
		pattern[i] = 'a';
	}
	
	return std::make_tuple(text, pattern);
}

