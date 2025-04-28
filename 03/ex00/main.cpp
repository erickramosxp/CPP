/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:45:21 by erramos           #+#    #+#             */
/*   Updated: 2025/04/26 16:45:22 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "=== Creating ClapTrap: Alphose ===" << std::endl;
    ClapTrap first("Alphose");

    std::cout << "\n=== Creating ClapTrap: Eric ===" << std::endl;
    ClapTrap second("Eric");

    std::cout << "\n=== Attacking Phase ===" << std::endl;
    first.attack("Eric");
    second.attack("Alphose");

    std::cout << "\n=== Copy Constructing ClapTrap: third from first ===" << std::endl;
    ClapTrap third(first);

    std::cout << "\n=== third attacks Neo ===" << std::endl;
    third.attack("Neo");

    std::cout << "\n=== Assignment Operation: second = third ===" << std::endl;
    second = third;

    third.takeDamage(50);
    third.attack("Neo");

    std::cout << "\n=== second attacks Nanami ===" << std::endl;
    second.attack("Nanami");

    return 0;
}

