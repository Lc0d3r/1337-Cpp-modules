#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    this->fixed_point = 0;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called\n";
    this->fixed_point = n * pow(2, fractional_bits);
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called\n";
    this->fixed_point = roundf(n * pow(2, fractional_bits));
}



Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

int Fixed::getRawBits( void ) const
{
    return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}

float Fixed::toFloat( void ) const {
    return (float)((float)this->fixed_point / pow(2, fractional_bits));
}

int Fixed::toInt( void ) const {
    return (this->fixed_point / pow(2, fractional_bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
    os << fix.toFloat();
    return os;
}