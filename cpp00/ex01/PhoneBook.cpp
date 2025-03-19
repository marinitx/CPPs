#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
    : _totalContacts(0), _oldestContact(0) {}

PhoneBook::~PhoneBook() {
	std::cout << "Bye bye! <3" << std::endl;
	return;
}

void PhoneBook::_add_info(std::string field, Contact& info)
{
	std::string str;

	while (true)
	{
		std::cout << "Enter the contact's " + field + ":" << std::endl;
		std::getline(std::cin, str);

		if (str.length() == 0)
		{
			std::cout << "Please, enter the damn contact's " + field + "!" << std::endl;
			continue;
		}

		break;
	}
	info.set_value(field, str);
}

void PhoneBook::add()
{
	Contact contact;

	std::cout << "Seems like you want to ADD a new contact... Great! Just note you can only ADD 8 contacts or they will be replaced." << std::endl;
	_add_info("first name", contact);
	_add_info("last name", contact);
	_add_info("nickname", contact);
	_add_info("phone number", contact);
	_add_info("darkest secret", contact);
	
	if (_totalContacts < 8)
	{
		this->contacts[_totalContacts] = contact;
		_totalContacts++;
	}
	else
	{
		std::cout << "Oops! The list of contacts is full, first contact will be replaced" << std::endl;
		this->contacts[0] = contact;
	}
	std::cout << "done" << std::endl; //*******comprobación */
}

void PhoneBook::search()
{

}
