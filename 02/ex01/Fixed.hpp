/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:20:19 by erramos           #+#    #+#             */
/*   Updated: 2025/04/26 13:20:20 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _number;
        static const int _bits;
        
    public:
        Fixed(void);
        Fixed(const Fixed &fixed);
        Fixed(const int nb);
        Fixed(const float nb);
        float toFloat( void ) const;
        int toInt( void ) const;
        ~Fixed();
        Fixed &operator=(const Fixed& fixed);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
};

std::ostream &operator<<(std::ostream& os, const Fixed& fixed);

#endif
