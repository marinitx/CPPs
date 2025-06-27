#pragma once

#include <iostream>
#include <string>

class ScalarConverter
{
    public:
        static void convert(const std::string& literal);

    private:
        ScalarConverter(); //si lo de3jo privado ya no es instanciable ;)
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
};
