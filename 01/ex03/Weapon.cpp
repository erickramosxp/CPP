#include "Weapon.hpp"

const Weapon::std::string& getType() {
    return this->type;
}

void Weapon::setType(std::string type) {
    this->type = type;
}