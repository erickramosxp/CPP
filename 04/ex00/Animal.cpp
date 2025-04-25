# include "Animal.hpp"


std::string Animal::getType() const {

    return this->type;
};

void Animal::makeSound() const {
    std::cout << "Animal sound!" << std::endl;
}