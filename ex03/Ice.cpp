#include <iostream>
#include <string>
#include "Color.hpp"
#include "Ice.hpp"

Ice::Ice(void) {
	this->m_type = "ice";
}

Ice::Ice(Ice const& other): AMateria(other) {
	// this->m_type = "ice";
}

Ice::~Ice(void) {}

Ice& Ice::operator=(Ice const& other) {
	(void) other;
	return *this;
}

AMateria* Ice::clone(void) const {
	return new Ice();
}

void	Ice::use(ICharacter& target) {
	std::cout
	<< Color::Modifier(Color::FG_BLUE)
	<< "* shoots an ice bolt at " << target.getName() << " *"
	<< Color::Modifier()
	<< std::endl;
}
