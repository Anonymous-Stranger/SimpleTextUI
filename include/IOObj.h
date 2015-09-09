/*
 * IOObj.h
 *
 *  Created on: Aug 17, 2015
 *      Author: Akash
 */

#ifndef SIMPLE_TEXT_UI_IOOBJ_H_
#define SIMPLE_TEXT_UI_IOOBJ_H_

#include <iostream>
#include "Errors.h"

namespace SimpleTextUI {

class IOObj: public std::iostream {
public:

	IOObj(std::istream& in=std::cin, std::ostream& out=std::cout):
		i{&in}, o{&out}, iOwner{false}, oOwner{false} {}
	IOObj(std::istream& in, std::ostream* out): i{&in}, o{out}, iOwner{false}, oOwner{true} {}
	IOObj(std::istream* in, std::ostream& out): i{in}, o{&out}, iOwner{true}, oOwner{false} {}
	IOObj(std::istream* in, std::ostream* out): i{in}, o{out}, iOwner{true}, oOwner{true} {}

	IOObj(const IOObj&)=delete;
	IOObj& operator=(const IOObj&)=delete;

	~IOObj() { releaseIO(); }

	std::istream& in() { return *i; }
	std::ostream& out() { return *o; }

	void setInput(std::istream* in);
	void setInput(std::istream& in);
	void setOutput(std::ostream* out);
	void setOutput(std::ostream& out);

	void outputSeparator() { *o << "-------------------------------" << std::endl; }

protected:
	IOObj(IOObj&&)=default;
	IOObj& operator=(IOObj&&)=default;

private:
	std::istream* i;
	std::ostream* o;
	bool iOwner, oOwner;

	void releaseIO() {
		releaseIn();
		releaseOut();
	}

	void releaseIn() { if (iOwner) delete i; }
	void releaseOut() { if (oOwner) delete o; }

};

template<typename T>
inline IOObj& operator<<(IOObj& io, T output) {
	io.out() << output;
	if (io.out().fail()) throw OutputFailedError{};
	if (io.out().bad()) throw OutputBrokenError{};
	return io;
}

inline IOObj& operator<<(IOObj& io, std::ostream& (*manip) (std::ostream&) ) {
	io.out() << manip;
	if (io.out().fail()) throw OutputFailedError{};
	if (io.out().bad()) throw OutputBrokenError{};
	return io;
}

template<typename T>
inline IOObj& operator>>(IOObj& io, T& input) {
	io.in() >> input;
	if (io.in().fail()) throw InputFailedError{};
	if (io.in().bad()) throw InputBrokenError{};
	return io;
}

} /* SimpleTextUI */

#endif /* IOOBJ_H_ */
