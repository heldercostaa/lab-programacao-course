//
//  console_helper.hpp
//  quicksort-variations
//
//  Created by Helder Costa (github: heldercostaa) on 01/05/19.
//  Copyright © 2019. All rights reserved.
//

#ifndef CONSOLE_HELPER_HPP
#define CONSOLE_HELPER_HPP

#include "quicksort.hpp"

#include <tuple>
#include <iostream>
#include <vector>

void clean_screen();
void begin_application();
void call_beginning(int instancia, int tam, int min, int max);

void progress_bar(int progresso, int progresso_maximo);
bool sort_by_time(const std::tuple<Quicksort, long, bool>& a, const std::tuple<Quicksort, long, bool>& b);
void show_results(std::vector<std::tuple<Quicksort,long,bool>> resultado);

#endif /* CONSOLE_HELPER_HPP */
