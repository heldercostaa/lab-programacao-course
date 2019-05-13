//
//  search.cpp
//  pattern-search
//
//  Created by Helder Costa on 12/05/19.
//  Copyright © 2019 UFC. All rights reserved.
//

#include "search.hpp"

#include <cstring>

Search::Search(enum_search t_search_type) {
	search_type = t_search_type;
};

void Search::search(const char* text, const char* pattern, int* output) {
	
	switch (search_type) {
		case INTUITIVE:
			intuitive_search(text, pattern, output);
			break;
		case KMP:
			kmp(text, pattern, output);
			break;
	}
	
}

void Search::intuitive_search(const char* text, const char* pattern, int* output) {
	
	int s = 0;
	
	for (int i = 0; text[i] != '\0'; i++) {
		bool found = true;
		for (int j = 0; pattern[j] != '\0'; j++) {
			if (text[i+j] != pattern[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			output[s] = i;
			s++;
		}
	}
	
	output[s] = -1;
}

/*
 Examples of pi[] construction:
 For the pattern "AAAA",
 pi[] is [0, 1, 2, 3]
 
 For the pattern "ABCDE",
 pi[] is [0, 0, 0, 0, 0]
 
 For the pattern "AABAACAABAA",
 pi[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
 
 For the pattern "AAACAAAAAC",
 pi[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4]
 
 For the pattern "AAABAAA",
 pi[] is [0, 1, 2, 0, 1, 2, 3]
 */
int* calculate_pi(const char* pattern) {
	
	long m = strlen(pattern);
	int* pi = new int[m];
	
	pi[0] = 0;
	for (int i = 1; i <= m-1; i++) {
		int k = i-1;
		while (true) {
			int l = pi[k];
			if (l == 0) {
				if (pattern[0] == pattern[i]) {
					pi[i] = 1; break;
				} else {
					pi[i] = 0; break;
				}
			} else {
				if (pattern[i] == pattern[l]) {
					pi[i] = l+1; break;
				} else {
					k = l - 1;
				}
			}
		}
	}
	
	return pi;
}

void Search::kmp(const char* text, const char* pattern, int* output) {
	
	int* pi = calculate_pi(pattern);
	//print_array(pi, strlen(padrao));
	
	long n = strlen(text);
	long m = strlen(pattern);
	
	int i = 0, j = 0, s = 0;
	
	while (i < n) {
		if (text[i] != pattern[j]) {
			if (j == 0) {
				i++;
			} else {
				j = pi[j-1];
			}
		} else {
			if (j == m-1) {
				output[s] = i;
				s++;
				j = pi[j];
				i++;
			} else {
				i++;
				j++;
			}
		}
	}
	
	output[s] = -1;
	
}
