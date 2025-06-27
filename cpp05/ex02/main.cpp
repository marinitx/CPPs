#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	std::string target = "objetivo";

	Bureaucrat jefe("Jefe", 1);
	Bureaucrat humilde("Humilde", 70);
	Bureaucrat mediocre("Mediocre", 150);

	std::cout << "\n========= SHRUBBERY 145, 137=========" << std::endl;
	{
		ShrubberyCreationForm form(target);

		std::cout << "\nCaso 1: Mediocre no puede firmar ni ejecutar" << std::endl;
		mediocre.signForm(form);
		try { form.execute(mediocre); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

		std::cout << "\nCaso 2: Humilde puede ejecutar pero form no está firmado aún" << std::endl;
		try { form.execute(humilde); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

		std::cout << "\nCaso 3: Humilde firma y puede ejecutar" << std::endl;
		form.beSigned(humilde);
		try { form.execute(humilde); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
	}

	std::cout << "\n========= ROBOTOMY 72, 45=========" << std::endl;
	{
		RobotomyRequestForm form(target);

		std::cout << "\nCaso 1: Mediocre no puede firmar ni ejecutar" << std::endl;
		mediocre.signForm(form);
		try { form.execute(mediocre); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

		std::cout << "\nCaso 2: Humilde puede ejecutar pero no está firmado aún" << std::endl;
		try { form.execute(humilde); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

		std::cout << "\nCaso 3: Humilde firma pero no puede ejecutar" << std::endl;
		form.beSigned(humilde);
		if (form.isSigned())
			std::cout << "✅ El formulario está firmado correctamente." << std::endl;
		else
			std::cout << "❌ El formulario NO está firmado." << std::endl;

		try { form.execute(humilde); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

		std::cout << "\nCaso 4: Jefe firma y ejecuta" << std::endl;
		form.beSigned(jefe);
		try { form.execute(jefe); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
	}

	std::cout << "\n========= PRESIDENTIAL 25, 5=========" << std::endl;
	{
		PresidentialPardonForm form(target);

		std::cout << "\nCaso 1: Mediocre no puede firmar ni ejecutar" << std::endl;
		mediocre.signForm(form);
		try { form.execute(mediocre); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

		std::cout << "\nCaso 2: Humilde no puede firmar asi que jefe firma y humilde intenta ejecutar y no puede" << std::endl;
		form.beSigned(jefe);
		try { form.execute(humilde); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

		std::cout << "\nCaso 4: Jefe firma y ejecuta" << std::endl;
		form.beSigned(jefe);
		try { form.execute(jefe); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
	}

	return 0;
}
