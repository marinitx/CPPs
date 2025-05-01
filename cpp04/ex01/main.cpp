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
    const int SIZE = 4;

    std::cout << BLUE << "\n[1] CREANDO ARRAY DE ANIMALES\n" << RESET;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << BLUE << "\n[2] SONIDOS \n" << RESET;
    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();

    std::cout << BLUE << "\n[3] PROBANDO IDEAS EN DOG\n" << RESET;
    Dog* originalDog = new Dog();
    originalDog->setIdea(0, "Catch the ball");
    originalDog->setIdea(1, "Pee");

    std::cout << "Original Dog idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Original Dog idea 1: " << originalDog->getIdea(1) << std::endl;

    std::cout << BLUE << "\n[4] HACIENDO DEEP COPY DE DOG\n" << RESET;
    Dog* copiedDog = new Dog(*originalDog);
    copiedDog->setIdea(0, "Run after a bird");

    std::cout << GREEN << "\n--- Verificando que sí es deepcopy ---\n" << RESET;
    std::cout << "Original Dog idea 0 (should be unchanged): " << originalDog->getIdea(0) << std::endl;
    std::cout << "Copied Dog idea 0 (should be new):        " << copiedDog->getIdea(0) << std::endl;

    std::cout << BLUE << "\n[5] ELIMINANDO ORIGINAL Y COPIA\n" << RESET;
    delete originalDog;
    delete copiedDog;

    std::cout << BLUE << "\n[6] BORRANDO EL ARRAY ENTERO\n" << RESET;
    for (int i = 0; i < SIZE; i++)
        delete animals[i];

    return 0;
}
