#include "Character.hpp"

Character::Character(void) : _name("default")
{
	for (int i = 0; i < _size; i++)
		_inventory[i] = NULL;
}


Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < _size; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const &rhs) : _name(rhs.getName())
{
	for (int i = 0; i < _size; i++)
		this->_inventory[i] = rhs._inventory[i]->clone();
}

Character::~Character()
{
	for (int i = 0; i < _size; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
}

Character	&Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		for (int i = 0; i < _size; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

const std::string	&Character::getName(void) const { return (this->_name); }

void	Character::equip(AMateria *m)
{
	if (m)
	{
		std::cout << this->getName();
		for (int i = 0; i < _size; i++)
		{
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = m;
				std::cout << " equips " << m->getType() << " in slot " << i << std::endl;
				return ;
			}
		}
		std::cout << " can't equip " <<  m->getType() << std::endl;
		delete m;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < _size)
	{
		std::cout << this->getName() << " unequips " << this->_inventory[idx]->getType() << " from slot " << idx << std::endl;
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < _size && this->_inventory[idx])
	{
		std::cout << this->getName() << " ";
		this->_inventory[idx]->use(target);
	}
}