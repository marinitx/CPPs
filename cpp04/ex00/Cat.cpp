#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignation operator called" << std::endl;
    this->_type = copy._type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << " /\\_/\\ " << std::endl;
    std::cout << "( o.o ) " << std::endl;
    std::cout << " > ^ <    miau\n" << std::endl;    
}