#include <iostream>
#include <string>
#include <iomanip>
#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(Brain const& other) {
	*this = other;
	std::cout << "Brain copied" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain destroyed" << std::endl;
}

Brain&	Brain::operator=(Brain const& other) {
	std::cout << "Brain copy assignment operator: coping ideas..." << std::endl;
	this->setIdeas(other.getIdeas(), 100);
	return *this;
}

bool	Brain::operator==(Brain const& other) {
	std::cout << "Comparing brains" << std::endl;
	std::cout << &this->m_ideas << std::endl;
	std::cout << &other.m_ideas << std::endl;
	std::cout << &this->m_ideas - &other.m_ideas << std::endl;

	return (&this->m_ideas == &other.m_ideas);
}

std::string const*	Brain::getIdeas(void) const {
	return &m_ideas[0]; 
}

void	Brain::setIdeas(std::string const* ideas, size_t count) {
	if (count > 100) {
		std::cerr << "Too many ideas: " << count << std::endl;
		count = 100;
	}
	for (size_t i = 0; i < count; i++)
	{
		this->setIdea(i, ideas[i]);
	}
}

std::string	Brain::getIdea(int n) const {
	if (n < 0 || n >= 100) {
		std::cerr << "Idea is out of reach: index out of bounds: " << n << std::endl;
		return "";
	}
	return m_ideas[n];
}

void	Brain::setIdea(int n, std::string const& idea) {
	if (n < 0 || n >= 100) {
		std::cerr << "Can't place idea inside the mind: index out of bounds: " << n << std::endl;
		return ;
	}
	m_ideas[n] = idea;
}

std::ostream&	operator<<(std::ostream& os, Brain const& brain) {
	for (size_t i = 0; i < 100; i++)
	{
		std::string const	idea = brain.getIdea(i);
		os << "#" << std::setw(2) << std::setfill('0') << i << ": ";
		if (idea.empty()) {
			os << "<is empty>" << std::endl;
			break;
		}
		os << idea << std::endl;
	}
	return os;
}
