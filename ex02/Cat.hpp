#ifndef CAT_H
#define CAT_H

#include <string>
#include "AAnimal.hpp"

class Cat : public AAnimal {

	public:

		Cat(void);
		Cat(Cat const& other);
		~Cat(void);

		Cat&	operator=(Cat const& other);
		bool	operator==(Cat const& other);

		Brain&	getBrain(void) const;

		void	makeSound(void) const;
		void	thinkAbout(std::string const ideas[100]);

	private:

		Brain*	m_brain;

};

#endif
