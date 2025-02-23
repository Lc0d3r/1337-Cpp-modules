#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    public:
        Fixed(); // Default Constructor
        // Parameterized Constructor
        Fixed(const Fixed& other); // Copy Constructor
        Fixed& operator=(const Fixed& other); // copy Assignment Operator
        ~Fixed(); // Destructor

        // and some member func
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif