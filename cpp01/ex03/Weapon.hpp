#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
    public:
        Weapon(void);
        Weapon(std::string const &type);
        ~Weapon(void);
        void    setType(std::string const &type);
        std::string const & getType(void) const;
    private:
        std::string _type;
};

#endif