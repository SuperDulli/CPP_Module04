#include <iostream>
#include <string>
#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void) {
	std::string	catIdea = "I like cardboard boxes.";
	std::cout << "--- Test begin ---" << std::endl;
	{
		std::cout << "Test from subject:" << std::endl;
		
		Animal const* cat = new Cat();
		
		delete cat;

		// std::cout << catIdea << std::endl;
		std::cout << std::string(80, '-') << std::endl;
	}
	{
		std::cout << "Test Brain" << std::endl;
		std::string	ideas[100] = { "Hi", "this", "is", "Brain" };

		Brain	a;
		Brain	b(a);

		std::cout << "Filling a with ideas" << std::endl;
		a.setIdeas(ideas, 100);
		std::cout << "Brain a: " << std::endl << a << std::endl;
		std::cout << "Brain b: " << std::endl << b << std::endl;

		std::cout << "create a copy of a and assign it to b" << std::endl;
		b = a;
		std::cout << "Brain a: " << std::endl << a << std::endl;
		std::cout << "Brain b: " << std::endl << b << std::endl;

		std::cout << "changing an idea in b" << std::endl;
		b.setIdea(3, "Dave");
		std::cout << "Brain a: " << std::endl << a << std::endl;
		std::cout << "Brain b: " << std::endl << b << std::endl;

		std::cout << "testing capacity" << std::endl;
		for (size_t i = 0; i < 100; i++)
		{
			std::string const idea = std::string(i + 1, '*');
			a.setIdea(i, idea);
		}
		a.setIdea(100, "Outside");
		a.setIdea(-42, "Negative");
		std::cout << a << std::endl;
		
		std::cout << std::string(80, '-') << std::endl;
	}
	std::cout << std::string(80, '-') << std::endl;
	{
		std::cout << "Testing Animals with brains" << std::endl;

		// Brain	stackBrain;
		// Brain*	heapBrain = new Brain();

		Animal*	animal;
		Cat*	cat = new Cat();
		Dog*	dog = new Dog();

		std::string	ideas[100] = {"Set", "the", "world", "on", "fire"};
		std::string	dogIdeas[100] = {"Bring", "bark", "back", "wuff", "the", "whoooo", "ball"};

		// stackBrain.setIdeas(ideas, 100);

		// cat->setBrain(&stackBrain);
		cat->thinkAbout(ideas);
		// stackBrain.setIdea(2, std::string("tree"));
		std::cout << "cat thinks about:" << std::endl;
		std::cout << cat->getBrain() << std::endl;

		dog->thinkAbout(dogIdeas);
		std::cout << "dog thinks about:" << std::endl;
		std::cout << dog->getBrain() << std::endl;
		
		animal = cat;

		std::cout << std::string(80, '-') << std::endl;

		std::cout << "--- testing copying animals (w/ brains) ---" << std::endl;
		Cat	copyCat1 = *cat;
		Cat	copyCat2(*cat);
		Dog	copyDog1 = *dog;
		Dog	copyDog2(*dog);

		// Dog* copyDog3 = cat; // cats can't be copied to dogs
		// copyCat1 = *cat;
		if (*cat == copyCat1) {
			std::cout << "same cats" << std::endl;
		}
		if (*cat == copyCat2) {
			std::cout << "same cats" << std::endl;
		}
		if (*dog == copyDog1) {
			std::cout << "same dogs" << std::endl;
		}
		if (*dog == copyDog2) {
			std::cout << "same dogs" << std::endl;
		}
		if (dog->getBrain() == cat->getBrain()) {
			std::cout << "the dog has the same brain as the cat" << std::endl;
		}
		// *dog == *cat // no match operator overload
		std::cout << std::string(80, '-') << std::endl;

		delete animal;
		delete dog;

		std::cout << std::string(80, '-') << std::endl;
	}
	{
		std::cout << "--- Creating a zoo full of cats and dogs ---" << std::endl;

		std::cout << "build the zoo" << std::endl;
		int const	zooSize = 6;
		// Animal*	zoo = new Animal[zooSize];
		Animal*		zoo[zooSize];

		std::cout << "populate the zoo" << std::endl; 
		for (size_t i = 0; i < zooSize / 2; i++)
		{
			zoo[i] = new Cat();
		}
		for (size_t i = zooSize / 2; i < zooSize; i++)
		{
			zoo[i] = new Dog();
		}
		std::cout << std::endl;
		
		std::cout << "destroying the zoo" << std::endl;
		for (size_t i = 0; i < zooSize; i++)
		{
			std::cout << "deleting animal #" << i << std::endl;
			delete zoo[i];
		}	
	}

	// std::cout << cat->getBrain() << std::endl;


	return 0;
}


// void	testDeepCopy(Animal const& a, Animal const& b) {

// }
