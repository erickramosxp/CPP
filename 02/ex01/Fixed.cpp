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
    std::cout << "Copy assignment operator called" << std::endl;
    this->_number = fixed.getRawBits();
    return *this;
};

Fixed::Fixed(const int nb): _number(nb << this->_bits) {};

Fixed::Fixed(const float nb) {
    this->_number = roundf(nb * (1 << this->_bits));
};

float Fixed::toFloat( void ) const {

    return (this->_number / (float)(1 << this->_bits));
};


int Fixed::toInt( void ) const {

    return (this->_number >> this->_bits);
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
};