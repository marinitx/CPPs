#pragma once

#include <iostream>
#include <string>

class Bureaucrat {

    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);

        const std::string &getName() const;
        const std::string &getGrade() const;

        

};