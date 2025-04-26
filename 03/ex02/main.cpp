/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:47:28 by erramos           #+#    #+#             */
/*   Updated: 2025/04/26 16:47:30 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "=== Creating ClapTrap: Alphose ===" << std::endl;
    ClapTrap first("Alphose");

    std::cout << "\n=== Creating ClapTrap: Eric ===" << std::endl;
    ClapTrap second("Eric");

    std::cout << "\n=== Attacking Phase ===" << std::endl;
    first.attack("Eric");
    second.attack("Alphonse");

    std::cout << "\n=== Copy Constructing ClapTrap: third from first ===" << std::endl;
    ClapTrap third(first);

    std::cout << "\n=== Checking Energy Points Eric (first) ===" << std::endl;
    std::cout << first.getEnergyPoints() << std::endl;

    std::cout << "\n=== third attacks Neo ===" << std::endl;
    third.attack("Neo");

    std::cout << "\n=== Assignment Operation: second = third ===" << std::endl;
    second = third;

    std::cout << "\n=== second attacks Nanami ===" << std::endl;
    second.attack("Nanami");

    std::cout << "\n=== Creating ScavTrap: Guard ===" << std::endl;
    ScavTrap scav("Guard");

    std::cout << "\n=== ScavTrap attacks Enemy and enters Gate Keeper Mode ===" << std::endl;
    scav.attack("Enemy");
    scav.guardGate();

    std::cout << "\n=== Checking Energy Points (scav) ===" << std::endl;
    std::cout << scav.getEnergyPoints() << std::endl;

    std::cout << "\n=== Creating FragTrap: Bob ===" << std::endl;
    FragTrap frag("Bob");

    std::cout << "\n=== FragTrap requests High Fives ===" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n=== Checking Energy Points (frag) ===" << std::endl;
    std::cout << frag.getEnergyPoints() << std::endl;

    return 0;
}
