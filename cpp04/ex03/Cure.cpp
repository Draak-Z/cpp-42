#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(Cure const &rhs) : AMateria(rhs) {}

Cure::~Cure() {}

Cure	&Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

Cure	*Cure::clone() const { return (new Cure(*this)); }

void	Cure::use(ICharacter &target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; };
