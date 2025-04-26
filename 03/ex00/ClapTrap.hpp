/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:45:16 by erramos           #+#    #+#             */
/*   Updated: 2025/04/26 16:45:18 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

    private:

        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

    public:

        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &clap);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& clap);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName();
        int getHitPoints();
        int getEnergyPoints();
        int getAttackDamage();
};


#endif
