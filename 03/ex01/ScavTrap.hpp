#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
    
    public:
        ScavTrap(std::string name);
        ~ScavTrap();
        void guardGate();
};

#endif