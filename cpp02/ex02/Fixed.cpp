#include "Fixed.hpp"

// constructor por defecto pone el valor a 0
Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// constructor con un número entero convierte el número al formato que usa esta clase
Fixed::Fixed(const int intVal)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = intVal << _fractionalBits;
}

// constructor con un número decimal convierte el número al formato que usa esta clase
Fixed::Fixed(const float floatVal)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(floatVal * (1 << _fractionalBits));
}

// constructor por copia crea un objeto igual a otro
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = other._rawBits;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// operador de asignación copia el valor de otro objeto
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_rawBits = other.getRawBits();
	return *this;
}

// devuelve el valor interno del número
int Fixed::getRawBits(void) const
{
	return _rawBits;
}

// cambia el valor interno del número
void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

// convierte el valor a  decimal
float Fixed::toFloat(void) const
{
	return (float)_rawBits / (1 << _fractionalBits);
}

// convierte el valor a entero
int Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

// compara numeros
bool Fixed::operator>(const Fixed& other) const { return _rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed& other) const { return _rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed& other) const { return _rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed& other) const { return _rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed& other) const { return _rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed& other) const { return _rawBits != other._rawBits; }

// suma numeros
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}

// resta números
Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}

// multiplica números
Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->_rawBits * other._rawBits) >> _fractionalBits);
	return result;
}

// divide numeros
Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->_rawBits << _fractionalBits) / other._rawBits);
	return result;
}

// suma un poco
Fixed& Fixed::operator++()
{
	_rawBits++;
	return *this;
}

// suma un poco pero devuelve el valor original
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	_rawBits++;
	return temp;
}

// resta un poco
Fixed& Fixed::operator--()
{
	_rawBits--;
	return *this;
}

// resta un poco pero devuelve el valor original
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	_rawBits--;
	return temp;
}

// devuelve el menor de dos números (versión no constante)
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

// devuelve el menor de dos números (versión constante)
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

// devuelve el mayor de dos números (versión no constante)
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

// devuelve el mayor de dos números (versión constante)
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

// permite mostrar el número por pantalla como decimal
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}