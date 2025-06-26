#pragma once

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        ShrubberyCreationForm();
        std::string _target;
    
    public:
        ShrubberyCreationForm(const std::string &target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm&src);
        ShrubberyCreationForm&operator=(const ShrubberyCreationForm&src);

        std::string getTarget() const;
        void execute(Bureaucrat const &b) const;
};