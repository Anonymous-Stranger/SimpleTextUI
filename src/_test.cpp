/*
 * _test.cpp
 *
 * Tests SimpleTextUI.
 * 
 *  Created on: Aug 17, 2015
 *      Author: Akash
 */

#include "_test.h"

namespace SimpleTextUITest {

void run() {

	Menu menu {{
		{"blah", [](IOObj& io){
			
			io << std::endl;

			io << (yesOrNo(io, "Are you sure?", false) ? "Good." : "Nevermind.");

			io << std::endl << std::endl;

			input<std::string>(io, "type 'hello': ", [](std::string s){ return s == "hello"; });

			io << std::endl;

			input<unsigned int>(io, "type a four digit positive integer: ", [](unsigned int i){ return 999 < i && i <= 9999; });

		}}
	}};

	menu.choose();

}

}


