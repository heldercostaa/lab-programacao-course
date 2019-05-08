//
//  partition.cpp
//  quicksort-variations
//
//  Created by Helder Costa (github: heldercostaa) on 01/05/19.
//  Copyright © 2019. All rights reserved.
//

#include "partition.hpp"
#include "array_helper.hpp"

#include <iostream>

Partition::Partition(enum_partition t_partition) {
	partition = t_partition;
}

std::tuple<int*, int*> Partition::partitionate(int *i, int *f, int *p) {
	switch (partition){
		case DOUBLE:
			if(debug) { std::cout << "Partition: Double\n"; }
			return double_partition(i, f, p);
			break;
		case TRIPLE:
			if(debug) { std::cout << "Partition: Triple\n"; }
			return triple_partition(i, f, p);
			break;
		default:
			if(debug) { std::cout << "Invalid Partition\n"; }
			return std::make_tuple(i, f);
			break;
	}
}

std::tuple<int*, int*> Partition::double_partition(int* i, int* f, int* p) {
	
	int* m = i;
	
	swap(i, p);
	for (int* j = i; j != f+1; j++) {
		if(*j < *i) {
			swap(j, m+1);
			m++;
		}
	}
	swap(i, m);
	
	return std::make_tuple(m, m);
}

std::tuple<int*, int*> Partition::triple_partition(int* i, int* f, int* p) {
	
	int* m = i;
	int* ig = i;
	
	swap(i, p);
	for (int* j = i+1; j != f+1; j++) {
		
		int pivot = *i;
		
		if(*j == pivot) {
			ig++;
			swap(j, ig);
		} else if(*j < pivot) {
			m++;
			ig++;
			swap(ig, j);
			swap(m, ig);
		}
	}
	swap(i, m);
	
	return std::make_tuple(m, ig);
}

std::ostream& operator<<(std::ostream &os, const Partition& particionamento) {
	switch (particionamento.partition){
		case DOUBLE:
			std::cout << "Double";
			break;
		case TRIPLE:
			std::cout << "Triple";
			break;
		default:
			std::cout << "Invalid Partition";
			break;
	}
	return os;
}
