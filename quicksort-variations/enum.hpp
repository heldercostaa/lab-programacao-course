//
//  enum.hpp
//  quicksort-variations
//
//  Created by Helder Costa (github: heldercostaa) on 01/05/19.
//  Copyright © 2019. All rights reserved.
//

#ifndef ENUM_HPP
#define ENUM_HPP

enum enum_type { first_type,
	
	INDEX,
	POINTER,
	//	TIME,
	MEMORY,
	
	last_type };

enum enum_selection { first_selection,
	
	FIXED,
	RANDOM,
	HOARE,
	BFPRT,
	
	last_selection};

enum enum_partition { first_partition,
	
	DOUBLE,
	TRIPLE,
	
	last_partition };

#endif /* ENUM_HPP */
