#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>

class Contact
{
    public:
        Contact();
        ~Contact();
        std::string get_value(std::string field) const;
        void set_value(std::string field, std::string value);

    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
};

#endif