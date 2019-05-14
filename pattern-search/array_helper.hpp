//
//  array_helper.hpp
//  pattern-search
//
//  Created by Helder Costa on 12/05/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#ifndef array_helper_hpp
#define array_helper_hpp

#include <stdio.h>
#include <tuple>

void print_text(const char* text, int size);
void print_array(int *arr, int size);
bool equal(int* arr1, int* arr2);

char* random_text(int size, int l);
std::tuple<char*, char*> worst_case_1(int n, int m);
std::tuple<char*, char*> worst_case_2(int n, int m);

#endif /* array_helper_hpp */
