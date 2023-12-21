#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
public:
    Fixed();  // Default constructor
    Fixed(int value);  // Parameterized constructor
    Fixed(const Fixed &other);  // Copy constructor
    ~Fixed();  // Destructor
    Fixed& operator=(const Fixed &other);  // Assignment operator
    int getRawBits( void ) const;
    void setRawBits( int const raw );
private:
    int fixedNumberValue;
    static const int numberOfFractionalBits = 8;
};

#endif