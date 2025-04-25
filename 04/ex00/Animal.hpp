#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {

    protected:
        std::string type;
    
    public:
        std::string getType() const;
        virtual void    makeSound() const;
};

#endif