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

int main(void) {

    ClapTrap first("Alphose");
    ClapTrap second("Eric");

    first.attack("Eric");
    second.attack("Alphonse");

    ClapTrap third(first);

    third.attack("Neo");

    second = third;

    second.attack("Nanami");

    ScavTrap scav("Guard");
    scav.attack("Enemy");
    scav.guardGate(); 

    return (0);
}
