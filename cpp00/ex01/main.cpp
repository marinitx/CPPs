#include "PhoneBook.hpp"

void PhoneBook::welcome()
{
	std::cout << "----------------------------------------" << std::endl;
    std::cout << "Welcome to the Awesome 80s PhoneBook!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "This rad piece of tech lets you:" << std::endl;
    std::cout << " - ADD: Save a new contact (max 8, oldest gets replaced!)" << std::endl;
    std::cout << " - SEARCH: Check out your contacts in style" << std::endl;
    std::cout << " - EXIT: Shut down this groovy machine" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Enter a command to start: ";
}

int main()
{
	PhoneBook phone;
	std::string input;

	phone.welcome();
	while (1)
	{
		std::getline(std::cin, input);
		if (input == "EXIT")
			break ;
		if (input == "ADD")
			phone.add();
		else if (input == "SEARCH")
			phone.search();
		else if (input != "EXIT")
			std::cout << "Sorry, I don't understand this command. Try (ADD, SEARCH, EXIT) :D" << std::endl;
	}
	return (0);
}
