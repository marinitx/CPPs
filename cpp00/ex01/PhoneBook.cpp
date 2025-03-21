#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
    : _totalContacts(0), _oldestContact(0) {}

PhoneBook::~PhoneBook() 
{
		std::cout << PINK << GOODBYE_MESSAGE << RESET;
}

void PhoneBook::_add_info(std::string field, Contact& info)
{
	std::string answer;

	while (true)
	{
		std::cout << INSTRUCTION << "Enter the contact's " + field + ":" << RESET << std::endl;
		std::getline(std::cin, answer);

		if (answer.length() == 0)
		{
			std::cout << ERROR << "Please, enter the damn contact's " + field + "!" << RESET << std::endl;
			continue;
		}

		break;
	}
	info.set_value(field, answer);
}

void PhoneBook::add()
{
	Contact contact;

	std::cout << std::endl;
	std::cout << INFO << "Seems like you want to ADD a new contact... Great! Just note you can only ADD 8 contacts or they will be replaced." 
		<< RESET << std::endl;
	_add_info("first name", contact);
	_add_info("last name", contact);
	_add_info("nickname", contact);
	_add_info("phone number", contact);
	_add_info("darkest secret", contact);
	
	if (this->_totalContacts < 8)
	{
		this->contacts[_totalContacts] = contact;
		_totalContacts++;
		std::cout << SUCCESS << "Contact added successfully!" << RESET << std::endl;
	}
	else
	{
		std::cout << ERROR << "Oops! The list of contacts is full, oldest contact will be replaced" << RESET << std::endl;
		this->contacts[_oldestContact] = contact;
		_oldestContact = (_oldestContact + 1) % 8;
	}
	std::cout << std::endl;
}

void PhoneBook::search()
{
	int i;

	i = 0;
	if (this->_totalContacts == 0)
	{
		std::cout << INFO << "You have no contacts added yet. Would you like to ADD a contact?"
			<< RESET << std::endl;
		return;
	}
	std::cout << INFO << "Here are your contacts:" << std::endl 
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First name" << "|"
		<< std::setw(10) << "Last name" << "|"
		<< std::setw(10) << "Nickname" << "|" << std::endl;
	while (i < this->_totalContacts)
	{
		_print_table(i, this->contacts[i]);
		i++;
	}
	getindex();
}
