#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Animals ===" << std::endl;

    const Animal* random = new Animal();
    const Animal* puppy = new Dog();
    const Animal* kitten = new Cat();

    std::cout << puppy->getType() << " " << std::endl;
    std::cout << kitten->getType() << " " << std::endl;
    std::cout << random->getType() << " " << std::endl;

    kitten->makeSound();
    puppy->makeSound();
    random->makeSound();

    delete puppy;
    delete kitten;
    delete random;

    std::cout << "\n=== Wrong Animals ===" << std::endl;

    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongKitten = new WrongCat();

    std::cout << wrong->getType() << " " << std::endl;
    std::cout << wrongKitten->getType() << " " << std::endl;

    wrong->makeSound();
    wrongKitten->makeSound();

    delete wrong;
    delete wrongKitten;

    return 0;
}
