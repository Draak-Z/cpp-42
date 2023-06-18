#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Zombie 
{
    public:
        Zombie(std::string name);
        ~Zombie(void);
        void    announce(void) const;
        std::string getName(void) const;
    private:
        std::string name;
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif