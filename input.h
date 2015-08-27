/*
 * input.h
 *
 *  Created on: Aug 17, 2015
 *      Author: Akash
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <functional>
#include <limits>
#include "IOObj.h"

namespace SimpleTextUI {

	void ignoreInputToNewline(std::istream& in);
	inline void ignoreInputToNewline(IOObj& io) { ignoreInputToNewline(io.in()); }

	template<typename T>
	inline T input(
		IOObj& io,
		std::string message,
		std::function<bool(T)> isValid=[](T){ return true; }
	) {
		T obj;

		do {
			io << message;
			io >> obj;
			ignoreInputToNewline(io);
		} while (!isValid(obj));

		return obj;
	}

	bool yesOrNo(IOObj& io, std::string message);
	bool yesOrNo(IOObj& io, std::string message, bool defaultVal);

} /* namespace SimpleTextUI */

#endif /* INPUT_H_ */
