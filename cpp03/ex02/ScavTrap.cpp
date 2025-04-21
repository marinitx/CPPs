#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unnamed")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor for " << name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor for " << _name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    ClapTrap::operator=(copy);
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "ScavTrap " << _name << " can't attack!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " has entered Gate keeper mode!" << std::endl;
}
