//
//  partition.hpp
//  quicksort-variations
//
//  Created by Helder Costa (github: heldercostaa) on 01/05/19.
//  Copyright © 2019. All rights reserved.
//

#ifndef PARTITION_HPP
#define PARTITION_HPP

#include "enum.hpp"

#include <tuple>
#include <iostream>

extern bool debug;

class Partition {
	enum_partition partition;
	
public:
	Partition(enum_partition t_partition);
	std::tuple<int*, int*> partitionate(int* i, int* f, int* p);
	
	std::tuple<int*, int*> double_partition(int* i, int* f, int* p);
	std::tuple<int*, int*> triple_partition(int* i, int* f, int* p);
	
	friend std::ostream& operator<<(std::ostream &os, const Partition& n);
};

#endif /* PARTITION_HPP */
