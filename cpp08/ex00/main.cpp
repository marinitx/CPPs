#include "easyfind.hpp"

int main()
{
    try
    {
        //ejemplito con array
        std::vector<int> arr;
        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);

        std::vector<int>::iterator it = easyfind(arr, 20);
        std::cout << "Found: " << *it << std::endl;

        //y con listas
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);

        std::list<int>::iterator it2 = easyfind(lst, 4); //no lo encuentra
        std::cout << "Found: " << *it2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
