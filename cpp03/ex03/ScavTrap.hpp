#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(ScavTrap const &src);
        ScavTrap(std::string name);
        ~ScavTrap(void);

        ScavTrap & operator=(ScavTrap const &rhs);
        void    attack(std::string const &target);
		void    guardGate(void);

    protected:
        bool _gate_keeper_mode;
};

#endif