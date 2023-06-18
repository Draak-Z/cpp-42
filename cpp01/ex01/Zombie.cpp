
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->_name = "\0";
}

Zombie::Zombie(std::string name)
{
	setName(name);
}

Zombie::~Zombie(void)
{
	std::cout << this->getName() << ": returned to the grave" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void) const
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(void) const
{
	return (this->_name);
}