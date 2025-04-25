
#include "WrongAnimal.hpp"

std::string WrongAnimal::getType() const {
    return this->type;
};

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound!" << std::endl;
}