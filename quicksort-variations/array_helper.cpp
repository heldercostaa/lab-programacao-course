//
//  array_helper.cpp
//  quicksort-variations
//
//  Created by Helder Costa (github: heldercostaa) on 01/05/19.
//  Copyright © 2019. All rights reserved.
//

#include "array_helper.hpp"

#include <iostream>
#include <cstring>
#include <random>

int* create_array(int size, int min, int max) {
	
	std::random_device rd;
	std::mt19937 ger(rd());
	std::uniform_int_distribution<int> generate(min, max);
	
	srand(static_cast<unsigned int>(time(NULL)));
	
	int* rand = new int[size];
	for(int* p = rand; p != rand+size; p++) {
		*p = generate(ger);
	}
	
	return rand;
}

bool is_sorted(int *i, int size) {
	
	for(int* p = i; p < i+size-1; p++) {
		if(*p > *(p+1)) { return false; }
	}
	return true;
}

void print_array(int *i, int tam) {
	
	for (int* q = i; q != i + tam; q++) {
		*q < 10 ? std::cout << " " : std::cout << "";
		std::cout << *q << " ";
	}
	std::cout << "\n";
}

void swap(int* p, int* q) {
	
	int temp = *p;
	*p = *q;
	*q = temp;
}
