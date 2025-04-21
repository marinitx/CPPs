#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Clappy"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "Assignation operator called" << std::endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints <= 0)
        std::cout << "ClapTrap " << this->_name << " cannot attack! Not enough energy left." << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout << "ClapTrap " << this->_name << " cannot attack! Not enough hit points left." << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return ;
	}
	this->_hitPoints = this->_hitPoints - amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage! "<< this->_hitPoints << " HP left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints <= 0)
        std::cout << "ClapTrap " << this->_name << " cannot be repaired! Not enough energy left." << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout << "ClapTrap " << this->_name << " cannot be repaired! Not enough hit points left." << std::endl;
    else
    {
	    this->_energyPoints--;
	    this->_hitPoints = this->_hitPoints + amount;
        std::cout << "Claptrap " << this->_name << " healed and now has " << amount << " HP and now has " << this->_energyPoints << " energy left." << std::endl;
    }
}