/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:47:36 by erramos           #+#    #+#             */
/*   Updated: 2025/04/26 16:47:39 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {

    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "Constructor of ScavTrap was called" << std::endl;
};

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
};

ScavTrap::ScavTrap() {
    
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "Default constructor of ScavTrap was called" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {

    std::cout << "Copy constructor of ScavTrap called" << std::endl;

};

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    
    std::cout << "Copy assignment operator ScavTrap was called" << std::endl;

    if (this == &other)
        return *this;
    ClapTrap::operator=(other);

    return *this;
};


ScavTrap::~ScavTrap(){
    std::cout << "Destructor of ScavTrap was called" << std::endl;
};

void ScavTrap::attack(const std::string& target) {
    
    if (this->_hitPoints <= 0) {
        std::cout << this->_name << " is dead" << std::endl;
        return ;
    }
    
    if (this->_energyPoints > 0) {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else {
        std::cout << this->_name << " does not have enought energy points for this attack" << std::endl;
    }
};

void ScavTrap::beRepaired(unsigned int amount) {

    if (this->_energyPoints > 0) {
        std::cout << "Repairs " << amount << " hit points for ScavTrap " << this->_name << std::endl;
        this->_hitPoints = amount;
        this->_energyPoints--;
    } else {
        std::cout << this->_name << " does not have enought energy points for restore hit points" << std::endl;
    }
};
