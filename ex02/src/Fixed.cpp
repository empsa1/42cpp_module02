#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::numberOfFractionalBits = 8;

Fixed::Fixed() : fixedNumberValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Integer constructor called" << std::endl;
    fixedNumberValue = value << numberOfFractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    fixedNumberValue = roundf(value * (1 << numberOfFractionalBits));
}

Fixed::Fixed(const Fixed &other) : fixedNumberValue(other.fixedNumberValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        fixedNumberValue = other.fixedNumberValue;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixedNumberValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    fixedNumberValue = raw;
}

float Fixed::toFloat( void ) const {
    return ((float)this->fixedNumberValue / (float)(1 << this->numberOfFractionalBits));
}

int Fixed::toInt( void ) const {
    return (this->fixedNumberValue >> this->numberOfFractionalBits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
bool Fixed::operator>(const Fixed& other) const {
    return fixedNumberValue > other.fixedNumberValue;
}
bool Fixed::operator<(const Fixed& other) const {
    return fixedNumberValue > other.fixedNumberValue;
}
bool Fixed::operator>=(const Fixed& other) const {
    return fixedNumberValue >= other.fixedNumberValue;
}
bool Fixed::operator<=(const Fixed& other) const {
    return fixedNumberValue <= other.fixedNumberValue;
}
bool Fixed::operator==(const Fixed& other) const {
    return fixedNumberValue == other.fixedNumberValue;
}
bool Fixed::operator!=(const Fixed& other) const {
    return fixedNumberValue != other.fixedNumberValue;
}
Fixed Fixed::operator+(const Fixed& other) const {
    return this->toFloat() + other.toFloat();
}
Fixed Fixed::operator-(const Fixed& other) const {
    return this->toFloat() - other.toFloat();
}
Fixed Fixed::operator*(const Fixed& other) const {
    return this->toFloat() * other.toFloat();
}
Fixed Fixed::operator/(const Fixed& other) const {
    return this->toFloat() / other.toFloat();
}
Fixed& Fixed::operator++() {
    fixedNumberValue+=1;
    return *this;
}     
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}  
Fixed& Fixed::operator--() {
    fixedNumberValue -= 1;
    return *this;
}  
Fixed Fixed::operator--(int) {
     Fixed temp(*this);
    --(*this);
    return temp; 
}
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}