
#include "ClapTrap.hpp"

int main(void) {

    ClapTrap first("Alphose");
    ClapTrap second("Eric");

    first.attack("Eric");
    second.attack("Alphonse");

    ClapTrap third(first);

    third.attack("Neo");

    second = third;

    second.attack("Nanami");

    return (0);
}