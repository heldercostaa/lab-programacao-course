//
//  quicksort.hpp
//  quicksort-variations
//
//  Created by Helder Costa (github: heldercostaa) on 01/05/19.
//  Copyright © 2019. All rights reserved.
//

#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "enum.hpp"
#include "selection.hpp"
#include "partition.hpp"

#include <iostream>

extern bool debug;

class Quicksort {
	enum_type type;
public:
	Selection selection = Selection(BFPRT, TRIPLE);
	Partition partition = Partition(TRIPLE);
	Quicksort(enum_type t_type, enum_selection t_selection, enum_partition t_partition);
	void start(int* i, int* f);
	
	void qs_index(int* i, int* f);
	void qs_pointer(int* i, int* f);
	void qs_tempo(int* i, int* f);
	void qs_memory(int* i, int* f);
	
	friend std::ostream& operator<<(std::ostream &os, const Quicksort& n);
};

#endif /* QUICKSORT_HPP */
