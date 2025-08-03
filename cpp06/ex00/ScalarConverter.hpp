#pragma once

#include <limits.h>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
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

};
