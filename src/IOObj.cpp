/*
 * IOObj.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: Akash
 */

#include "IOObj.h"

namespace SimpleTextUI {

void IOObj::setInput(std::istream* in) {
	releaseIn();
	this->i = in;
	iOwner = true;
}

void IOObj::setInput(std::istream& in) {
	releaseIn();
	this->i = &in;
	iOwner = false;
}

void IOObj::setOutput(std::ostream* out) {
	releaseOut();
	this->o = out;
	oOwner = true;
}

void IOObj::setOutput(std::ostream& out) {
	releaseOut();
	this->o = &out;
	oOwner = false;
}

} /* namespace SimpleTextUI */
