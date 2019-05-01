//
//  selecoes.cpp
//  class-07
//
//  Created by Helder Costa (github: heldercostaa) on 30/04/19.
//  Copyright © 2019. All rights reserved.
//

#include "selecoes.hpp"
#include "particoes.hpp"

#import <iostream>

int* selecao_hoare(int* i, int* f, int k) {

	auto p = particao_tripla(i, f, i);
	int* pos1 = std::get<0>(p);
	int* pos2 = std::get<1>(p);

	if(k < (pos1-i)+1) {
		pos1--;
		return selecao_hoare(i, pos1, k);
	}
	if(k > (pos2-i)+1) {
		pos2++;
		return selecao_hoare(pos2, f, (int) (k-(pos2-i)));
	}
	return (k+i)-1;
}
