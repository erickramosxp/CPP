#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
};

void    Cat::makeSound() const {
    std::cout << "Meow! Meoww! Meowwww! Meowwwwww!" << std::endl;
};