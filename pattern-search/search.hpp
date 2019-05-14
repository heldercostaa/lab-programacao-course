//
//  search.hpp
//  pattern-search
//
//  Created by Helder Costa on 12/05/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#ifndef search_hpp
#define search_hpp

#include "enum.hpp"
#include "instance.hpp"

#include <string.h>
#include <vector>

class Search {
	enum_search search_type;

public:
	std::string search_name;
	Instance instance;

	Search(enum_search t_search_type, Instance t_instance);
	
	std::vector<int> search();
	
	std::vector<int> intuitive_search(const char* text, const char* pattern, std::vector<int> output);
	std::vector<int> kmp(const char* text, const char* pattern, std::vector<int> output);

	friend std::ostream& operator<<(std::ostream &os, const Search& n);
};



#endif /* search_hpp */
