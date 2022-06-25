#ifndef DOG_H
#define DOG_H

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	public:

		Dog(void);
		Dog(Dog const& other);
		~Dog(void);

		Dog&	operator=(Dog const& other);
		bool	operator==(Dog const& other);

		Brain&	getBrain(void) const;

		void	makeSound(void) const;
		void	thinkAbout(std::string const ideas[100]);

	private:

		Brain*	m_brain;

};

#endif
