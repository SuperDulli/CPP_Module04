#ifndef MATERIA_SOURCE_H
#define MATERIA_SOURCE_H

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:

	MateriaSource(void);
	MateriaSource(MateriaSource const& other);
	~MateriaSource(void);

	MateriaSource& operator=(MateriaSource const& other);

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const& type);

private:

	AMateria*	m_materias[4];

	void	clearMaterias(void);

};

#endif
