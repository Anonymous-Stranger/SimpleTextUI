
#include <iostream>
#include <stdexcept>

#include "_test.h"

int main() try {

    SimpleTextUITest::run();

} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
} catch (...) {
    std::cerr << "SimpleTextUI Test: something failed." << std::endl;    
}
