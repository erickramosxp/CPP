
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {

    ClapTrap first("Alphose");
    ClapTrap second("Eric");

    first.attack("Eric");
    second.attack("Alphonse");

    ClapTrap third(first);

    third.attack("Neo");

    second = third;

    second.attack("Nanami");

    ScavTrap scav("Guard");
    scav.attack("Enemi");
    scav.guardGate(); 

    FragTrap frag("Bob");
    frag.highFivesGuys();

    return (0);
}