#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
    : _totalContacts(0), _oldestContact(0) {}

PhoneBook::~PhoneBook() {
	std::cout << "Bye bye! <3" << std::endl;
	return;
}

void PhoneBook::_add_info(std::string field, Contact& info)
{
	std::string answer;

	while (true)
	{
		std::cout << "Enter the contact's " + field + ":" << std::endl;
		std::getline(std::cin, answer);

		if (answer.length() == 0)
		{
			std::cout << "Please, enter the damn contact's " + field + "!" << std::endl;
			continue;
		}

		break;
	}
	info.set_value(field, answer);
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
	
	if (this->_totalContacts < 8)
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

void PhoneBook::_print_table(int i, Contact contact)
{
	//falta truncar para que no se pase de 10 caracteres :D
	std::cout << std::setw(10) << i << "|";
	std::cout << std::setw(10) << contact.get_value("first name") << "|";
	std::cout << std::setw(10) << contact.get_value("last name") << "|";
	std::cout << std::setw(10) << contact.get_value("nickname") << "|" << std::endl;
}

void PhoneBook::search()
{
	int i;

	i = 1;
	if (this->_totalContacts == 0)
	{
		std::cout << "You have no contacts added yet. Would you like to ADD a contact?" << std::endl;
		return;
	}
	while (i < this->_totalContacts)
	{
		_print_table(i, this->contacts[i]);
		i++;
	}
	// preguntar al usuario por el index y desplegar la info del contacto
	// comprobar que el index está entre los valores permitidos
}
