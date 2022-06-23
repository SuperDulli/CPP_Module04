#ifndef CAT_H
#define CAT_H

#include <string>
#include "Animal.hpp"

class Cat : private Animal {

	public:

		Cat(void);
		Cat(Cat const& other);
		~Cat(void);

		Cat&	operator=(Cat const& other);

		Brain*	getBrain(void) const;
		void	setBrain(Brain* brain);

		void	makeSound(void) const;

	private:

		Brain*	m_brain;

};

#endif
