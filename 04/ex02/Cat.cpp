#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Default constructor of Cat was called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
};

Cat::~Cat() {
    std::cout << "Destructor of Cat was called" << std::endl;
    delete this->brain;
};

Cat::Cat(const Cat &other): Animal(other) {
    std::cout << "Copy constructor of Cat was called" << std::endl;
    this->type = other.type;
    this->brain = new Brain(*other.brain);
};

Cat& Cat::operator=(const Cat &other) {

    std::cout << "Copy assignment operator of Cat was called" << std::endl;
    
    if (this != &other)
    {
        this->type = other.type;
        if (this->brain) {
            delete this->brain;
            this->brain = new Brain(*other.brain);
        }
    }

    return *this;
};

void    Cat::makeSound() const {
    std::cout << "Meow! Meoww! Meowwww! Meowwwwww!" << std::endl;
};

void Cat::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}
