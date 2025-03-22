#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

#define ERROR "\033[91m" //red
#define INSTRUCTION "\033[95m" //purple
#define SUCCESS "\033[92m" //green
#define INFO "\033[96m" //cyan
#define RESET "\033[0m" //white
#define PINK "\033[95m"

class Zombie
{
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce( void );
        
    private:
        std::string name;
};

        void randomChump(std::string name);
        Zombie* newZombie(std::string name);

#endif