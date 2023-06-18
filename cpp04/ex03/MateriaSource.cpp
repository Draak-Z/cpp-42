#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < _size; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &rhs)
{
	for (int i = 0; i < _size; i++)
		this->_inventory[i] = rhs._inventory[i]->clone();
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _size; i++)
		if (_inventory[i])
			delete _inventory[i];
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
	{
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

void		MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < _size; i++)
	{
		if (!this->_inventory[i])
		{
			std::cout << "MateriaSource learns " << m->getType() << std::endl;
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "MateriaSource can't learn new materia" << std::endl;
	delete m;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < _size; i++)
		if (this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	std::cout << "MateriaSource can't create " << type << " materia because it is unknown" << std::endl;
	return (NULL);
}
