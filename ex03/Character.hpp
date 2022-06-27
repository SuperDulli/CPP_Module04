#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {

public:

	Character(void);
	Character(std::string const& name);
	Character(Character const& other);
	~Character(void);

	Character& operator=(Character const& other);

	std::string const& getName(void) const;

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	AMateria* getMateria(int idx);

private:

	std::string	m_name;
	AMateria*	m_inventory[4];

	void	initInventory(void);
	void	clearInventory(void);

};

#endif
