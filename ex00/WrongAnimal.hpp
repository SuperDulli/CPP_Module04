#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <string>

class WrongAnimal {

	public:

		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const& other);
		~WrongAnimal(void);

		WrongAnimal&	operator=(WrongAnimal const& other);

		std::string	getType(void) const;

		void	makeSound(void) const;

	protected:

		std::string	m_type;

};

#endif
