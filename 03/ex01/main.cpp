/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:46:16 by erramos           #+#    #+#             */
/*   Updated: 2025/04/26 16:46:18 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap first("Alphose");
    ClapTrap second("Eric");

    std::cout << "\n=== ClapTraps Attacking Phase ===" << std::endl;
    first.attack("Eric");
    second.attack("Alphose");

    std::cout << "\n=== Copy Constructing ClapTrap: third from first ===" << std::endl;
    ClapTrap third(first);

    std::cout << "\n=== third attacks Neo ===" << std::endl;
    third.attack("Neo");

    std::cout << "\n=== Assignment Operation: second = third ===" << std::endl;
    second = third;

    std::cout << "\n=== second attacks Nanami ===" << std::endl;
    second.attack("Nanami");

    std::cout << "\n=== Creating ScavTrap ===" << std::endl;
    ScavTrap scav("Guard");


    std::cout << "\n=== ScavTrap Actions ===" << std::endl;
    scav.attack("Enemy");
    scav.guardGate();

    return 0;
}

