#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {

	public:

		Animal(void);
		Animal(Animal const& other);
		~Animal(void);

		Animal&	operator=(Animal const& other);

		virtual void	makeSound(void) const;

	protected:

		std::string	m_type;

};

#endif
