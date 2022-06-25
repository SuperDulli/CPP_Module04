#include <iostream>
#include <string>
#include "Color.hpp"
#include "Cure.hpp"

Cure::Cure(void) {
	this->m_type = "cure";
}

Cure::Cure(Cure const& other): AMateria(other) {
	// this->m_type = "cure";
}

Cure::~Cure(void) {}

Cure& Cure::operator=(Cure const& other) {
	(void) other;
	return *this;
}

AMateria* Cure::clone(void) const {
	return new Cure();
}

void	Cure::use(ICharacter& target) {
	std::cout
	<< Color::Modifier(Color::FG_GREEN)
	<< "* heals " << target.getName() << "'s wounds *"
	<< Color::Modifier()
	<< std::endl;
}
