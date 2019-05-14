//
//  console_helper.cpp
//  pattern-search
//
//  Created by Helder Costa on 13/05/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#include "console_helper.hpp"

#include <iostream>

void clean_screen() {
	std::cout << std::string( 100, '\n' );
}

void begin_application() {
	
	std::cout << "\n";
	std::cout << "          +============================================+\n";
	std::cout << "          |                                            |\n";
	std::cout << "          |          Welcome to Pattern Search         |\n";
	std::cout << "          |             --> Quicksort <--              |\n";
	std::cout << "          |                                            |\n";
	std::cout << "          +============================================+\n";
	std::cout << "                                                        \n";
	std::cout << "                           Helder Costa                 \n";
	std::cout << "                    Federal University of Ceará         \n";
	std::cout << "                        Prof: Pablo Mayckon             \n\n\n";
	
	std::cout << "The instance type, the size of the text, the size of the pattern\n";
	std::cout << "and the range of the alphabet will be decided by you.\n\n";
}
