#include "../includes/Fixed.hpp"
#include <cmath>
#include <algorithm>

Fixed::Fixed() : value(0) {
    // Default constructor
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
    // Integer constructor
    std::cout << "Integer constructor called" << std::endl;
    value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    // Float constructor
    std::cout << "Float constructor called" << std::endl;
    value = roundf(floatValue * epsilon);
}

Fixed::Fixed(const Fixed &other) : value(other.value) {
    // Copy constructor
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
    // Copy assignment operator
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

Fixed::~Fixed() {
    // Destructor
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const {
    // Convert to float
    return static_cast<float>(value) / epsilon;
}

int Fixed::toInt() const {
    // Convert to integer
    return value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    // Overload insertion operator
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed &other) const {
    return value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
    return value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
    return value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    ++value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    --value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}