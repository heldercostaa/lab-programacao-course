//
//  selection.hpp
//  quicksort-variations
//
//  Created by Helder Costa (github: heldercostaa) on 01/05/19.
//  Copyright © 2019. All rights reserved.
//

#ifndef SELECTION_HPP
#define SELECTION_HPP

#include "enum.hpp"
#include "partition.hpp"

#include <iostream>

extern bool debug;

class Selection {
	
	Partition partition = Partition(TRIPLE);
	
public:
	enum_selection selection;
	
	Selection(enum_selection t_selection, enum_partition t_partition);
	int* select(int* i, int* f, int k);
	
	static int* fixed_selection(int* i, int* f);
	int* random_selection(int* i, int* f);
	int* hoare_selection(int* i, int* f, int k);
	int* bfprt_selection(int* i, int* f, int k);
	
	friend std::ostream& operator<<(std::ostream &os, const Selection& n);
};

#endif /* SELECTION_HPP */
