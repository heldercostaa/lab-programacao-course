//
//  console_helper.cpp
//  pattern-search
//
//  Created by Helder Costa on 13/05/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#include "console_helper.hpp"
#include "array_helper.hpp"
#include "table_printer.h"

#include <iostream>
#include <thread>

void clean_screen() {
	std::cout << std::string( 100, '\n' );
}

void begin_application() {
	
	std::cout << "\n";
	std::cout << "          +============================================+\n";
	std::cout << "          |                                            |\n";
	std::cout << "          |          Welcome to Pattern Search         |\n";
	std::cout << "          |                 --> KMP <--                |\n";
	std::cout << "          |                                            |\n";
	std::cout << "          +============================================+\n";
	std::cout << "                                                        \n";
	std::cout << "                           Helder Costa                 \n";
	std::cout << "                    Federal University of Ceará         \n";
	std::cout << "                        Prof: Pablo Mayckon             \n\n\n";
	
	std::cout << "The instance type, the size of the text, the size of the pattern\n";
	std::cout << "and the range of the alphabet will be decided by you.\n\n";
}

void call_beginning(Instance instance) {
	
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "\nAll set!\n";

	if ((instance.n < 25 && instance.m < 25) || instance.instance_type == REAL) {
		std::cout << "Looking for the pattern: [";
		print_text(instance.pattern, instance.m);
		if (instance.instance_type == REAL) {
			std::cout << "] into a real book.\n";
		} else {
			std::cout << "] into the text: [";
			print_text(instance.text, instance.n);
			std::cout << "]\n";
		}
	}

	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "\nWait. Searching...\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));

}

void show_results(std::vector<std::tuple<Search,std::vector<int>,long,bool>> result) {
	std::cout << "Search completed.\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Generating results...\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Below, the table with the results.\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));

	bprinter::TablePrinter tp(&std::cout);
	tp.AddColumn("INSTANCE", 13);
	tp.AddColumn("SEARCH ALGORITHM", 16);
	tp.AddColumn("TOTAL PATTERNS", 15);
	tp.AddColumn("TIME", 10);
	tp.AddColumn("SAME OUTPUT?", 13);
	
	long total_patterns = 0;
	
	tp.PrintHeader();
	for (auto tuple : result) {
		Search search = std::get<0>(tuple);
		std::vector<int> indexes = std::get<1>(tuple);
		std::string time = std::to_string(std::get<2>(tuple)) + "ms";
		std::string same_output = std::get<3>(tuple) ? "Yes" : "No";

		total_patterns = indexes.size();
		
		tp << search.search_name << search << total_patterns << time << same_output;
	}
	tp.PrintFooter();
	
	if (total_patterns <= 100) {
		std::cout << "Indexes position: \n[ ";
		for (int index : std::get<1>(result[0])) {
			std::cout << index << " ";
		}
		std::cout << "]";
	} else {
		std::cout << "The first 100 indexes positions: \n[ ";
		for (int i = 0; i < 100 ; i++) {
			std::cout << std::get<1>(result[0])[i] << " ";
		}
		std::cout << ".....]";
	}

}
