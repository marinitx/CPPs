#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cctype>

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        void welcome();
        void add();
        void search();

    private:
        Contact contacts[8];
        int     _totalContacts;
        int     _oldestContact;
        void    _add_info(std::string field, Contact& info);
};

#endif