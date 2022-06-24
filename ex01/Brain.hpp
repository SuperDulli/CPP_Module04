#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <ostream>

class Brain {

public:

	Brain(void);
	Brain(Brain const& other);
	~Brain(void);

	Brain&	operator=(Brain const& other);
	bool	operator==(Brain const& other);

	std::string const*	getIdeas(void) const;
	void				setIdeas(std::string const* ideas, size_t count);

	std::string	getIdea(int n) const;
	void		setIdea(int n, std::string const& idea);

private:

	std::string	m_ideas[100];

};

std::ostream&	operator<<(std::ostream& os, Brain const& brain);

#endif
