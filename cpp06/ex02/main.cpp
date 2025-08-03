#include "Base.hpp"

int main()
{
    Base* ptr = generate();

    std::cout << "Identify using pointer: ";
    identify(ptr);

    std::cout << "Identify using reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}
