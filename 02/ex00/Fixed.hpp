/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:19:11 by erramos           #+#    #+#             */
/*   Updated: 2025/04/26 13:19:13 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _number;
        static const int _bits;
        
    public:
        Fixed(void);
        Fixed(const Fixed &fixed);
        ~Fixed();
        Fixed &operator=(const Fixed& fixed);

        int getRawBits( void ) const;
        void setRawBits( int const raw );

};

#endif
