#include "AMateria.hpp"


AMateria::AMateria(void) : _type("default") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const &rhs) : _type(rhs.getType()) {}

AMateria::~AMateria(void) {}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

std::string const	&AMateria::getType() const {return (this->_type);}

void	AMateria::use(ICharacter &target) {(void)target;}