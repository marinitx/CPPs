#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

#define ERROR "\033[91m" //red
#define INSTRUCTION "\033[95m" //purple
#define SUCCESS "\033[92m" //green
#define INFO "\033[96m" //cyan
#define RESET "\033[0m" //white
#define PINK "\033[95m"

#define GOODBYE_MESSAGE \
	"  , ; ,   .-'\"\"\"'-.   , ; ,\n" \
	"  \\\\|/  .'         '.  \\|//\n" \
	"   \\-;-/   ()   ()   \\-;-/\n" \
	"   // ;               ; \\\\\n" \
	"  //__; :.         .; ;__\\\\\n" \
	" `-----\'.'-.....-'.'/-----'\n" \
	"        '.'.-.-,_.'.'\n" \
	"byebye    '(  (..-'\n" \
	"            '-'\n"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void welcome();
		void add();
		void search();
		void getindex();

	private:
		Contact contacts[8];
		int		_totalContacts;
		int		_oldestContact;
		void	_add_info(std::string field, Contact& info);
		void	_print_table(int i, Contact contact);
		void	_print_index(int i, Contact contact);
		bool	_is_digit(const std::string& str);
};

#endif