#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;

    public:
        Form();
        ~Form();
        Form(const std::string &name, int signGrade, int execGrade);
        Form(const Form &src);
        Form &operator=(const Form &src);

        const std::string &getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(const Bureaucrat &b);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &form);