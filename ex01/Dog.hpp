#ifndef DOG_H
#define DOG_H

#include <string>
#include "Animal.hpp"

class Dog : public Animal {

	public:

		Dog(void);
		Dog(Dog const& other);
		~Dog(void);

		Dog&	operator=(Dog const& other);

		void	makeSound(void) const;

};

#endif
