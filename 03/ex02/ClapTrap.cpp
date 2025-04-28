/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:46:59 by erramos           #+#    #+#             */
/*   Updated: 2025/04/26 16:47:01 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Unknow") ,_hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor of ClapTrap was called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name) ,_hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Parameterized constructor of ClapTrap was called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap) {

    std::cout << "Copy constructor of ClapTrap was called" << std::endl;

    this->_name = clap._name;
    this->_hitPoints = clap._hitPoints;
    this->_energyPoints = clap._energyPoints;
    this->_attackDamage = clap._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clap) {


    std::cout << "Copy assignment operator of ClapTrap was called" << std::endl;

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
    std::cout << "Destructor of ClapTrap called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    
    if (this->_hitPoints <= 0) {
        std::cout << this->_name << " is dead" << std::endl;
        return ;
    }
    
    if (this->_energyPoints > 0) {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else {
        std::cout << this->_name << " does not have enought energy points for this attack" << std::endl;
    }
};

void ClapTrap::takeDamage(unsigned int amount) {

    if (this->_hitPoints <= 0) {
         std::cout << this->_name << " is dead" << std::endl;
         return ;
    }
    this->_hitPoints -= amount;
    std::cout << _name << " took " << amount << " points of damage!" << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount) {

    if (this->_energyPoints > 0) {
        std::cout << "Repairs " << amount << " hit points for ClapTrap " << this->_name << std::endl;
        this->_hitPoints = amount;
        this->_energyPoints--;
    } else {
        std::cout << this->_name << " does not have enought energy points for restore hit points" << std::endl;
    }
};

std::string ClapTrap::getName() {
    return _name;
}

int ClapTrap::getHitPoints() {
    return _hitPoints;
}

int ClapTrap::getEnergyPoints() {
    return _energyPoints;
}

int ClapTrap::getAttackDamage() {
    return _attackDamage;
}
