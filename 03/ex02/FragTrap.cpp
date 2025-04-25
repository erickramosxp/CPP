
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name) {

    std::cout << "Constructor of FragTrap was called" << std::endl;

    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
};

FragTrap::~FragTrap() {
    std::cout << "Destructor of FragTrap was called" << std::endl;
};

void FragTrap::guardGate() {
    std::cout << "FragTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
};

void FragTrap::highFivesGuys(void) {
    std::cout << "✋ FragTrap " + _name + " demands a high five! Don't leave me hanging! ✋" << std::endl;
};