
#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "Color.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main(void) {
	// std::cout << Color::Modifier(Color::BG_GREEN) << "RED" << std::endl;
	std::cout << "--- Test begin ---" << std::endl;
	{
		std::cout << "-- Test from subject --" << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;

	}
	std::cout << std::string(80, '-') << std::endl;
	{
		std::cout << "-- Test capacity --" << std::endl;

		MateriaSource* ms = new MateriaSource();
		AMateria* m = new Ice();

		ms->learnMateria(new Ice());
		ms->learnMateria(new Ice());
		ms->learnMateria(new Ice());
		ms->learnMateria(new Ice());
		ms->learnMateria(m);

		ms->createMateria("cure");
		ms->createMateria("virus");

		delete m;
		delete ms;

		std::cout << "- Character -" << std::endl;

		Character* c = new Character("Indiana Jones");
		AMateria* cure = new Cure();

		c->unequip(0);
		c->use(0, *c);
		c->equip(new Cure());
		c->equip(new Cure());
		c->equip(new Cure());
		c->equip(new Cure());
		c->equip(cure);
		c->unequip(4);

		AMateria* mOnTheFloor = c->getMateria(1);
		c->unequip(1);
		delete mOnTheFloor;
		c->equip(new Ice());

		delete c;
		delete cure;

	}
	std::cout << std::string(80, '-') << std::endl;
	{
		std::cout << "-- Test copy --" << std::endl;

		AMateria* copy;
		AMateria* cure = new Cure();
		AMateria* ice = new Ice();

		copy = cure;
		cure = ice;

		std::cout
		<< "Type of cure after assigning ice to it:"
		<< cure->getType()
		<< std::endl;

		delete copy;
		delete cure;
		// delete ice; // already deleted
	}
	return 0;
}
