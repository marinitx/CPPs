#pragma once

#include <iostream>
#include <limits> //numeric limits
#include <cctype> // For std::isdigit, std::isprint
#include <string>

class ScalarConverter
{
    private:
        ScalarConverter(); //si lo de3jo privado ya no es instanciable ;)
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();

    public:
        static void convert(const std::string& literal);
        const char charConvert(const std::string &c);
        int intConvert(const std::string &i);
        const float floatConvert(const std::string &f);
        const double doubleConvert(const std::string &d);

};
