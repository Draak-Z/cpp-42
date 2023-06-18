#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap gearbox("gearbox");
    ClapTrap Default;
    ClapTrap borderland;
    borderland = gearbox;
    gearbox.attack("a rock");
    borderland.attack("a wall");
    Default.attack("a cloud");
    gearbox.takeDamage(20);
    borderland.takeDamage(0);
    Default.takeDamage(5);
    gearbox.beRepaired(20);
    borderland.beRepaired(0);
    Default.beRepaired(5);
    for (int i = 0; i < 9; i++)
        borderland.beRepaired(0);
    borderland.attack("a wall");
    std::cout << "borderland is named " << borderland.getName() << std::endl << std::endl;
}