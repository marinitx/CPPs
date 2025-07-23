#include "ScalarConverter.hpp"

static bool isChar(const std::string &s)
{
    return s.length() == 1 && !std::isdigit(s[0]);
}

bool isInt(const std::string &s)
{
    char *end;
    std::strtol(s.c_str(), &end, 10);
    return *end == '\0' && end != s.c_str();
}

static bool isFloat(const std::string &s)
{
    if (s == "+inff" || s == "-inff" || s == "nanf")
        return true;
    char *end;
    std::strtod(s.c_str(), &end);
    return *(end) == 'f';
}

static bool isDouble(const std::string &s)
{
    if (s == "+inf" || s == "-inf" || s == "nan")
        return true;
    char *end;
    std::strtod(s.c_str(), &end);
    return *end == '\0';
}

void ScalarConverter::convert(const std::string &literal)
{
    std::cout.precision(1);
    std::cout.setf(std::ios::fixed);

    if (isChar(literal)) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    // INT
    if (isInt(literal))
    {
        long val = std::strtol(literal.c_str(), NULL, 10);
        if (val < CHAR_MIN || val > CHAR_MAX)
            std::cout << "char: impossible" << std::endl;
        else if (val >= 32 && val <= 126)
            std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (val < INT_MIN || val > INT_MAX)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(val) << std::endl;

        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(val) << std::endl;
        return;
    }

    // FLOAT
    if (isFloat(literal))
    {
        std::string copy = literal.substr(0, literal.length() - 1);
        double tmp = std::strtod(copy.c_str(), NULL);
        float val = static_cast<float>(tmp);

        // CHAR
        if (tmp != tmp || tmp > 126 || tmp < 0)
            std::cout << "char: impossible" << std::endl;
        else if (tmp >= 32 && tmp <= 126)
            std::cout << "char: '" << static_cast<char>(tmp) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        // INT
        if (tmp != tmp || tmp < static_cast<double>(INT_MIN) || tmp > static_cast<double>(INT_MAX))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(tmp) << std::endl;

        // FLOAT y DOUBLE
        std::cout << "float: " << val << "f" << std::endl;
        std::cout << "double: " << tmp << std::endl;
        return;
    }



    // DOUBLE
    if (isDouble(literal))
    {
        double val = std::strtod(literal.c_str(), NULL);

        if (val != val || val == std::numeric_limits<double>::infinity() || val == -std::numeric_limits<double>::infinity())
            std::cout << "char: impossible" << std::endl;
        else if (val >= 32 && val <= 126)
            std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (val < INT_MIN || val > INT_MAX)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(val) << std::endl;

        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
        std::cout << "double: " << val << std::endl;
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