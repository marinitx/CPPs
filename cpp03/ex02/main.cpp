#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
    std::cout << "Constructing" << std::endl;
    ScavTrap squirtle("Squirtle");
    ScavTrap psyduck("Psyduck");

    std::cout << "Testing" << std::endl;
    squirtle.attack("Psyduck");
    psyduck.takeDamage(20);
    psyduck.attack("Squirtle");
    squirtle.takeDamage(20);

    squirtle.beRepaired(15);
    psyduck.guardGate();
    squirtle.guardGate();

    for (int i = 0; i < 3; i++)
        psyduck.attack("wild Pidgeotto");

    psyduck.takeDamage(100);
    std::cout << "Deconstructing" << std::endl;

	std::cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
    std::cout << "Constructing" << std::endl;
    FragTrap bulbasaur("Bulbasaur");
    FragTrap charmander("Charmander");

    std::cout << "Testing" << std::endl;
    bulbasaur.attack("Charmander");
    charmander.takeDamage(30);

    charmander.beRepaired(10);
    charmander.attack("Bulbasaur");
    bulbasaur.takeDamage(30);

    bulbasaur.highFivesGuys();
    charmander.highFivesGuys();

    for (int i = 0; i < 5; i++)
        bulbasaur.attack("wild Zubat");

    std::cout << "Deconstructing" << std::endl;

	return 0;
}