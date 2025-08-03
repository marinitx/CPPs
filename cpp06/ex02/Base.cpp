#include "Base.hpp"

Base* generate(void)
{
    srand(static_cast<unsigned int>(time(NULL)));

    int randNum = rand() % 3;
    switch (randNum)
    {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
    }
    return NULL; //se supone que no llega nunca pero así me evito warnings
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type is C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type is A" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type is B" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type is C" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}
    
    std::cout << "Unknown type" << std::endl;
}
