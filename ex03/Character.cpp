#include <iostream>
#include <string>
#include "Color.hpp"
#include "Character.hpp"

Character::Character(void) {}

Character::Character(std::string const& name): m_name(name) {}

Character::Character(Character const& other): m_name(other.m_name) {
	*this = other;
}

Character::~Character(void) {
	this->clearInventory();
}

Character& Character::operator=(Character const& other) {
	this->m_name = other.m_name;
	this->clearInventory();
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->m_inventory[i])
			this->m_inventory[i] = other.m_inventory[i]->clone();
	}
	return *this;
}

std::string const& Character::getName(void) const {
	return m_name;
}

void Character::equip(AMateria* m) {
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->m_inventory[i]) {
			this->m_inventory[i] = m;
			std::cout
			<< this->m_name << " equips " << m->getType() << " at slot #" << i
			<< std::endl;
			return;
		}
	}
	std::cerr
	<< Color::Modifier(Color::FG_RED)
	<< this->m_name << "can't equip " << m->getType() << ": Full inventory"
	<< Color::Modifier()
	<< std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || 4 >= idx) {
		std::cerr
		<< Color::Modifier(Color::FG_RED)
		<< this->m_name << " can't unequip Materia at index " << idx
		<< ": index out of bounds"
		<< Color::Modifier()
		<< std::endl;
		return;
	}
	if (!this->m_inventory[idx]) {
		std::cerr
		<< Color::Modifier(Color::FG_RED)
		<< this->m_name << " can't unequip Materia at index " << idx
		<< ": no Materia at this inventory slot"
		<< Color::Modifier()
		<< std::endl;
		return;
	}
	this->m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || 4 <= idx) {
		std::cerr
		<< Color::Modifier(Color::FG_RED)
		<< this->m_name << " can't use Materia at index " << idx
		<< ": index out of bounds"
		<< Color::Modifier()
		<< std::endl;
		return;
	}
	if (!this->m_inventory[idx]) {
		std::cerr
		<< Color::Modifier(Color::FG_RED)
		<< this->m_name << " can't use Materia at index " << idx
		<< ": no Materia at this inventory slot"
		<< Color::Modifier()
		<< std::endl;
		return;
	}
	this->m_inventory[idx]->use(target);
}

void Character::clearInventory(void) {
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->m_inventory[i])
			continue;
		delete this->m_inventory[i];
		this->m_inventory[i] = NULL;
	}
}
