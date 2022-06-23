#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): m_type("generic WrongAnimal") {
	std::cout << "Default WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): m_type(type) {
	std::cout << "WrongAnimal Constructor called with type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& other): m_type(other.m_type) {
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& other) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->m_type = other.m_type;
	return *this;
}

std::string	WrongAnimal::getType(void) const { return m_type; }

void	WrongAnimal::makeSound(void) const {
	std::cout << "* generic WrongAnimal noises *" << std::endl;
}
