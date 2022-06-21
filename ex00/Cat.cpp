#include <iostream>
#include <string>
#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {
	std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(Cat const& other): Animal(other.m_type) {
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called" << std::endl;
}

Cat&	Cat::operator=(Cat const& other) {
	std::cout << "Cat copy assignmet operator called" << std::endl;
	this->m_type = other.m_type;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "* meow miau *" << std::endl;
}
