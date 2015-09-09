/*
 * _test.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: Akash
 */

#include "_test.h"

namespace SimpleTextUITest {

void run() {

	SimpleTextUI::Menu menu {{
		{"blah", [](SimpleTextUI::IOObj& io){
			io << (yesOrNo(io, "Are you sure?", false) ? "Good." : "Nevermind.") << std::endl;
		}}
	}};

	menu.choose();

}

}


