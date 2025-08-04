#include "ScalarConverter.hpp"


// COMPROBACIONES ********
static bool isChar(const std::string &s)
{
    return s.length() == 1 && !std::isdigit(s[0]);
}

/*
convierte s a un long int
guarda en end un puntero al priemr caracter que no puede convertir
ex. 123hola apunta a h (return false)
123 apunta a '\0' (return true)
*/
static bool isInt(const std::string &s)
{
    char *end;
    std::strtol(s.c_str(), &end, 10);
    return *end == '\0' && end != s.c_str(); //no haya quedado nada sin convertir y al menos algo se haya convertido (true)
}

//convierte en double y comprueba que al final haya una f y nada mas después
static bool isFloat(const std::string &s)
{
    if (s == "+inff" || s == "-inff" || s == "nanf")
        return true;
    char *end;
    std::strtod(s.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

static bool isDouble(const std::string &s)
{
    if (s == "+inf" || s == "-inf" || s == "nan")
        return true;
    char *end;
    std::strtod(s.c_str(), &end);
    return *end == '\0';
}


// IMPRIME ********
static void printChar(int c)
{
    std::cout << "char: ";
    if (c >= CHAR_MIN && c <= CHAR_MAX)
    {
        if (std::isprint(c))
            std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

static void printFloat(double val)
{
    if (val <= -1000000.0 || val >= 1000000.0 || floor(val) != val)
        std::cout << "f" << std::endl;
    else
        std::cout << ".0f" << std::endl;
}

static void printDouble(double val)
{
    if (val <= -1000000.0 || val >= 1000000.0 || floor(val) != val)
        std::cout << std::endl;
    else
        std::cout << ".0" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    if (isChar(literal))
    {
        char c = literal[0];
        printChar(c);
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    if (isInt(literal))
    {
        long val = std::strtol(literal.c_str(), NULL, 10);
        printChar(static_cast<int>(val));
        if (val < INT_MIN || val > INT_MAX)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(val) << std::endl;
        std::cout << "float: " << static_cast<float>(val);
        printFloat(static_cast<double>(val));
        std::cout << "double: " << static_cast<double>(val);
        printDouble(static_cast<double>(val));
        return;
    }

    if (isFloat(literal))
    {
        std::string copy = literal.substr(0, literal.length() - 1);
        double tmp = std::strtod(copy.c_str(), NULL);
        float val = static_cast<float>(tmp);
        printChar(static_cast<int>(tmp));

        std::cout << "int: ";
        if (tmp < static_cast<double>(INT_MIN) || tmp > static_cast<double>(INT_MAX) || tmp != tmp)
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(tmp) << std::endl;

        std::cout << "float: " << val;
        printFloat(tmp);

        std::cout << "double: " << tmp;
        printDouble(tmp);
        return;
    }

    if (isDouble(literal))
    {
        double val = std::strtod(literal.c_str(), NULL);
        printChar(static_cast<int>(val));

        std::cout << "int: ";
        if (val < static_cast<double>(INT_MIN) || val > static_cast<double>(INT_MAX) || val != val)
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(val) << std::endl;

        std::cout << "float: " << static_cast<float>(val);
        printFloat(val);

        std::cout << "double: " << val;
        printDouble(val);
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

/*

Your program must detect the literal’s type, acquire that literal in the right type (so
it’s not a string anymore), then convert it explicitly to each of the three other types and
display the results using the same formatting as below. If a conversion does not make
sense or overflows, display that the conversion is impossible. You can include any header
you need to handle numeric limits and special values.

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/