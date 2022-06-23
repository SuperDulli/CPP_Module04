#include <iostream>
#include <string>
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
	std::cout << "coping ideas..." << std::endl;
	this->setIdeas(other.getIdeas());
	return *this;
}

std::string const*	Brain::getIdeas(void) const {
	return &m_ideas[0]; 
}

void	Brain::setIdeas(std::string const ideas[100]) {
	for (int i = 0; i < 100; i++)
	{
		this->setIdea(i, ideas[i]);
	}
}

std::string	Brain::getIdea(int n) const {
	if (n < 0 || n > 100) {
		std::cerr << "Idea is out of reach: index out of bounds" << std::endl;
		return "";
	}
	return m_ideas[n];
}

void	Brain::setIdea(int n, std::string const& idea) {
	if (n < 0 || n > 100) {
		std::cerr << "Can't place idea inside the mind: index out of bounds" << std::endl;
		return ;
	}
	m_ideas[n] = idea;
}

