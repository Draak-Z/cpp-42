#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(Dog const &rhs) : AAnimal(rhs), _brain(new Brain(*(rhs._brain)))
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	if (this->_brain)
		delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
    *this->_brain = *rhs._brain;
	return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "waf waf !" << std::endl;
}

Brain *Dog::getBrain()
{
	return (this->_brain);
}