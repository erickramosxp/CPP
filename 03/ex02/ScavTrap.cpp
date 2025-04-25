
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {

    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "Constructor of ScavTrap was called" << std::endl;
};

ScavTrap::~ScavTrap(){
    std::cout << "Destructor of ScavTrap was called" << std::endl;
};

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
};
