#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {

    private:
        const std::string _name;
        int _grade;
        Bureaucrat();

    public:
        Bureaucrat(const std::string &name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);

        const std::string &getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signForm(Form &form);

        //excepciones para no tener que usar ifs elses. what devuelve un mensaje de texto
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual char const *what() const throw();
        };
};

// esto es para que el compilador me deje imprimir el objeto b como texto
// de modo que devuelve una referencia a un flujo de salida
// es decir, el compilador si puede imprimir ints chars o strings pero no un objeto custom como Bureaucrat
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);