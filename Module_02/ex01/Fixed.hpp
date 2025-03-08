#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    public:
        Fixed(); // Default Constructor
        Fixed(const int n);// Parameterized Constructor
        Fixed(const float n);
        Fixed(const Fixed& other); // Copy Constructor
        Fixed&  operator=(const Fixed& other); // copy Assignment Operator overload
        ~Fixed(); // Destructor
        
        // and some member func
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        
};

// << Operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fix);  

#endif