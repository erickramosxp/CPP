
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal") {
    std::cout << "Default constructor of WrongAnimal was called" << std::endl;
};

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor of WrongAnimal was called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << "Copy constructor of WrongAnimal was called" << std::endl;

    this->type = other.type;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "Copy assignment operator of WrongAnimal was called" << std::endl;

    if (this != &other)
        this->type = other.type;

    return *this;
};

std::string WrongAnimal::getType() const {
    return this->type;
};

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound!" << std::endl;
}