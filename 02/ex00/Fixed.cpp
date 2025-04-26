/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:19:00 by erramos           #+#    #+#             */
/*   Updated: 2025/04/26 13:19:02 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void): _number(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &fixed) {
    *this = fixed;
    std::cout << "Copy constructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& fixed) {
    this->_number = fixed._number;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
};

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
    return this->_number;
}

void Fixed::setRawBits(int const raw) {
    this->_number = raw;
}
