#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &src)
    : _name(src._name), _isSigned(src._isSigned),
      _signGrade(src._signGrade), _execGrade(src._execGrade) {}

AForm &AForm::operator=(const AForm &src)
{
    if (this != &src)
        _isSigned = src._isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }

const char *AForm::GradeTooHighException::what() const throw() { return "Form: Grade too high!"; }

const char *AForm::GradeTooLowException::what() const throw() { return "Form: Grade too low!"; }

const char* AForm::FormNotSigned::what() const throw() { return "Form is not signed."; }

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form \"" << form.getName() << "\", signed: ";
    if (form.isSigned())
        out << "yes";
    else
        out << "no";
    out << ", grade to sign: " << form.getSignGrade()
        << ", grade to execute: " << form.getExecGrade();
    return out;
}

