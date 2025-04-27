#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal (const Animal &copy);
        virtual ~Animal();
        Animal &operator=(const Animal &copy);

        virtual void makeSound() const;
        std::string getType(void)const;
        void setType(std::string type);
};

#endif