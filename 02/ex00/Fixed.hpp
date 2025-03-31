#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
    private:
        int number;
        static const int bits;
        
    public:
        Fixed(void);
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );

}

#endif