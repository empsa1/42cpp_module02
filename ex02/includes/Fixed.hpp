#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int value; // To store the fixed-point number value
    static const int fractionalBits = 8; // Number of fractional bits (const for all instances)
    static const int epsilon = 1 << fractionalBits; // Smallest representable value

public:
    // Constructors
    Fixed();
    Fixed(const int intValue);
    Fixed(const float floatValue);

    // Copy constructor
    Fixed(const Fixed &other);

    // Copy assignment operator
    Fixed& operator=(const Fixed &other);

    // Destructor
    ~Fixed();

    // Member functions
    float toFloat() const;
    int toInt() const;

    // Overload insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

    // Comparison operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment and decrement operators
    Fixed& operator++(); // Pre-increment
    Fixed operator++(int); // Post-increment
    Fixed& operator--(); // Pre-decrement
    Fixed operator--(int); // Post-decrement

    // Static member functions
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
};

#endif