#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(), _gate_keeper_mode(false)
{
    std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gate_keeper_mode(false)
{
    std::cout << "ScavTrap name constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & rhs) : ClapTrap(rhs), _gate_keeper_mode(rhs._gate_keeper_mode)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->_name << " is destructed." << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    this->_name = rhs.getName();
    this->_hit_points = rhs.getHitpoints();
    this->_energy_points = rhs.getEnergyPoints();
    this->_attack_damage = rhs.getAttackDamage();
    this->_gate_keeper_mode = rhs._gate_keeper_mode;
    return (*this);
}

void    ScavTrap::attack(std::string const &target)
{
    if (this->_energy_points == 0)
        std::cout << "Not enough energy to attack" << std::endl;
    else if (this->_hit_points == 0)
        std::cout << "This ScavTrap is KO and can't attack" << std::endl;
    else
    {
        this->_energy_points--;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage !" << std::endl;
    }
}

void    ScavTrap::guardGate(void)
{
    if (this->_energy_points == 0)
        std::cout << "Not enough energy to go in Gate keeper mode" << std::endl;
    else if (this->_hit_points == 0)
        std::cout << "This ScavTrap is KO and can't go in Gate keeper mode" << std::endl;
    else if (this->_gate_keeper_mode == false)
    {
        this->_gate_keeper_mode = true;
        this->_energy_points--;
        std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
    }
    else if (this->_gate_keeper_mode == true)
        std::cout << "ScavTrap " << this->_name << " is already in Gate keeper mode" << std::endl;
}