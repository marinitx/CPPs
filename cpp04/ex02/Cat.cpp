#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_brain = new Brain();
    this->_type = "Cat";
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = new Brain(*copy._brain);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &copy)
    {
        delete _brain;
        _brain = new Brain(*copy._brain);
        _type = copy._type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "\n /\\_/\\ " << std::endl;
    std::cout << "( o.o ) " << std::endl;
    std::cout << " > ^ <    miau\n" << std::endl;    
}

void Cat::setIdea(int index, const std::string& idea)
{
    this->_brain->setIdea(index, idea);
}
    
std::string Cat::getIdea(int index) const
{
    return this->_brain->getIdea(index);
}
