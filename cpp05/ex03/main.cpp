#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	Intern someRandomIntern;
	Bureaucrat boss("Jefe", 1);

	std::cout << "\n--- Caso válido: Shrubbery ---" << std::endl;
	AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "garden");
	if (form1)
	{
		boss.signForm(*form1);
		boss.executeForm(*form1);
		delete form1;
	}

	std::cout << "\n--- Caso válido: Robotomy ---" << std::endl;
	AForm *form2 = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form2)
	{
		boss.signForm(*form2);
		boss.executeForm(*form2);
		delete form2;
	}

	std::cout << "\n--- Caso válido: Presidential ---" << std::endl;
	AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Pepito");
	if (form3)
	{
		boss.signForm(*form3);
		boss.executeForm(*form3);
		delete form3;
	}

	std::cout << "\n--- Caso inválido: Form inexistente ---" << std::endl;
	AForm *form4 = someRandomIntern.makeForm("invalid form", "Nobody");
	if (form4)
		delete form4;

	return 0;
}

