#include "ScalarConverter.hpp"

//std::strtod() / std::strtof() / std::strtol() -> Parse string to numeric types.

// Converts string into char (32 - 126)
const char charConvert(const std::string &c)
{
    //if no es char -> cout Non displayable
    //if nan -> cout impossible
    //itoa int to char c_str()
    //std::cout << "char: " << c << std::endl; // Tengo que volver a convertir a string para imprimir?
}

//Converts string into int
int intConvert(const std::string &i)
{
    //if nan -> cout impossible
    //strtod()
    //std::cout << "int: " << i << std::endl;

}

//Converts string into float
const float floatConvert(const std::string &f)
{
    //if nan -> cout impossible
    //strtof()
    //std::cout << "float: " << f << std::endl;

}

//Converts string into double
const double doubleConvert(const std::string &d)
{
    //if nan -> cout impossible
    //strtol()
    //std::cout << "double: " << d << std::endl;

}

// Modify it's type, convert.
// If overflow -> impossible
// Handle numeric limits and special values
static void convert(const std::string& literal)
{
    //charConvert
    //intConvert
    //floatConvert
    //doubleConvert
    
}

// Detect literal's type
static void detectType(const std::string &literal)
{
    //if isdigit() entonces char
    //else if (librería is float?) entonces float
    //if isanumber? entonces int
    // if (double) entonces doble

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