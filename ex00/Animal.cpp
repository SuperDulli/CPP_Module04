#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal(void): m_type("generic animal") {
	std::cout << "Default Animal Constructor called" << std::endl;
}

Animal::Animal(Animal const& other): m_type(other.m_type) {
	std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal&	Animal::operator=(Animal const& other) {
	std::cout << "Animal copy assignmet operator called" << std::endl;
	this->m_type = other.m_type;
	return *this;
}

void	Animal::makeSound(void) const {
	std::cout << "* generic animal noises *" << std::endl;
}
