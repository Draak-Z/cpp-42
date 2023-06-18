#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << this->getName() << ": returned to the grave" << std::endl;
}

std::string	Zombie::getName(void) const
{
	return (this->name);
}

void	Zombie::announce(void) const
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
