//
//  main.cpp
//  pattern-search
//
//  Created by Helder Costa on 12/05/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#include "array_helper.hpp"
#include "search.hpp"
#include "enum.hpp"
#include "console_helper.hpp"
#include "instance.hpp"

#include <thread>
#include <iostream>
#include <random>
#include <string.h>
#include <vector>

int main() {
	
	while(true) {

		int instance_number = 0;
		enum_instance instance_type = RANDOM;
		int n = -1, m = -1;
		int l_or_word = -1;
		
		begin_application();
		std::cout << "\nEnter the way to generate the instances\n";
		std::cout << "   (1) - Random instances\n";
		std::cout << "   (2) - Worst Case 1 / eg: Text='aaaa..aa' and pattern='aa..ab'\n";
		std::cout << "   (3) - Worst Case 2 / eg: Text='aaaa..aa' and pattern='aa..aa'\n";
		std::cout << "   (4) - Real instance\n";
		while (instance_number < 1 or instance_number > 4) {
			std::cout << "\nEnter mode (1-4): ";
			std::cin >> instance_number;

			if (instance_number == 1) {
				instance_type = RANDOM;
			} else if (instance_number == 2) {
				instance_type = WC1;
			} else if (instance_number == 3) {
				instance_type = WC2;
			} else if (instance_number == 4) {
				instance_type = REAL;
			}
		}

		if (instance_type != REAL) {
			std::cout << "\nEnter the size of the Text: ";
			std::cin >> n;
			std::cout << "Great, now the size of the Pattern: ";
			std::cin >> m;
		}

		Instance instance;
		if (instance_type == RANDOM || instance_type == REAL) {
			if (instance_type == RANDOM) {
				std::cout << "\nAs you chose Random Instances, is necessary to limit the alphabet\n";
				std::cout << "to the first l elements. The alphabet have a-z letters (26 letters).\n";
				while (l_or_word < 1 || l_or_word > 26) {
					std::cout << "\nChoose l between 1 and 26: ";
					std::cin >> l_or_word;
				}
			} else {
				std::cout << "\nThe Real Instance is a book, so you have to choose one word of the book.\n";
				std::cout << "There are 35130 different words in this book.\n";

				while (l_or_word < 1 || l_or_word > 35130) {
					std::cout << "\nChoose one number between 1 and 35130: ";
					std::cin >> l_or_word;
				}
				l_or_word--;
			}
			instance = Instance(instance_type, n, m, l_or_word);
		} else {
			instance = Instance(instance_type, n, m);
		}

		call_beginning(instance);

		std::vector<std::tuple<Search,std::vector<int>,long,bool>> result;
		int* arr1 = NULL;
		int* arr2 = NULL;

		for (int t_search_type = first_search+1; t_search_type < last_search; t_search_type++) {
			
			enum_search search_type = (enum_search) t_search_type;

			Search search = Search(search_type, instance);
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
			std::vector<int> indexes = search.search();
			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
			long time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
			
			/*std::vector<int> indexes;
			for(int i = 0; output[i] != -1; i++) {
				indexes.push_back(output[i]);
			}

			if(arr1 == NULL) {
				arr1 = output;
			} else {
				arr2 = arr1;
				arr1 = output;	
			}*/

			bool same_output = true;
			if (arr1 != NULL && arr2 != NULL) {
				same_output = equal(arr1, arr2);
			}

			std::tuple<Search,std::vector<int>,long,bool> tuple = std::make_tuple(search, indexes, time, same_output);
			result.push_back(tuple);
		}

		show_results(result);

		std::cout << "\n\nDo you want to try another Text and Pattern? (Y/N)\n>> ";
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
