#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form() : _name(""), _isSigned(false), _signGrade(75), _execGrade(75) {}

Form::Form(const Form &src)
    : _name(src._name), _isSigned(src._isSigned),
      _signGrade(src._signGrade), _execGrade(src._execGrade) {}

Form &Form::operator=(const Form &src)
{
    if (this != &src)
        _isSigned = src._isSigned;
    return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecGrade() const { return _execGrade; }

const char *Form::GradeTooHighException::what() const throw() { return "Form: Grade too high!"; }

const char *Form::GradeTooLowException::what() const throw() { return "Form: Grade too low!"; }

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
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
