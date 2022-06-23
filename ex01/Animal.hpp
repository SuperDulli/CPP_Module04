#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "Brain.hpp"

class Animal {

	public:

		Animal(void);
		Animal(std::string type);
		Animal(Animal const& other);
		virtual ~Animal(void);

		Animal&	operator=(Animal const& other);

		std::string	getType(void) const;

		Brain*	getBrain(void) const;
		void	setBrain(Brain* brain);

		virtual void	makeSound(void) const;

	protected:

		std::string	m_type;
		Brain*	m_brain;

};

#endif
