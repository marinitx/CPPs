#include "Brain.hpp"

Brain::Brain()
{
	for (size_t i = 0; i < 100; i++)
	{
		_ideas[i] = ("idea " + std::to_string(i));
	}
	std::cout << "Default Brain constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		for (size_t i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return *this;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

std::string Brain::getIdea(size_t i) const
{
	if (i >= 100)
	{
		std::cerr << "Error: only valid index from 0 to 99\n";
		return "";
	}
	return _ideas[i];
}

void Brain::setIdea(size_t i, const std::string &idea)
{
	if (i >= 100)
	{
		std::cerr << "Error: only valid index from 0 to 99\n";
		return;
	}
	_ideas[i] = idea;
}