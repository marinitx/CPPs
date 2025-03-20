#include "PhoneBook.hpp"

void PhoneBook::welcome()
{
	std::cout << INFO << "----------------------------------------" << RESET << std::endl;
	std::cout << INFO << "Welcome to the Awesome 80s PhoneBook!" << RESET << std::endl;
	std::cout << INFO << "----------------------------------------" << RESET << std::endl;
	std::cout << INFO << "This rad piece of tech lets you:" << RESET << std::endl;
	std::cout << INFO << " - ADD: Save a new contact (max 8, oldest gets replaced!)" << RESET << std::endl;
	std::cout << INFO << " - SEARCH: Check out your contacts in style" << RESET << std::endl;
	std::cout << INFO << " - EXIT: Shut down this groovy machine" << RESET << std::endl;
	std::cout << INFO << "----------------------------------------" << RESET << std::endl;
	std::cout << INSTRUCTION << "Enter a command to start: " << RESET << std::endl;
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
			break;
		if (input == "ADD")
			phone.add();
		else if (input == "SEARCH")
			phone.search();
		else if (input != "EXIT")
			std::cout << ERROR << "Sorry, I don't understand this command. Try (ADD, SEARCH, EXIT) :D" << RESET << std::endl;
	}
	return (0);
}