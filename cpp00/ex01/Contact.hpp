#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>
#include <string>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        std::string get_value(std::string field);
        void set_value(std::string field, std::string str);

    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
};

#endif