#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:

    public:
        Intern();
        ~Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);

        AForm *makeForm(const std::string &name, const std::string &target) const;
};