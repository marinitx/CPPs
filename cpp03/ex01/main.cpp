#include "ScavTrap.hpp"

int main()
{
    std::cout << "Creating Piplup..." << std::endl;
    ClapTrap piplup("Piplup");

    std::cout << "Creating Chimchar (ScavTrap)..." << std::endl;
    ScavTrap chimchar("Chimchar");

    std::cout << "\n🔥 Battle Start 🔥\n" << std::endl;
    piplup.attack("Chimchar");
    chimchar.takeDamage(1);

    chimchar.attack("Piplup");
    piplup.takeDamage(20);

    chimchar.guardGate();

    std::cout << "\n🏁 Battle Ended 🏁\n" << std::endl;
    return 0;
}