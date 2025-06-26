#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("RobotomyRequestForm", 72, 45), _target(src._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src)
    {
        this->AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget() const { return this->_target; }

void RobotomyRequestForm::execute(Bureaucrat const &b) const
{
    if (!this->getSignGrade())
        throw FormNotSigned();
    if (this->getExecGrade() < b.getGrade())
        throw GradeTooLowException();
    if (rand() % 2)
    {
        std::cout << "***DRILLING NOISES***" << std::endl;
        std::cout << this->_target << " has been successfully robotomized." << std::endl;
    }
    else
        std::cout << this->_target << " Robotomy failed." << std::endl;
}
