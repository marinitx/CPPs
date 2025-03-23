#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() 
{
    std::cout << SUCCESS << this->name << " has been successfully destroyed." << RESET << std::endl;    
}

void Zombie::announce()
{
    std::cout << INFO << this->name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::addName(std::string name)
{
    this->name = name;
}