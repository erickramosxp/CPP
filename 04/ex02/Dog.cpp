#include "Dog.hpp"

Dog::Dog() {

    std::cout << "Default constructor of Dog was called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::~Dog() {
    std::cout << "Destructor of Dog was called" << std::endl;

    delete this->brain;
};

Dog::Dog(const Dog &other): Animal(other) {
    std::cout << "Copy constructor of Dog was called" << std::endl;

    this->type = other.type;
    this->brain = new Brain(*other.brain);
};

Dog& Dog::operator=(const Dog &other) {
    std::cout << "Copy assignment operator of Dog was called" << std::endl;

    if (this != &other) {
        this->type = other.type;    
        if (this->brain) {
            delete this->brain;
            this->brain = new Brain(*other.brain);
        }
    }
    
    return *this;
};

void    Dog::makeSound() const {
    std::cout << "Woof! Woof! Woof! Woof!" << std::endl;
};

void Dog::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}