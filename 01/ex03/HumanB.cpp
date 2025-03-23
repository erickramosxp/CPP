#include "HumanB.hpp"

void HumanB::attack() {
    std::cout << this->name + " attacks with their " + this->weapon->getType() << std::endl;
}