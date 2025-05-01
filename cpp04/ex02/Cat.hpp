#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
    Brain* _brain;

public:
    Cat();
    Cat(const Cat &copy);
    ~Cat();

    Cat &operator=(const Cat &copy);
    
    void makeSound() const;

    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif
