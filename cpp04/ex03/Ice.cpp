#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria()
{
	this->_type =  "ice";
}

Ice::~Ice(void) {}

Ice &Ice::operator=(const Ice& c)
{
	this->_type = c._type;
	return *this;
}

Ice::Ice(const Ice& c)
{
	*this = c;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*"<< std::endl;
}
AMateria* Ice::clone (void) const
{
	return (new Ice);
}
