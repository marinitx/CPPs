#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n***** Test con rango  *****" << std::endl;
    try
    {
        Span sp2(10);
        std::vector<int> nums;
        for (int i = 0; i < 10; ++i)
            nums.push_back(i * 5); //cada númerito separado por distancia de 5*n (exponencial)

        sp2.addRange(nums.begin(), nums.end());

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n(exception more than available)" << std::endl;
    try
    {
        Span sp3(3);
        sp3.addNumber(1);
        sp3.addNumber(2);
        sp3.addNumber(3);
        sp3.addNumber(4); //este ya no cabe
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n(exception less than 2 numbers)" << std::endl;
    try
    {
        Span sp4(5);
        sp4.addNumber(42);
        std::cout << sp4.shortestSpan() << std::endl; //solo hay 1 numero
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

