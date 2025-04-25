
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Unknow") ,_hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name) ,_hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap) {

    std::cout << "Copy constructor called" << std::endl;

    this->_name = clap._name;
    this->_hitPoints = clap._hitPoints;
    this->_energyPoints = clap._energyPoints;
    this->_attackDamage = clap._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clap) {


    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &clap) {
        return *this;
    }

    this->_name = clap._name;
    this->_hitPoints = clap._hitPoints;
    this->_energyPoints = clap._energyPoints;
    this->_attackDamage = clap._attackDamage;

    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    
    if (this->_energyPoints > 0) {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else {
        std::cout << this->_name << " does not have enought energy points for this attack" << std::endl;
    }
};

void ClapTrap::takeDamage(unsigned int amount) {
    this->_attackDamage = amount;
    std::cout << "Added " << amount << " attack damage to the ClapTrap " << this->_name << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount) {

    if (this->_energyPoints > 0) {
        std::cout << "Repairs " << amount << " hit points for ClapTrap " << this->_name << std::endl;
        this->_energyPoints--;
    } else {
        std::cout << this->_name << " does not have enought energy points for restore hit points" << std::endl;
    }
};