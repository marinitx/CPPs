#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat dios("Diosito", 2);
        std::cout << dios << std::endl;
        dios.incrementGrade(); //paso de 2 a 1
        std::cout << dios << std::endl;
        dios.incrementGrade(); //excepción, no puede subir más de 1
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat rata("Ratita", 151); //no puedo crear uno de menos de 150 (151)
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception on creation: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat trabajador("Trabajador honesto", 150);
        std::cout << trabajador << std::endl;
        trabajador.decrementGrade(); //excepción, no puede bajar de 150
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}