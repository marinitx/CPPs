#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("ShrubberyCreationForm", 145, 137), _target(src._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src)
    {
        this->AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const { return this->_target; }

void ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
    if (!this->getSignGrade())
        throw FormNotSigned();
    else if (this->getExecGrade() < b.getGrade())
        throw GradeTooLowException();
    else
    {
        std::ofstream outfile((this->_target + "_shrubbery").c_str());
        if (!outfile)
        {
            std::cerr << "Failed to create file: " << this->_target << "_shrubbery" << std::endl;
            return;
        }
    
        outfile <<
            "       _-_\n"
            "    /~~   ~~\\\n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "       // \\\\\n";
    
        outfile.close();
        std::cout << "Shrubbery file created: " << _target << "_shrubbery" << std::endl;
    }
}
