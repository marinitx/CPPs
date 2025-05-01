#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &copy);
		virtual ~Brain();
		Brain &operator=(const Brain &copy);
		
		std::string getIdea(size_t i)const;
		void setIdea(size_t i, const std::string &idea);
};

#endif