//
//  selecao.cpp
//  quicksort-variations
//
//  Created by Helder Costa (github: heldercostaa) on 01/05/19.
//  Copyright © 2019. All rights reserved.
//

#include "selection.hpp"
#include "array_helper.hpp"

#include <math.h>
#include <iostream>
#include <random>

Selection::Selection(enum_selection t_selection, enum_partition t_partition) {
	selection = t_selection;
	partition = Partition(t_partition);
}

int* Selection::select(int *i, int *f, int k) {
	switch (selection) {
		case FIXED:
			if(debug) { std::cout << "Selection: Fixed\n"; }
			return fixed_selection(i, f);
			break;
		case RANDOM:
			if(debug) { std::cout << "Selection: Random\n"; }
			return random_selection(i, f);
			break;
		case HOARE:
			if(debug) { std::cout << "Selection: Hoare\n"; }
			return hoare_selection(i, f, k);
			break;
		case BFPRT:
			if(debug) { std::cout << "Selection: BFPRT\n"; }
			return bfprt_selection(i, f, k);
			break;
		default:
			std::cout << "Invalid Selection\n";
			return nullptr;
			break;
	}
}

int* Selection::fixed_selection(int* i, int* f) {
	
	return i;
}

int* Selection::random_selection(int* i, int* f) {
	
	int last = (int) (f-i);
	int random_index = rand()%(last+1);
	
	return i+random_index;
}

int* Selection::hoare_selection(int* i, int* f, int k) {
	
	int* pivot = random_selection(i, f);
	
	auto p = partition.partitionate(i, f, pivot);
	int* pos1 = std::get<0>(p);
	int* pos2 = std::get<1>(p);
	
	if(k < (pos1-i)+1) {
		pos1--;
		return hoare_selection(i, pos1, k);
	}
	if(k > (pos2-i)+1) {
		pos2++;
		return hoare_selection(pos2, f, (int) (k-(pos2-i)));
	}
	
	return (k+i)-1;
}

int* Selection::bfprt_selection(int* i, int* f, int k) {
	
	int size = (int)(f-i)+1;
	int* last_median = i;
	
	// Step a
	if(size <= 5) {
		hoare_selection(i, f, k);
		return i+(k-1);
	}
	// Step b e c
	else {
		int* begin_interval = i;
		int* end_interval = i+4;
		while(begin_interval <= f) {
			int size_interval = (int)(end_interval-begin_interval)+1;
			int middle_interval = ceil(size_interval/2.0);
			hoare_selection(begin_interval, end_interval, middle_interval);
			
			int* median_position = begin_interval+(middle_interval-1);
			swap(last_median, median_position);
			
			++last_median;
			begin_interval += 5;
			end_interval += 5;
			if(end_interval > f) { end_interval = f; }
		}
	}
	--last_median;
	
	// Step d
	int medians_size = (int)(last_median-i)+1;
	int medians_middle = ceil(medians_size/2.0);
	int* pivot = bfprt_selection(i, last_median, medians_middle);
	
	// Step e
	auto p = partition.partitionate(i, f, pivot);
	int* pos1 = std::get<0>(p);
	int* pos2 = std::get<1>(p);
	
	// Step f
	if(k < (pos1-i)+1) {
		return bfprt_selection(i, pos1-1, k);
	}
	if(k > (pos2-i)+1) {
		return bfprt_selection(pos2+1, f, (int) (k-(pos2+1-i)));
	}
	
	return i+(k-1);
}

std::ostream& operator<<(std::ostream &os, const Selection& selection) {
	switch (selection.selection) {
		case FIXED:
			std::cout << "Fixed";
			break;
		case RANDOM:
			std::cout << "Random";
			break;
		case HOARE:
			std::cout << "Hoare";
			break;
		case BFPRT:
			std::cout << "BFPRT";
			break;
		default:
			std::cout << "Invalid Selectin";
			break;
	}
	
	return os;
}
