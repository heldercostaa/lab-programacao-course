//
//  main.cpp
//  huffman-coding
//
//  Created by Helder Costa on 03/06/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#include <iostream>

#include "min_heap.hpp"

int main(int argc, const char * argv[]) {
	
	// Sample
	// https://www.tutorialspoint.com/data_structures_algorithms/images/min_heap_example.jpg
	
	MinHeap heap = MinHeap(10);
	heap.insertValue(42);
	heap.insertValue(27);
	heap.insertValue(14);
	heap.insertValue(26);
	heap.insertValue(10);
	heap.insertValue(44);
	heap.insertValue(35);
	heap.insertValue(19);
	heap.insertValue(33);
	heap.insertValue(31);
	
	// Must print 10
	std::cout << heap.getMin() << std::endl;
	
	// Must print 1
	std::cout << heap.left(0) << std::endl;
	
	// Must print 2
	std::cout << heap.right(0) << std::endl;
	
	// Must print 3
	std::cout << heap.parent(8) << std::endl;
	
	// Must print 10
	std::cout << heap.extractMin() << std::endl;
	
	// Must print 14
	std::cout << heap.getMin() << std::endl;
	
	// Must print 3
	heap.insertValue(3);
	std::cout << heap.getMin() << std::endl;
	
	
}
