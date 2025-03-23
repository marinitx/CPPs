#include "Zombie.hpp"

#ifndef N
#define N 4
#endif

int main()
{
    Zombie *horde = NULL;

    horde = zombieHorde(N, "Gengar");
    for (int i = 0; i < N; i++)
        horde[i].announce();
    
    delete [] horde;
    return 0;
}