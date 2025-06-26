#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm();
        std::string _target;
    
    public:
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

        std::string getTarget() const;
        void execute(Bureaucrat const &b) const;
};