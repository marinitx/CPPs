#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria()
{
	this->_type =  "cure";
}

Cure::~Cure(void) {}

Cure &Cure::operator=(const Cure& c)
{
	this->_type = c._type;
	return *this;
}

Cure::Cure(const Cure& c)
{
	*this = c;
	std::cout << "Cure copy constructor called" << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<"'s wounds *" << std::endl;
}

AMateria* Cure::clone(void) const
{
	return (new Cure);
}
