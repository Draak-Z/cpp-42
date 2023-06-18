#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
    std::cout << "DiamondTrap name constructor called" << std::endl;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(DiamondTrap const & rhs) : ClapTrap(rhs)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    this->_gate_keeper_mode = rhs._gate_keeper_mode;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->_name << " is destructed." << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const &rhs)
{
    std::cout << "DiamondTrap assignation operator called" << std::endl;
    this->_name = rhs.getName();
    this->_hit_points = rhs.getHitpoints();
    this->_energy_points = rhs.getEnergyPoints();
    this->_attack_damage = rhs.getAttackDamage();
    this->_gate_keeper_mode = rhs._gate_keeper_mode;
    return (*this);
}

std::string const	&DiamondTrap::getName(void) const
{
	return (this->DiamondTrap::_name);
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap's name is " << this->_name <<  " and its Claptrap name is " << this->ClapTrap::_name << std::endl;
}