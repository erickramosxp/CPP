# include "Animal.hpp"

Animal::Animal(): type("Unknow") {
    std::cout << "Default constructor of Animal was called" << std::endl;
};

Animal::~Animal() {
    std::cout << "Destructor of Animal was called" << std::endl;
};

Animal::Animal(const Animal &other) {
    std::cout << "Copy constructor of Animal was called" << std::endl;

    this->type = other.type;
};

Animal& Animal::operator=(const Animal &other) {
    std::cout << "Copy assignment operator of Animal was called" << std::endl;

    if (this == &other)
        return (*this);

    this->type = other.type;
    return (*this);
};

std::string Animal::getType() const {

    return this->type;
};

void Animal::makeSound() const {
    std::cout << "Animal sound!" << std::endl;
}