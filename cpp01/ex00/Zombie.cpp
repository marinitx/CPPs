#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << SUCCESS << this->name << " has been destroyed successfully" << RESET << std::endl;
}

void Zombie::announce( void )
{
    std::cout << INFO << this->name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}