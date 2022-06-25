#include <iostream>
#include <string>
#include "Cat.hpp"

Cat::Cat(void): AAnimal("Cat"), m_brain(new Brain()) {
	std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(Cat const& other): AAnimal(other.m_type), m_brain(new Brain()) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = other;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called" << std::endl;
	delete m_brain;
}

Cat&	Cat::operator=(Cat const& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	AAnimal::operator=(other);

	this->m_type = other.m_type;
	this->m_brain->setIdeas(other.getBrain().getIdeas(), 100);
	return *this;
}

bool	Cat::operator==(Cat const& other) {
	std::cout << "Comparing two cats" << std::endl;

	bool typeAtSameAdress = (&this->m_type == &other.m_type);
	bool brainIsSame = (*this->m_brain == *other.m_brain);

	return (typeAtSameAdress && brainIsSame);
}

Brain&	Cat::getBrain(void) const { return *m_brain; }

void	Cat::makeSound(void) const {
	std::cout << "* meow miau *" << std::endl;
}

void	Cat::thinkAbout(std::string const ideas[100]) {
	this->m_brain->setIdeas(ideas, 100);
}
