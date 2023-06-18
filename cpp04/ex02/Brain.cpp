#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &rhs)
{
    std::cout << "Brain copy constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	if (this == &rhs)
		return (*this);
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}

std::string *Brain::getIdeas()
{
	return (this->ideas);
}