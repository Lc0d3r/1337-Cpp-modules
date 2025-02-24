#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called\n";
    this->fixed_point = 0;
}

Fixed::Fixed(const int n)
{
    // std::cout << "Int constructor called\n";
    this->fixed_point = n * 256;
}

Fixed::Fixed(const float n)
{
    // std::cout << "Float constructor called\n";
    this->fixed_point = roundf(n * 256);
}



Fixed::Fixed(const Fixed& other)
{
    // std::cout << "Copy constructor called\n";
    fixed_point = other.fixed_point;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
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

bool Fixed::operator>(const Fixed& f)
{
    if (this->fixed_point > f.fixed_point)
        return true;
    return false;
}
bool Fixed::operator<(const Fixed& f)
{
    if (this->fixed_point < f.fixed_point)
        return true;
    return false;
}
bool Fixed::operator>=(const Fixed& f)
{
    if (this->fixed_point >= f.fixed_point)
        return true;
    return false;
}
bool Fixed::operator<=(const Fixed& f)
{
    if (this->fixed_point <= f.fixed_point)
        return true;
    return false;
}
bool Fixed::operator==(const Fixed& f)
{
    if (this->fixed_point == f.fixed_point)
        return true;
    return false;
}
bool Fixed::operator!=(const Fixed& f)
{
    if (this->fixed_point != f.fixed_point)
        return true;
    return false;
}
Fixed Fixed::operator+(const Fixed& f)
{
    return Fixed(this->toFloat() + f.toFloat());
}
Fixed Fixed::operator-(const Fixed& f)
{
    return Fixed(this->toFloat() - f.toFloat());
}
Fixed Fixed::operator*(const Fixed& f)
{
    return Fixed(this->toFloat() * f.toFloat());
}
Fixed Fixed::operator/(const Fixed& f)
{
    return Fixed(this->toFloat() / f.toFloat());
}

//prefix
Fixed Fixed::operator++()
{
    this->fixed_point++;
    return *this;
}

Fixed Fixed::operator--()
{
    this->fixed_point++;
    return *this;
}
//postfix
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->fixed_point++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->fixed_point--;
    return temp;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f1 < f2)
        return (f1);
    return f2;
}

Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if ((Fixed&)f1 < (Fixed&)f2)
        return ((Fixed&)f1);
    return (Fixed&)f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    if (f1 > f2)
        return (f1);
    return f2;
}

Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    if ((Fixed&)f1 > (Fixed&)f2)
        return ((Fixed&)f1);
    return (Fixed&)f2;
}