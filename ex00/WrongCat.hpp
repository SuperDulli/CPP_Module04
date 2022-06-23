#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:

		WrongCat(void);
		WrongCat(WrongCat const& other);
		~WrongCat(void);

		WrongCat&	operator=(WrongCat const& other);

		void	makeSound(void) const;

};

#endif
