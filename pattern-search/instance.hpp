//
//  instance.hpp
//  pattern-search
//
//  Created by Helder Costa on 14/05/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#ifndef instance_hpp
#define instance_hpp

#include "enum.hpp"

#include <iostream>
#include <string.h>

class Instance {
	int l_or_word;

	void get_text_and_pattern();
	
public:
	enum_instance instance_type;
	int n;
	int m;
	const char* text;
	const char* pattern;
	std::string instance_name;

	Instance();
	Instance(enum_instance t_instance_type, int t_n, int t_m);
	Instance(enum_instance t_instance_type, int t_n, int t_m, int t_l_or_word);
};



#endif /* instance_hpp */