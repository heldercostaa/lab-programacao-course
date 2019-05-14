//
//  instance.cpp
//  pattern-search
//
//  Created by Helder Costa on 14/05/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#include "instance.hpp"
#include "array_helper.hpp"
#include "array_helper.hpp"
#include "instancias_Reais_Trabalho_2.hpp"

#include <thread>
#include <tuple> 

Instance::Instance() {

}

Instance::Instance(enum_instance t_instance_type, int t_n, int t_m){
	instance_type = t_instance_type;
	n = t_n;
	m = t_m;
	get_text_and_pattern();
};

Instance::Instance(enum_instance t_instance_type, int t_n, int t_m, int t_l_or_word){
	instance_type = t_instance_type;
	n = t_n;
	m = t_m;
	l_or_word = t_l_or_word;
	get_text_and_pattern();
};

void Instance::get_text_and_pattern() {
	switch (instance_type) {
		case RANDOM: {
			text = random_text(n, l_or_word);
			std::this_thread::sleep_for(std::chrono::seconds(1));
			pattern = random_text(m, l_or_word);
			
			instance_name = "Random";
		break;				
		} case WC1: {
			std::tuple<char*, char*> wc1 = worst_case_1(n, m);
			text = std::get<0>(wc1);
			pattern = std::get<1>(wc1);
			
			instance_name = "Worst case 1";
		break;
		} case WC2: {
			std::tuple<char*, char*> wc2 = worst_case_2(n, m);
			text = std::get<0>(wc2);
			pattern = std::get<1>(wc2);
			
			instance_name = "Worst case 2";
		break;
		} case REAL: {
			text = Texto_Livros;
			pattern = Padroes_Palavras[l_or_word];
			n = 64;
			m = (int) strlen(pattern);
			
			instance_name = "Real";
		break;
		}
	}
}