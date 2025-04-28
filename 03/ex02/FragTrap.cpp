/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:47:15 by erramos           #+#    #+#             */
/*   Updated: 2025/04/26 16:47:18 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

FragTrap::FragTrap() {

    std::cout << "Default constructor of FragTrap was called" << std::endl;

    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
};

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other) {

    std::cout << "Copy constructor of FragTrap called" << std::endl;
};

FragTrap& FragTrap::operator=(const FragTrap &other) {

    std::cout << "Copy assignment operator FragTrap was called" << std::endl;

    if (this == &other)
        return *this;
    ClapTrap::operator=(other);

    return *this;
};

void FragTrap::attack(const std::string& target) {
    
    if (this->_hitPoints <= 0) {
        std::cout << this->_name << " is dead" << std::endl;
        return ;
    }

    if (this->_energyPoints > 0) {
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else {
        std::cout << this->_name << " does not have enought energy points for this attack" << std::endl;
    }
};

void FragTrap::takeDamage(unsigned int amount) {

    if (this->_hitPoints <= 0) {
        std::cout << this->_name << " is dead" << std::endl;
        return ;
    }

    if (this->_hitPoints <= 0) {
         std::cout << this->_name << " is dead" << std::endl;
         return ;
    }
    this->_hitPoints -= amount;
    std::cout << _name << " took " << amount << " points of damage!" << std::endl;
};

void FragTrap::beRepaired(unsigned int amount) {

    if (this->_energyPoints > 0) {
        std::cout << "Repairs " << amount << " hit points for FragTrap " << this->_name << std::endl;
        this->_hitPoints = amount;
        this->_energyPoints--;
    } else {
        std::cout << this->_name << " does not have enought energy points for restore hit points" << std::endl;
    }
};
