#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    // the line below calls the copy constructor
    Fixed b( a );
    Fixed c;

    // this ==> c.operator=(b); is the same as the  line bellow
    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}