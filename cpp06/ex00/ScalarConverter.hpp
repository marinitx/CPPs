#pragma once

#include <iostream>
#include <cstdlib>
#include <climits>
#include <limits.h>
#include <cfloat>
#include <limits>
#include <cctype>
#include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter(); //si lo de3jo privado ya no es instanciable ;)
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();

    public:
        static void convert(const std::string& literal);
        int intConvert(const std::string &i);

};
