#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_brain = new Brain();
    this->_type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain(*copy._brain);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &copy)
    {
        delete _brain;
        _brain = new Brain(*copy._brain);
        _type = copy._type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "..^____/" << std::endl;
    std::cout << "`-. ___ )" << std::endl;
    std::cout << "  ||  ||      guau\n" << std::endl;
}


void Dog::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        this->_brain->setIdea(index, idea);
    else
        std::cerr << "Error: only valid index from 0 to 99\n";
}
    
std::string Dog::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return this->_brain->getIdea(index);
    else
    {
        std::cerr << "Error: only valid index from 0 to 99\n";
        return "";
    }
}