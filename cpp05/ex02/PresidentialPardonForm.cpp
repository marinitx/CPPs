#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm("PresidentialPardonForm", 25, 5), _target(src._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this != &src)
    {
        this->AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

std::string PresidentialPardonForm::getTarget() const { return this->_target; }

void PresidentialPardonForm::execute(Bureaucrat const &b) const
{
    if (!this->getSignGrade())
        throw FormNotSigned();
    if (this->getExecGrade() < b.getGrade())
        throw GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
