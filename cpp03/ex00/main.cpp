#include "ClapTrap.hpp"

int main()
{
    ClapTrap piplup("Piplup");
    ClapTrap chimchar("Chimchar");

    std::cout << "\n🔥 Battle Start! 🔥\n" << std::endl;

    piplup.attack("Chimchar");
    chimchar.takeDamage(2);

    chimchar.attack("Piplup");
    piplup.takeDamage(3);

    piplup.beRepaired(4);
    chimchar.beRepaired(2);

    chimchar.attack("Piplup");
    piplup.takeDamage(5);

    std::cout << "\n💥 Final Moves 💥\n" << std::endl;

    piplup.attack("Chimchar");
    chimchar.takeDamage(4);

    chimchar.attack("Piplup");
    piplup.takeDamage(6);

    std::cout << "\n🏁 Battle Ended 🏁\n" << std::endl;

    return 0;
}
