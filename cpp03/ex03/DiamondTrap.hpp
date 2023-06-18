#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(DiamondTrap const &src);
        DiamondTrap(std::string name);
        ~DiamondTrap(void);

        DiamondTrap & operator=(DiamondTrap const &rhs);
		std::string const	&getName(void) const;
		void		attack(std::string const &target);
		void whoAmI(void);

	private:
        DiamondTrap(void);
		std::string _name;
};

#endif