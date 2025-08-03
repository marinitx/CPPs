#include "Array.hpp"

int main() {
    //array vacio
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    //array de 5 default
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    for (unsigned int i = 0; i < intArray.size(); ++i)
    {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    //cambiando cositas
    for (unsigned int i = 0; i < intArray.size(); ++i)
    {
        intArray[i] = i * 10;
    }

    std::cout << "Modified intArray:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); ++i)
    {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    //constructor de copia prueba
    Array<int> copiedArray(intArray);
    std::cout << "Copied array (deep copy test):" << std::endl;
    for (unsigned int i = 0; i < copiedArray.size(); ++i)
    {
        std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
    }

    //comprobar si es una copia profunda porque estoy modificando la original
    intArray[0] = 999;
    std::cout << "After modifying intArray[0], copiedArray[0] = " << copiedArray[0] << std::endl;

    try
    {
        std::cout << "Accessing out of range: " << intArray[10] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    Array<std::string> stringArray(3);
    stringArray[0] = "holiwi";
    stringArray[1] = "soy";
    stringArray[2] = "marina";

    std::cout << "String array:" << std::endl;
    for (unsigned int i = 0; i < stringArray.size(); ++i) {
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
    }

    return 0;
}
