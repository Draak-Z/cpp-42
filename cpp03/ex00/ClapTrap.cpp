#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_name = rhs.getName();
    this->_hit_points = rhs.getHitpoints();
    this->_energy_points = rhs.getEnergyPoints();
    this->_attack_damage = rhs.getAttackDamage();
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
    std::cout << this->_name << " is destructed." << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &rhs)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    this->_name = rhs.getName();
    this->_hit_points = rhs.getHitpoints();
    this->_energy_points = rhs.getEnergyPoints();
    this->_attack_damage = rhs.getAttackDamage();
    return (*this);
}

void    ClapTrap::attack(std::string const &target)
{
    if (this->_energy_points == 0)
        std::cout << "Not enough energy to attack" << std::endl;
    else if (this->_hit_points == 0)
        std::cout << "This ClapTrap is KO and can't attack" << std::endl;
    else
    {
        this->_energy_points--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage !" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_points == 0)
        std::cout << "This ClapTrap is already KO and can't take more damage" << std::endl;
    else if (this->_hit_points <= amount)
    {
        this->_hit_points = 0;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage and is KO !" << std::endl;
    }
    else
    {
        this->_hit_points -= amount;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage !" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_points == 0)
        std::cout << "Not enough energy to repair itself" << std::endl;
    else if (this->_hit_points == 0)
        std::cout << "This ClapTrap is KO and can't repair itself" << std::endl;
    else
    {
        this->_energy_points--;
        this->_hit_points += amount;
        std::cout << "ClapTrap " << this->_name << " repairs itself and gets " << amount << " hit points back" << std::endl;
    }
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

int ClapTrap::getHitpoints() const
{
	return (this->_hit_points);
}

int ClapTrap::getEnergyPoints() const
{
	return (this->_energy_points);
}

int ClapTrap::getAttackDamage() const
{
	return (this->_attack_damage);
}