#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignation operator called" << std::endl;
    this->_type = copy._type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "..^____/" << std::endl;
    std::cout << "`-. ___ )" << std::endl;
    std::cout << "  ||  ||      guau\n" << std::endl;
}