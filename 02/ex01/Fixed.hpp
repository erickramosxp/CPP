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