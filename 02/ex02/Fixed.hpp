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
        friend std::ostream &operator<<(std::ostream& os, const Fixed& fixed);
        
        bool &operator>(const Fixed& fixed);
        bool &operator<(const Fixed& fixed);
        bool &operator>=(const Fixed& fixed);
        bool &operator<=(const Fixed& fixed);
        bool &operator==(const Fixed& fixed);
        bool &operator!=(const Fixed& fixed);

        float &operator-(const Fixed& fixed);
        float &operator+(const Fixed& fixed);
        float &operator*(const Fixed& fixed);
        float &operator/(const Fixed& fixed);

        float &operator++(void);
        float &operator--(void);
        float &operator++(int);
        float &operator--(int);

        static Fixed& min(Fixed &nb1, Fixed &nb2);
        static Fixed& min(const Fixed &nb1, const Fixed &nb2);

        static Fixed& max(Fixed &nb1, Fixed &nb2);
        static Fixed& max(const Fixed &nb1, const Fixed &nb2);
};


#endif