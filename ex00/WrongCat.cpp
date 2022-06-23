#include <iostream>
#include <string>
#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat") {
	std::cout << "Default WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const& other): WrongAnimal(other.m_type) {
	std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const& other) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	this->m_type = other.m_type;
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << "* Eeehhoou! Iiaa Iiaa! *" << std::endl;
}
