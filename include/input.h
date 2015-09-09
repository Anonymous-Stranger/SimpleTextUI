/*
 * input.h
 *
 *  Created on: Aug 17, 2015
 *      Author: Akash
 */

#ifndef SIMPLE_TEXT_UI_INPUT_H_
#define SIMPLE_TEXT_UI_INPUT_H_

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
        bool failed {false};
        
        do {
            io << message;
            try { 
                io >> obj;
                failed = false;
            } catch (InputFailedError) { failed = true; }
            ignoreInputToNewline(io);
        } while (failed || !isValid(obj));

        return obj;
    }

	bool yesOrNo(IOObj& io, std::string message);
	bool yesOrNo(IOObj& io, std::string message, bool defaultVal);

} /* namespace SimpleTextUI */

#endif /* INPUT_H_ */
