#ifndef CAT_H
#define CAT_H

#include <string>
#include "Animal.hpp"

class Cat : public Animal {

	public:

		Cat(void);
		Cat(Cat const& other);
		~Cat(void);

		Cat&	operator=(Cat const& other);

		void	makeSound(void) const;

};

#endif
