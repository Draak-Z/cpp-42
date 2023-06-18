#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &rhs) : _type(rhs.getType())
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << this->_type << " makes a sound" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->_type);
}