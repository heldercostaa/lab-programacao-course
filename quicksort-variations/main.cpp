//
//  main.cpp
//  quicksort-variations
//
//  Created by Helder Costa (github: heldercostaa) on 01/05/19.
//  Copyright © 2019. All rights reserved.
//

#include "array_helper.hpp"
#include "quicksort.hpp"
#include "partition.hpp"
#include "console_helper.hpp"
#include "instancias_ruins_Quicksort.hpp"

#include <iostream>
#include <chrono>
#include <map>
#include <vector>
#include <tuple>
#include <string.h>

bool debug = false;

int main() {
	while (true) {
		
		int size, min, max, instance_type = 0;
		
		begin_application();
		std::cout << "Enter the size of the vector: ";
		std::cin >> size;
		std::cout << "\nNow, the way to generate the instances\n";
		std::cout << "   (1) - Random instances (define range)\n";
		std::cout << "   (2) - Bad instances to fixed selection\n";
		while (instance_type != 1 and instance_type != 2) {
			std::cout << "\nEnter mode (1/2): ";
			std::cin >> instance_type;
		}
		
		int* array;
		if (instance_type == 1) {
			std::cout << "\nThe lower limit of the range: ";
			std::cin >> min;
			std::cout << "\nFinally, the upper limit: ";
			std::cin >> max;
			array = create_array(size, min, max);
		} else {
			min = 0;
			max = size-1;
			array = new int[size];
			if (create_instance(array, size)) {
				std::cout << "Not enough memory";
				return 0;
			}
		}
		call_beginning(instance_type, size, min, max);
		
		std::vector<std::tuple<Quicksort,long,bool>> result;
		
		int progress = 0;
		int max_progress = (last_type-1)*(last_selection-1)*(last_partition-1);
		
		progress_bar(progress++, max_progress);
		
		for (int t_type = first_type+1; t_type < last_type; t_type++) {
			for (int t_selection = first_selection+1; t_selection < last_selection; t_selection++) {
				for (int t_partition = first_partition+1; t_partition < last_partition; t_partition++) {
					
					enum_type type = (enum_type) t_type;
					enum_selection selection = (enum_selection) t_selection;
					enum_partition partition = (enum_partition) t_partition;
					
					Quicksort qs = Quicksort(type, selection, partition);
					
					int* i = new int[size];
					int* f = i+(size-1);
					memcpy(i, array, size*sizeof(int));
					
					std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
					qs.start(i, f);
					std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
					
					long time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
					bool sorted = is_sorted(i, size);
					
					std::tuple<Quicksort,long,bool> tuple = std::make_tuple(qs, time, sorted);
					result.push_back(tuple);
					
					progress_bar(progress, max_progress);
					progress++;
				}
			}
		}
		
		show_results(result);
		
		std::cout << "\nDo you want to do another sorting? (Y/N)\n>> ";
		std::string repeat;
		std::cin >> repeat;
		
		if (repeat == "N" or repeat == "n") {
			return 0;
		} else {
			clean_screen();
			continue;
		}
	}
}
