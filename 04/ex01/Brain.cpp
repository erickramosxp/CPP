#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Default constructor of Brain was called" << std::endl;
};

Brain::~Brain() {
    std::cout << "Destructor of Brain was called" << std::endl;
};

Brain::Brain(const Brain &other) {

    std::cout << "Copy constructor of Brain was called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        this->ideas[i] = other.ideas[i];
    }
};

Brain& Brain::operator=(const Brain &other) {
    
    std::cout << "Copy assignment operator of Brain was called" << std::endl;
    
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];
        }
    }
    
    return *this;
};

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}