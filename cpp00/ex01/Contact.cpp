#include "Contact.hpp"

Contact::Contact() {};

Contact::~Contact() {};

void Contact::get_value()
{
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