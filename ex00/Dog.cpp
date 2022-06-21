#include <iostream>
#include <string>
#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {
	std::cout << "Default Dog Constructor called" << std::endl;
}

Dog::Dog(Dog const& other): Animal(other.m_type) {
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called" << std::endl;
}

Dog&	Dog::operator=(Dog const& other) {
	std::cout << "Dog copy assignmet operator called" << std::endl;
	this->m_type = other.m_type;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "* woof wuff *" << std::endl;
}
