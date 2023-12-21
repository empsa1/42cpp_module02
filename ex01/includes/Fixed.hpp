#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int value; 
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const int intValue);
    Fixed(const float floatValue);

    Fixed(const Fixed &other);

    Fixed& operator=(const Fixed &other);

    ~Fixed();

    float toFloat() const;
    int toInt() const;

    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif