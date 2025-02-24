#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    this->fixed_point = 0;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called\n";
    this->fixed_point = n * 256;
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called\n";
    this->fixed_point = n * 256;
}



Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
    fixed_point = other.fixed_point;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->setRawBits(other.getRawBits());
    return *this;

}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}

float Fixed::toFloat( void ) const {
    return (float)((float)this->fixed_point / (float)256);
}

int Fixed::toInt( void ) const {
    return (this->fixed_point / 256);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
    os << fix.toFloat();
    return os;
}