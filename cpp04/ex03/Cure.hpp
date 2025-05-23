#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure& operator=(const Cure& c);
		Cure(const Cure& c);
		void use(ICharacter& target);
		AMateria* clone() const;
};

#endif
