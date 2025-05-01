#include "Animal.hpp"

Animal::Animal() : _type("default")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal assignation operator called" << std::endl;
    this->_type = copy._type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "* Unbearable sound *" << std::endl;
}

std::string Animal::getType() const
{
    return (this->_type);
}

void    Animal::setType(std::string type)
{
    this->_type = type;
}