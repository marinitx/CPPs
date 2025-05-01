#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[36m"

int main()
{
    //No se puede hacer esto, porque AAnimal es abstracta:
    //AAnimal animal;  // ERROR: cannot instantiate abstract class

    // se pueden crear objetos de clases derivadas como dog y cat
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();

    //Pero no se podría hacer directamente
    //AAnimal* animal = new AAnimal();

    // llamada a makeSound de las clases derivadas
    std::cout << "The dog says: ";
    dog->makeSound();
    
    std::cout << "The cat says: ";
    cat->makeSound();

    //mostrar el tipo de animal
    std::cout << "The dog is of type: " << dog->getType() << std::endl;
    std::cout << "The cat is of type: " << cat->getType() << std::endl;

    // clean clean cleeaaaan
    delete dog;
    delete cat;

    return 0;
}


