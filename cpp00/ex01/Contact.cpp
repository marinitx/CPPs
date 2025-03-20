#include "Contact.hpp"

Contact::Contact() {};

Contact::~Contact() {};

std::string Contact::get_value(std::string field)
{
    if (field == "first name")
        return this->_first_name;
    else if (field == "last name")
        return this->_last_name;
    else if (field == "nickname")
        return this->_nickname;
    else if (field == "phone number")
        return this->_phone_number;
    else if (field == "darkest secret")
        return this->_darkest_secret;
    else
        return ("");
    //preguntar al usuario por cada una de las variables
}

void Contact::set_value(std::string field, std::string str) 
{
    if (field == "first name")
        this->_first_name = str;
    else if (field == "last name")
        this->_last_name = str;
    else if (field == "nickname")
        this->_nickname = str;
    else if (field == "phone number")
        this->_phone_number = str;
    else if (field == "darkest secret")
        this->_darkest_secret = str;
}