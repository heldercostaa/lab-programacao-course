//
//  quicksort.cpp
//  quicksort-variations
//
//  Created by Helder Costa (github: heldercostaa) on 01/05/19.
//  Copyright © 2019. All rights reserved.
//


#include "quicksort.hpp"

#include <iostream>
#include <math.h>

Quicksort::Quicksort(enum_type t_type, enum_selection t_selection, enum_partition t_partition) {
	type = t_type;
	selection = Selection(t_selection, t_partition);
	partition = Partition(t_partition);
}

void Quicksort::start(int* i, int* f) {
	switch (type) {
		case INDEX:
			if(debug) { std::cout << "Quicksort: Recursive with indexes\n"; }
			qs_index(i, f);
			break;
		case POINTER:
			if(debug) { std::cout << "Quicksort: Recursive with pointers\n"; }
			qs_pointer(i, f);
			break;
			//		case TIME:
			//			if(debug) { std::cout << "Quicksort: Optimizing time\n"; }
			//			qs_time(i, f);
			//			break;
		case MEMORY:
			if(debug) { std::cout << "Quicksort: Optimizing time and memory\n"; }
			qs_memory(i, f);
			break;
		default:
			std::cout << "Invalid Quicksort\n";
			break;
	}
}

void Quicksort::qs_index(int* i, int* f) {
	
	int a = 0;
	int b = (int) (f-i);
	
	if(a >= b) { return; }
	
	int middle = ceil((b-a)/2.0);
	int pivot = (int) (selection.select(i+a, i+b, middle)-i);
	
	auto equals = partition.partitionate(i+a, i+b, i+pivot);
	int equals_begin = (int) (std::get<0>(equals)-i);
	int equals_end = (int) (std::get<1>(equals)-i);
	
	qs_index(i+a, i+equals_begin-1);
	qs_index(i+equals_end+1, i+b);
}

void Quicksort::qs_pointer(int* i, int* f) {
	
	if(i >= f) { return; }
	
	int middle = ceil((f-i)/2.0);
	int* pivot = selection.select(i, f, middle);
	
	auto equals = partition.partitionate(i, f, pivot);
	int* equals_begin = std::get<0>(equals);
	int* equals_end = std::get<1>(equals);
	
	qs_pointer(i, equals_begin-1);
	qs_pointer(equals_end+1, f);
}

//void Quicksort::qs_time(int* i, int* f) {
//
//    while(i < f) {
//		int middle = ceil((f-i)/2.0);
//		int* pivot = select(i, f, middle);
//
//		auto equals = partition.particionar(i, f, pivot);
//		int* equals_begin = std::get<0>(equals);
//		int* equals_end = std::get<1>(equals);
//
//		qs_time(i, equals_begin-1);
//		i = equals_end+1;
//    }
//}

void Quicksort::qs_memory(int* i, int* f) {
	
	while(i < f) {
		int middle = ceil((f-i)/2.0);
		int* pivot = selection.select(i, f, middle);
		
		auto equals = partition.partitionate(i, f, pivot);
		int* equals_begin = std::get<0>(equals);
		int* equals_end = std::get<1>(equals);
		
		long left = equals_begin-i;
		long right = f-equals_end;
		
		if(left < right) {
			qs_memory(i, equals_begin-1);
			i = equals_end+1;
		} else {
			qs_memory(equals_end+1, f);
			f = equals_begin-1;
		}
	}
}

std::ostream& operator<<(std::ostream &os, const Quicksort& quicksort) {
	switch (quicksort.type) {
		case INDEX:
			std::cout << "Indexes";
			break;
		case POINTER:
			std::cout << "Pointers";
			break;
			//		case TIME:
			//			std::cout << "Time";
			//			break;
		case MEMORY:
			std::cout << "Memory";
			break;
		default:
			std::cout << "Invalid Quicksort";
			break;
	}
	
	return os;
}
