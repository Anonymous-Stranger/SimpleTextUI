/*
 * _test.cpp
 *
 * Tests SimpleTextUI.
 * 
 *  Created on: Aug 17, 2015
 *      Author: Akash
 */

#include "_test.h"
#include "Menu.h"
#include "input.h"

namespace SimpleTextUITest {

// helper functions
void blah(IOObj& io);
void sayNumber(IOObj& io);


// This gets called by _runtest.cpp
void run() { runCompressed(); }



void runSimple() {

	bool shouldContinue {true};

	Menu main {"Main Menu"};
	// menu.setTitle("Main Menu");
	
	main.addItem("number", sayNumber);
	main.addItem("blah", blah);
	main.addItem("quit", [&shouldContinue](IOObj&){ shouldContinue = false; }); 
	// a lambda is a good way to quit.

	while (shouldContinue) main.choose();

}

void runCompressed() {

	bool shouldContinue {true};

	Menu menu {{
		{"number", sayNumber},
		{"blah", blah},
		{"quit", [&shouldContinue](IOObj&){ shouldContinue = false; }}
	}, "Main Menu"};

	while(shouldContinue) menu.choose();

}

void blah(IOObj& io) {	

	io << std::endl;

	io << (yesOrNo(io, "Are you sure?", false) ? "Good." : "Nevermind.");

	io << std::endl << std::endl;

	input<std::string>(io, "type 'hello': ", [](std::string s){ return s == "hello"; });

	io << std::endl;

	input<unsigned int>(io, "type a four digit positive integer: ", [](unsigned int i){ return 999 < i && i <= 9999; });
}

void sayNumber(IOObj& io) {
	int num = input<int>(io, "enter any number: ", [](int i){ return true; });
	io << "Your number was " << num << std::endl;
}

/**
 * ------- Same functions using lambdas instead of blah and sayNumber -------
 */

void runSimpleLambdas() {
	bool shouldContinue {true};

	Menu main {"Main Menu"};
	// menu.setTitle("Main Menu");
	
	main.addItem("number", [](IOObj& io){
		int num = input<int>(io, "enter any number: ", [](int i){ return true; });
		io << "Your number was " << num << std::endl;
	});

	main.addItem("blah", [](IOObj& io){
		io << std::endl;

		io << (yesOrNo(io, "Are you sure?", false) ? "Good." : "Nevermind.");

		io << std::endl << std::endl;

		input<std::string>(io, "type 'hello': ", [](std::string s){ return s == "hello"; });

		io << std::endl;

		input<unsigned int>(io, "type a four digit positive integer: ", [](unsigned int i){ return 999 < i && i <= 9999; });
	});
	
	main.addItem("quit", [&shouldContinue](IOObj&){ shouldContinue = false; }); 

	while (shouldContinue) main.choose();
}

void runCompressedLambdas() {

	bool shouldContinue {true};

	Menu menu {{
		{"number", [](IOObj& io){
			int num = input<int>(io, "enter any number: ", [](int i){ return true; });
			io << "Your number was " << num << std::endl;
		}},
		{"blah", [](IOObj& io){
			io << std::endl;

			io << (yesOrNo(io, "Are you sure?", false) ? "Good." : "Nevermind.");

			io << std::endl << std::endl;

			input<std::string>(io, "type 'hello': ", [](std::string s){ return s == "hello"; });

			io << std::endl;

			input<unsigned int>(io, "type a four digit positive integer: ", [](unsigned int i){ return 999 < i && i <= 9999; });
		}},
		{"quit", [&shouldContinue](IOObj&){ shouldContinue = false; }}
	}};

	while(shouldContinue) menu.choose();

}

}


