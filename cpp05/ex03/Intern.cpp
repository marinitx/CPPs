#include "Intern.hpp"

Intern::Intern(void){}

Intern::Intern(const Intern &i)
{
	(void) i;
}

Intern::~Intern(void){}

Intern &Intern::operator=(const Intern &i)
{
	(void) i;
	return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	std::string forms[3] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			switch (i)
			{
			case 0:
				return new ShrubberyCreationForm(target);
				break;
			case 1:
				return new RobotomyRequestForm(target);
				break;
			case 2:
				return new PresidentialPardonForm(target);
				break;
			}
		}
	}
	std::cerr << "Error: Form is not valid." << std::endl;
	return NULL;
}