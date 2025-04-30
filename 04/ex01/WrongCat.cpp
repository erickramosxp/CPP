
#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "Default constructor of WrongCat was called" << std::endl;
    this->type = "WrongCat";
};

WrongCat::~WrongCat() {
    std::cout << "Destructor of WrongCat was called" << std::endl;
};

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other) {
    std::cout << "Copy constructor of WrongCat was called" << std::endl;

    this->type = other.type;
};

WrongCat& WrongCat::operator=(const WrongCat &other) {
    std::cout << "Copy assignment operator of WrongCat was called" << std::endl;

    if (this != &other)
        this->type = other.type;

    return *this;

};

void    WrongCat::makeSound() const {
    std::cout << "WrongMeow! WrongMeoww! WrongMeowwww! WrongMeowwwwww!" << std::endl;
};