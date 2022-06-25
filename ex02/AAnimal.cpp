#include <iostream>
#include <string>
#include "AAnimal.hpp"

AAnimal::AAnimal(void): m_type("generic animal") {
	std::cout << "Default AAnimal Constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type): m_type(type) {
	std::cout << "AAnimal Constructor called with type: " << type << std::endl;
}

AAnimal::AAnimal(AAnimal const& other): m_type(other.m_type) {
	std::cout << "AAnimal Copy Constructor called" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(AAnimal const& other) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	this->m_type = other.m_type;
	return *this;
}

std::string	AAnimal::getType(void) const { return m_type; }

void	AAnimal::makeSound(void) const {
	std::cout << "* generic animal noises *" << std::endl;
}
