#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor for " << name << " called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << "FragTrap copy constructor called!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    ClapTrap::operator=(copy);
    std::cout << "FragTrap assignment operator called!" << std::endl;
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " damage!" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "FragTrap " << _name << " is too tired or damaged to attack!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests a high five! 🖐️" << std::endl;
}