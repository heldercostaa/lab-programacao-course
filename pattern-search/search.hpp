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

class Search {
	enum_search search_type;

public:
	Search(enum_search t_search_type);
	
	void search(const char* text, const char* pattern, int* output);
	
	void intuitive_search(const char* text, const char* pattern, int* output);
	void kmp(const char* text, const char* pattern, int* output);
};



#endif /* search_hpp */
