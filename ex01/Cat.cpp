#include <iostream>
#include <string>
#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"), m_brain(new Brain()) {
	std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(Cat const& other): Animal(other.m_type) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = other;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called" << std::endl;
}

Cat&	Cat::operator=(Cat const& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	Animal::operator=(other);

	this->m_type = other.m_type;
	this->m_brain = other.getBrain();
	return *this;
}

Brain*	Cat::getBrain(void) const { return m_brain; }

void	Cat::setBrain(Brain* brain) {
	this->m_brain = brain;
}

void	Cat::makeSound(void) const {
	std::cout << "* meow miau *" << std::endl;
}
