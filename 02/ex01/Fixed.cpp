# include "Fixed.hpp"

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