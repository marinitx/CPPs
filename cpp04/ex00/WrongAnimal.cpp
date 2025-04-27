#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    this->_type = copy._type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "* WrongAnimal sounds *" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}