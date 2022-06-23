#include <iostream>
#include <string>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void) {
	{
		std::cout << "--- Test begin ---" << std::endl;

		Animal const* meta = new Animal();
		Animal const* cat = new Cat();
		Animal const* dog = new Dog();

		std::cout << meta->getType() << std::endl;
		meta->makeSound();
		std::cout << cat->getType() << std::endl;
		cat->makeSound();
		std::cout << dog->getType() << std::endl;
		dog->makeSound();

		std::cout << std::string(80, '-') << std::endl;

		delete meta;
		delete cat;
		delete dog;

		std::cout << std::string(80, '-') << std::endl;

		WrongAnimal const* wrong = new WrongAnimal();
		WrongAnimal const* wrongCat = new WrongCat();

		std::cout << wrong->getType() << std::endl;
		wrong->makeSound();
		std::cout << wrongCat->getType() << std::endl;
		wrongCat->makeSound();

		std::cout << std::string(80, '-') << std::endl;

		delete wrong;
		delete wrongCat;

		std::cout << std::string(80, '-') << std::endl;

		WrongCat const* wrongButRightCat = new WrongCat();
		std::cout << wrongButRightCat->getType() << std::endl;
		wrongButRightCat->makeSound();

		std::cout << std::string(80, '-') << std::endl;

		delete wrongButRightCat;

		std::cout << std::string(80, '-') << std::endl;
	}
	std::cout << "--- Testing OCCF ---" << std::endl;
	{
		std::cout << "--- Animal ---" << std::endl;
		
		Animal	a;
		Animal	b(a);
		Animal	c("Original");

		std::cout << a.getType() << std::endl;
		std::cout << b.getType() << std::endl;
		std::cout << c.getType() << std::endl;
		a = c;
		std::cout << a.getType() << std::endl;

		std::cout << std::string(80, '-') << std::endl;
	}
	std::cout << std::string(80, '-') << std::endl;
	{
		std::cout << "--- Cat ---" << std::endl;
		
		Cat	a;
		Cat	b(a);
		Cat	c;

		std::cout << a.getType() << std::endl;
		std::cout << b.getType() << std::endl;
		std::cout << c.getType() << std::endl;
		a = c;
		std::cout << a.getType() << std::endl;

		std::cout << std::string(80, '-') << std::endl;
	}
	std::cout << std::string(80, '-') << std::endl;
	{
		std::cout << "--- Dog ---" << std::endl;
		
		Dog	a;
		Dog	b(a);
		Dog	c;

		std::cout << a.getType() << std::endl;
		std::cout << b.getType() << std::endl;
		std::cout << c.getType() << std::endl;
		a = c;
		std::cout << a.getType() << std::endl;

		std::cout << std::string(80, '-') << std::endl;
	}
	std::cout << std::string(80, '-') << std::endl;
	{
		std::cout << "--- WrongCat ---" << std::endl;
		
		WrongCat	a;
		WrongCat	b(a);
		WrongCat	c;

		std::cout << a.getType() << std::endl;
		std::cout << b.getType() << std::endl;
		std::cout << c.getType() << std::endl;
		a = c;
		std::cout << a.getType() << std::endl;

		std::cout << std::string(80, '-') << std::endl;
	}
	std::cout << std::string(80, '-') << std::endl;
	{
		std::cout << "--- copying an cat to an animal ---" << std::endl;
		Animal* meta;
		Cat* cat = new Cat();
		Animal* meta2 = new Animal(*cat);

		meta = cat;
		std::cout << "cat that was assigned to an animal" << std::endl;
		// std::cout << meta->getType() << std::endl;
		meta->makeSound();

		std::cout << "cat that was passed to the Animal copy constructor" << std::endl;
		// std::cout << meta2->getType() << std::endl;
		meta2->makeSound();

		delete meta;
		delete meta2;
		// delete cat; // cat gets destroyed when meta gets destroyed, because ~Animal is virtual

		std::cout << std::string(80, '-') << std::endl;
	}
	{
		std::cout << "--- copying a wrong cat to a wrong animal ---" << std::endl;
		WrongAnimal* meta;
		WrongCat* cat = new WrongCat();
		WrongAnimal* meta2 = new WrongAnimal(*cat);

		meta = cat;
		std::cout << "cat that was assigned to an animal" << std::endl;
		// std::cout << meta->getType() << std::endl;
		meta->makeSound();

		std::cout << "cat that was passed to the Animal copy constructor" << std::endl;
		// std::cout << meta2->getType() << std::endl;
		meta2->makeSound();

		delete meta; // could lead to leaks, beause ~Cat() is not called
		delete meta2;
		// delete cat; // cat gets destroyed when meta gets deleted

		std::cout << std::string(80, '-') << std::endl;
	}

	return 0;
}
