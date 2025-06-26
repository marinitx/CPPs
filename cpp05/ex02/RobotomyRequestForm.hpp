#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        RobotomyRequestForm();
        std::string _target;
    
    public:
        RobotomyRequestForm(const std::string &target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm&src);
        RobotomyRequestForm&operator=(const RobotomyRequestForm&src);

        std::string getTarget() const;
        void execute(Bureaucrat const &b) const;
};