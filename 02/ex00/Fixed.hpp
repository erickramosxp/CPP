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