#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::string target = "el mundo";

	Bureaucrat jefe("Jefe", 1);
	Bureaucrat trabajadorHumilde("Trabajador humilde", 70);
	Bureaucrat trabajadorMediocre("Trabajador mediocre", 140);

	std::cout << "\n===== SHRUBBERY CREATION =====" << std::endl;
	{
		ShrubberyCreationForm sf("jardín");

		trabajadorMediocre.executeForm(sf);
		trabajadorMediocre.signForm(sf);
		trabajadorMediocre.executeForm(sf);

		jefe.signForm(sf);
		jefe.executeForm(sf);

		std::cout << sf << std::endl;
	}

	std::cout << "\n===== ROBOTOMY REQUEST =====" << std::endl;
	{
		RobotomyRequestForm rrf("cliente");

		trabajadorHumilde.signForm(rrf);
		jefe.signForm(rrf);

		trabajadorHumilde.executeForm(rrf);
		jefe.executeForm(rrf);

		std::cout << rrf << std::endl;
	}

	std::cout << "\n===== PRESIDENTIAL PARDON =====" << std::endl;
	{
		PresidentialPardonForm ppf("enemigo");

		trabajadorHumilde.signForm(ppf);

		try {
			ppf.execute(jefe);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		trabajadorHumilde.executeForm(ppf);
		jefe.executeForm(ppf);

		std::cout << ppf << std::endl;
	}

	return 0;
}

