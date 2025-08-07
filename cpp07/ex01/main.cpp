#include "iter.hpp"

template <typename T>
void printElement(T& element)
{
    std::cout << element << std::endl;
}

template <typename T>
void incrementElement(T& element)
{
    ++element;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    std::string stringArray[] = {"holi", "que tal", "bien gracias"};
    double doubleArray[] = {1.1, 2.2, 3.3};

    std::cout << "este es el array de ints:" << std::endl;
    iter(intArray, 5, printElement<int>);

    std::cout << "este es el array de ints incrementado" << std::endl;
    iter(intArray, 5, incrementElement<int>);
    iter(intArray, 5, printElement<int>);

    std::cout << "este es el array de strings:" << std::endl;
    iter(stringArray, 3, printElement<std::string>);

    std::cout << "este es el array de doubles:" << std::endl;
    iter(doubleArray, 3, printElement<double>);

    return 0;
}
