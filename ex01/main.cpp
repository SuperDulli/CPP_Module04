#include <iostream>
#include <string>
#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void) {

	Animal const* cat = new Cat();

	std::cout << cat->getBrain() << std::endl;

	delete cat;

	return 0;
}
