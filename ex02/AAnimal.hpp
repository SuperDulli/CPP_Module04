#ifndef AANIMAL_H
#define AANIMAL_H

#include <string>
#include "Brain.hpp"

class AAnimal {

	public:

		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal const& other);
		virtual ~AAnimal(void);

		AAnimal&	operator=(AAnimal const& other);

		std::string	getType(void) const;

		virtual void	makeSound(void) const = 0;

	protected:

		std::string	m_type;

};

#endif
