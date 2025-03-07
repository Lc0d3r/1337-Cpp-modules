#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

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
        
        // friend std::ostream& operator<<(std::ostream& os, const Fixed& fix);        // << Operator overload

        bool operator>(const Fixed& f);
        bool operator<(const Fixed& f);
        bool operator>=(const Fixed& f);
        bool operator<=(const Fixed& f);
        bool operator==(const Fixed& f);
        bool operator!=(const Fixed& f);
        Fixed operator+(const Fixed& f);
        Fixed operator-(const Fixed& f);
        Fixed operator*(const Fixed& f);
        Fixed operator/(const Fixed& f);

        Fixed operator++();
        Fixed operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed& min(Fixed& f1, Fixed& f2);
        static Fixed& min(const Fixed& f1, const Fixed& f2);
        static Fixed& max(Fixed& f1, Fixed& f2);
        static Fixed& max(const Fixed& f1, const Fixed& f2);      
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif