/*
 * SimpleTextUIErrors.h
 *
 *  Created on: Aug 19, 2015
 *      Author: Akash
 */

#ifndef SIMPLETEXTUIERRORS_H_
#define SIMPLETEXTUIERRORS_H_

#include <stdexcept>

namespace SimpleTextUI {

struct SimpleTextUIError: std::runtime_error {
	SimpleTextUIError(std::string message="something failed"): std::runtime_error("Simple Text UI: "+message) {}
};

struct OutputFailedError: SimpleTextUIError {
	OutputFailedError(std::string message="output failed"): SimpleTextUIError(message) {}
};

struct OutputBrokenError: SimpleTextUIError {
	OutputBrokenError(std::string message="output failed; probably not recoverable"): SimpleTextUIError(message) {}
};

struct InputFailedError: SimpleTextUIError {
	InputFailedError(std::string message="input failed"): SimpleTextUIError(message) {}
};

struct InputBrokenError: SimpleTextUIError {
	InputBrokenError(std::string message="input failed; probably not recoverable"): SimpleTextUIError(message) {}
};

} /* namespace ZombieCities */

#endif /* SIMPLETEXTUIERRORS_H_ */
