/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:46:25 by erramos           #+#    #+#             */
/*   Updated: 2025/04/26 16:46:27 by erramos          ###   ########.fr       */
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
    
    std::cout << "Default constructor of ScavTrap was called" << std::endl;

    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
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
