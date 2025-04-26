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

int main(void) {

    ClapTrap first("Alphose");
    ClapTrap second("Eric");

    first.attack("Eric");
    second.attack("Alphonse");

    ClapTrap third(first);

    third.attack("Neo");

    second = third;

    second.attack("Nanami");

    return (0);
}
