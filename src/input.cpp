/*
 * input.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: Akash
 */

#include "input.h"

namespace SimpleTextUI {

	void ignoreInputToNewline(std::istream& in) {
        in.clear();
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::string inputStr(
		IOObj& io,
		std::string message,
		std::function<bool(std::string)> isValid,
		bool trim
	) {

		std::string whitespaces {" \f\n\r\t\v"};
		std::string str;

		for (;;) { // loop broken by break statement

			io.in().clear();

			io << message;

			std::getline(io.in(), str);

			if (io.in().fail()) continue;
			if (io.in().bad()) throw OutputBrokenError();

			if (trim) str = str.substr(str.find_first_not_of(whitespaces), str.find_last_not_of(whitespaces)+1);

			if (isValid(str)) break;

		}

		return str;

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


