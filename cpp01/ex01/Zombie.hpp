
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
	    Zombie(void);
	    Zombie(std::string name);
	    ~Zombie(void);
	    std::string getName(void) const;
	    void    setName(std::string name);
	    void    announce(void) const;
	private:
	    std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif