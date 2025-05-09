#include "Dog.hpp"

Dog::Dog() {

    std::cout << "Default constructor of Dog was called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog() {
    std::cout << "Destructor of Dog was called" << std::endl;
};

Dog::Dog(const Dog &other): Animal(other) {
    std::cout << "Copy constructor of Dog was called" << std::endl;

    this->type = other.type;
};

Dog& Dog::operator=(const Dog &other) {
    std::cout << "Copy assignment operator of Dog was called" << std::endl;

    if (this != &other)
        this->type = other.type;    
    
    return *this;
};

void    Dog::makeSound() const {
    std::cout << "Woof! Woof! Woof! Woof!" << std::endl;
};