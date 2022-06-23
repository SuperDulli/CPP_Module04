#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {

	public:

		Animal(void);
		Animal(std::string type);
		Animal(Animal const& other);
		virtual ~Animal(void);

		Animal&	operator=(Animal const& other);

		std::string	getType(void) const;

		virtual void	makeSound(void) const;

	protected:

		std::string	m_type;

};

#endif
