#include "Zombie.hpp"

int main()
{
    std::cout << INSTRUCTION << "*Creating a zombie on the stack*" << RESET << std::endl;
    Zombie zombie1("Rauw Alejandro");
    zombie1.announce();

    std::cout << INSTRUCTION << "*Creating a zombie on the heap*" << RESET << std::endl;
    Zombie* zombie2;
    zombie2 = newZombie("jayco JhayCortez");
    zombie2->announce();
    delete(zombie2);

    std::cout << INSTRUCTION << "Creating a zombie with randomChump" << RESET << std::endl;
    randomChump("Bad Gyal");

    return 0;
}