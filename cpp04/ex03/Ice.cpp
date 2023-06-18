#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(Ice const &rhs) : AMateria(rhs) {}

Ice::~Ice() {}

Ice	&Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

Ice		*Ice::clone() const { return (new Ice(*this)); }

void	Ice::use(ICharacter &target) { std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; };
