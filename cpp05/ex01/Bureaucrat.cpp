#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    //comprobación cuando lo crea
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
    {
        _grade = src._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high!"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low!"; }

//esto para que el compilador me deje imprimirlo
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}