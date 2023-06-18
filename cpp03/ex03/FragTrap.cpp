#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const & rhs) : ClapTrap(rhs)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->_name << " is destructed." << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const &rhs)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    this->_name = rhs.getName();
    this->_hit_points = rhs.getHitpoints();
    this->_energy_points = rhs.getEnergyPoints();
    this->_attack_damage = rhs.getAttackDamage();
    return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " is requesting a high fives !" << std::endl;
}