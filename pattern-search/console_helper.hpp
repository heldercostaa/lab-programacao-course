//
//  console_helper.hpp
//  pattern-search
//
//  Created by Helder Costa on 13/05/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#ifndef console_helper_hpp
#define console_helper_hpp

#include "instance.hpp"
#include "search.hpp"

#include <tuple>
#include <iostream>
#include <vector>

void clean_screen();
void begin_application();
void call_beginning(Instance instance);
void show_results(std::vector<std::tuple<Search,std::vector<int>,long,bool>> result);

#endif /* console_helper_hpp */
