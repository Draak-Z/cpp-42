#include "Weapon.hpp"

Weapon::Weapon(void)
{
    return;
}

Weapon::Weapon(std::string const &type)
{
    this->setType(type);
}

Weapon::~Weapon(void)
{
    return;
}

void    Weapon::setType(std::string const &type)
{
    this->_type = type;
}

std::string const & Weapon::getType(void) const
{
    return (this->_type);
}