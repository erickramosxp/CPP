#include "HumanB.hpp"

void HumanB::setWeapon(Weapon& weapon){
    this->weapon = &weapon;
}

HumanB::HumanB(std::string name) {
    this->name = name;
    this->weapon = nullptr;
}

void HumanB::attack() {
    if (this->weapon)
        std::cout << this->name + " attacks with their " + this->weapon->getType() << std::endl;
}