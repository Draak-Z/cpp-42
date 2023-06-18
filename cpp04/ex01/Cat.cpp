#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(Cat const &rhs) : Animal(rhs), _brain(new Brain(*(rhs._brain)))
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	if (this->_brain)
		delete this->_brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
    *this->_brain = *rhs._brain;
	return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "miaou" << std::endl;
}

Brain *Cat::getBrain()
{
	return (this->_brain);
}