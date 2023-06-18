#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap gearbox("gearbox");
    ClapTrap borderland;
    ClapTrap copy;
    borderland.setName("borderland");
    copy = gearbox;
    gearbox.attack("a rock");
    copy.attack("a wall");
    borderland.attack("a cloud");
    gearbox.takeDamage(20);
    copy.takeDamage(0);
    borderland.takeDamage(5);
    gearbox.beRepaired(20);
    copy.beRepaired(0);
    borderland.beRepaired(5);
    std::cout << std::endl;

    ScavTrap scavenger;
    ScavTrap hyperion("hyperion");
    ScavTrap robot("robot");
    ScavTrap copyy(robot);
    scavenger.setName("scavenger");
    hyperion.attack("a rock");
    copyy.attack("a wall");
    scavenger.attack("a cloud");
    robot.takeDamage(200);
    scavenger.takeDamage(13);
    hyperion.takeDamage(50);
    robot.beRepaired(32);
    scavenger.beRepaired(5);
    hyperion.beRepaired(10);
    robot.guardGate();
    scavenger.guardGate();
    hyperion.guardGate();
    hyperion.guardGate();
    std::cout << std::endl;

    FragTrap final;
    FragTrap boss("boss");
    FragTrap copyyy(boss);
    copyyy.setName("copy");
    final.setName("final");
    final.attack("a brick");
    boss.attack("you");
    final.takeDamage(53);
    boss.takeDamage(800);
    final.beRepaired(100);
    boss.beRepaired(3);
    final.highFivesGuys();
    boss.highFivesGuys();
    copyyy.highFivesGuys();
    std::cout << std::endl;
    return (0);
}