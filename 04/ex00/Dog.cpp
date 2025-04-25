#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
}

void    Dog::makeSound() const {
    std::cout << "Woof! Woof! Woof! Woof!" << std::endl;
};