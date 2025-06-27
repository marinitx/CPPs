#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
        AForm();

    public:
        virtual ~AForm();
        AForm(const std::string &name, int signGrade, int execGrade);
        AForm(const AForm &src);
        AForm &operator=(const AForm &src);

        const std::string &getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(const Bureaucrat &b);

        virtual void execute(Bureaucrat const &executor) const = 0;

        class FormNotSigned : public std::exception
		{
			public:
				const char *what() const throw();
		};
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

std::ostream &operator<<(std::ostream &out, const AForm &Aform);