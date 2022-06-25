#include <iostream>
#include <string>
#include "Color.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {}

MateriaSource::MateriaSource(MateriaSource const& other) {
	*this = other;
}

MateriaSource::~MateriaSource(void) {
	this->clearMaterias();
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other) {
	this->clearMaterias();
	for (size_t i = 0; i < 4; i++)
	{
		if (!other.m_materias[i])
			this->m_materias[i] = other.m_materias[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->m_materias[i]) {
			this->m_materias[i] = m->clone();
			std::cout
			<< "MateriaSource: " << m->getType() << " added at index " << i
			<< std::endl;
			return;
		}
	}
	std::cerr
	<< Color::Modifier(Color::FG_RED)
	<< "MateriaSource: Can't add " << m->getType() << ": Capacity reached"
	<< Color::Modifier()
	<< std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->m_materias[i]) {
			break;
		}
		if (this->m_materias[i]->getType() == type) {
			return this->m_materias[i]->clone();
		}
	}
	std::cerr
	<< Color::Modifier(Color::FG_RED)
	<< "MateriaSource: Can't create " << type << ": Materia type unkown"
	<< Color::Modifier()
	<< std::endl;
	return NULL;
}

void MateriaSource::clearMaterias(void) {
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->m_materias[i])
			break;
		delete this->m_materias[i];
		this->m_materias[i] = NULL;
	}

}
