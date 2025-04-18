#include "HumanB.hpp"

void HumanB::setWeapon(Weapon& weapon){
    this->weapon = &weapon;
}

HumanB::HumanB(std::string name) {
    this->name = name;
    this->weapon = NULL;
}

void HumanB::attack() {
    if (this->weapon)
        std::cout << this->name + " attacks with their " + this->weapon->getType() << std::endl;
}