#include <iostream>
#include <string>
#include "Dog.hpp"

Dog::Dog(void): AAnimal("Dog"), m_brain(new Brain()) {
	std::cout << "Default Dog Constructor called" << std::endl;
}

Dog::Dog(Dog const& other): AAnimal(other.m_type), m_brain(new Brain()) {
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = other;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called" << std::endl;
	delete m_brain;
}

Dog&	Dog::operator=(Dog const& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	AAnimal::operator=(other);

	this->m_type = other.m_type;
	this->thinkAbout(other.getBrain().getIdeas());
	return *this;
}

bool	Dog::operator==(Dog const& other) {
	std::cout << "Comparing two dogs" << std::endl;

	bool typeAtSameAdress = (&this->m_type == &other.m_type);
	bool brainIsSame = (*this->m_brain == *other.m_brain);

	return (typeAtSameAdress && brainIsSame);
}

Brain&	Dog::getBrain(void) const {
	return *m_brain;
}

void	Dog::makeSound(void) const {
	std::cout << "* woof wuff *" << std::endl;
}

void	Dog::thinkAbout(std::string const ideas[100]) {
	this->m_brain->setIdeas(ideas, 100);
}
