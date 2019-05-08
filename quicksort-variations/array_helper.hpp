//
//  array_helper.hpp
//  quicksort-variations
//
//  Created by Helder Costa (github: heldercostaa) on 01/05/19.
//  Copyright © 2019. All rights reserved.
//

#ifndef ARRAY_HELPER_HPP
#define ARRAY_HELPER_HPP

extern bool debug;

int* create_array(int tam, int min, int max);
bool is_sorted(int *i, int tam);
void print_array(int *i, int tam);
void swap(int* p, int* q);

#endif /* ARRAY_HELPER_HPP */
