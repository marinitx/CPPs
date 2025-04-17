#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_rawBits = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = other.getRawBits();
    
}

Fixed& Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rawBits = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}