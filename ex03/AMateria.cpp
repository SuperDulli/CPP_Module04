#include <iostream>
#include <string>
#include "Color.hpp"
#include "AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(AMateria const& other): m_type(other.m_type) {}

AMateria::~AMateria(void) {}

AMateria& AMateria::operator=(AMateria const& other) {
	(void) other;
	return *this;
}

std::string const& AMateria::getType(void) const {
	return m_type;
}

AMateria* AMateria::clone(void) const {
	if (m_type.empty()) {
		std::cerr
		<< Color::Modifier(Color::FG_RED)
		<< "Can't clone <unkown Materia type>"
		<< Color::Modifier()
		<< std::endl;
		// return NULL;
	}
	return NULL;
}

void AMateria::use(ICharacter& target) {
	if (m_type.empty()) {
		std::cerr
		<< Color::Modifier(Color::FG_RED)
		<< "Can't use <unkown Materia type> on " << target.getName()
		<< Color::Modifier()
		<< std::endl;
		return;
	}
	this->use(target);
}
