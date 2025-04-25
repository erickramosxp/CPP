#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string type;

    public:
        std::string getType() const;
        void    makeSound() const;
};

#endif