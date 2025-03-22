#include "Zombie.hpp"

int main()
{
    //create a zombie on the stack (no memory)
    std::cout << INSTRUCTION << "*Creating a new zombie on the stack*" << RESET << std::endl;
    Zombie zombie1("Rauw Alejandro");
    zombie1.announce();

    //create a zombie on the heap (allocating memory)
    std::cout << INSTRUCTION << "*Creating a new zombie on the heap*" << RESET << std::endl;
    Zombie* zombie2;
    zombie2 = newZombie("jayco JhayCortez");
    zombie2->announce();
    delete(zombie2);

    return 0;
}