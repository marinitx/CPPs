#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat trabajador("Trabajador honesto", 15);
        Form permiso("Permiso para ir al baño", 10, 10);

        std::cout << trabajador << std::endl;
        std::cout << permiso << std::endl;

        trabajador.signForm(permiso);  //falla, es demasiado bajo el rango 15, necesita 10
        std::cout << permiso << std::endl;

        Bureaucrat jefe("Jefe", 1);
        jefe.signForm(permiso);  //firma el permiso
        std::cout << permiso << std::endl;

        if (permiso.isSigned())
            std::cout << "Trabajador fue al baño exitosamente." << std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

