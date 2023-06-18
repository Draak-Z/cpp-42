#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(Cat const &rhs) : Animal(rhs)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "miaou" << std::endl;
}