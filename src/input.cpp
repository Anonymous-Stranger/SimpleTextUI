/*
 * input.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: Akash
 */

#include "input.h"

namespace SimpleTextUI {

	void ignoreInputToNewline(std::istream& in) {
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	bool yesOrNo(IOObj& io, std::string message) {
		for(;;) { // exited in switch

			io << message << " (y/n): ";

			char c;
			while ((c = io.in().get()) != '\n' && isspace(c)); // goto first non-whitespace

			if (c != '\n') ignoreInputToNewline(io);

			switch(c) {
			case 'y': case 'Y': return true;
			case 'n': case 'N': return false;
			default: continue;
			}

		}
	}

	bool yesOrNo(IOObj& io, std::string message, bool defaultVal) {

		for(;;) { // exited in switch

			io << message << " (" << (defaultVal ? 'Y' : 'y');
			io << '/' << (defaultVal ? 'n' : 'N') << "): ";

			char c;
			while ((c = io.in().get()) != '\n' && isspace(c)); // goto first non-whitespace

			if (c == '\n') return defaultVal;

			ignoreInputToNewline(io);

			switch(c) {
			case 'y': case 'Y': return true;
			case 'n': case 'N': return false;
			default: continue;
			}

		}

	}

}


