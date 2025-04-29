#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Default constructor of Cat was called" << std::endl;
    this->type = "Cat";
};

Cat::~Cat() {
    std::cout << "Destructor of Cat was called" << std::endl;
};

Cat::Cat(const Cat &other) {
    std::cout << "Copy constructor of Cat was called" << std::endl;
};

Cat& Cat::operator=(const Cat &other) {

    std::cout << "Copy assignment operator of Cat was called" << std::endl;
};

void    Cat::makeSound() const {
    std::cout << "Meow! Meoww! Meowwww! Meowwwwww!" << std::endl;
};