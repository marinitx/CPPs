#include "PhoneBook.hpp"
#include "Contact.hpp"

bool PhoneBook::_is_digit(const std::string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) {
            return false;
        }
    }
    return true;
}

void PhoneBook::_print_table(int i, Contact contact) 
{
    std::ostringstream oss;
    oss << i;
    std::string index = oss.str();
    std::string fname = contact.get_value("first name");
    if (fname.length() > 10) fname = fname.substr(0, 9) + ".";
    std::string lname = contact.get_value("last name");
    if (lname.length() > 10) lname = lname.substr(0, 9) + ".";
    std::string nname = contact.get_value("nickname");
    if (nname.length() > 10) nname = nname.substr(0, 9) + ".";

    std::cout << INFO << std::setw(10) << index << "|" 
              << std::setw(10) << fname << "|" 
              << std::setw(10) << lname << "|" 
              << std::setw(10) << nname << "|" << RESET << std::endl;
}

void PhoneBook::_print_index(int i, Contact contact)
{
	std::cout << std::endl;
	std::cout << INFO << "This is contact number " << i << " info: " << std::endl;
	std::cout << "First name: " << contact.get_value("first name") << std::endl;
	std::cout << "Last name: " << contact.get_value("last name") << std::endl;
	std::cout << "Nickname: " << contact.get_value("nickname") << std::endl;
	std::cout << "Phone number: " << contact.get_value("phone number") << std::endl;
	std::cout << "Darkest secret: " << contact.get_value("darkest secret") << std::endl;
	std::cout << std::endl << "Try other command: ADD, SEARCH or EXIT!" << RESET << std::endl;
}

void PhoneBook::getindex()
{
	int id;
	std::string answer;

	std::cout << std::endl;
	std::cout << INSTRUCTION << "Which contact do you want to see? Enter its id!" 
		<< RESET << std::endl;
	while (true)
	{
		std::getline(std::cin, answer);
		id = atoi(answer.c_str());
		if (answer.length() == 0)
		{
			std::cout << ERROR << "Come on write something... An id can't be empty!" 
				<< RESET << std::endl;
			continue;
		}
        if (!_is_digit(answer))
        {
            std::cout << ERROR << "Trying to trick me? Haha, only digits allowed!" << RESET << std::endl;
            continue;
        }
		if (id < 0 || id > this->_totalContacts - 1)
		{
			std::cout << ERROR << "That's not even a possible id... Try again or it will take forever" 
			<< RESET << std::endl;
			continue; 
		}
		break;
	}
	_print_index(id, this->contacts[id]);
}


