#ifndef A_MATERIA_H
#define A_MATERIA_H

#include <string>

class ICharacter;

class AMateria {

public:

	AMateria(void);
	AMateria(AMateria const& other);
	AMateria(std::string const& type);
	virtual ~AMateria(void);

	AMateria& operator=(AMateria const& other);

	std::string const& getType(void) const;

	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target);

protected:

	std::string	m_type;

};

#include "ICharacter.hpp"

#endif
