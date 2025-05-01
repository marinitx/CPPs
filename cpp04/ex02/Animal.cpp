#include "Animal.hpp"

AAnimal::AAnimal() : _type("default")
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = copy;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
    std::cout << "AAnimal assignation operator called" << std::endl;
    this->_type = copy._type;
    return *this;
}

std::string AAnimal::getType() const
{
    return (this->_type);
}

void AAnimal::setType(std::string type)
{
    this->_type = type;
}
