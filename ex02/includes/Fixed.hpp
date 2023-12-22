#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

/*Orthodox Canonical Form in C++
    Default constructor: MyClass() : member(0) {} -> A constructor without any parameters that initializes an object with default values.
--------------------------------------------------------------------------------------------------------------------------------------------
    Copy Constructor: MyClass(const MyClass &other) : member(other.member) {} -> A constructor that creates a new object by 
        copying the values of an existing object of the same type. It takes a reference to an object of the same class as its parameter.
--------------------------------------------------------------------------------------------------------------------------------------------
    Copy Assignment Operator (operator=): MyClass& operator=(const MyClass &other) {
    if (this != &other) {
        member = other.member;
    }
    return *this;
} -> A function that assigns the values of one object to another object of the same type. 
        It returns a reference to the object being assigned to and takes a reference to an object of the same class as its parameter
--------------------------------------------------------------------------------------------------------------------------------------------
    Destructor: ~MyClass() {} -> A function that is called when an object is destroyed or goes out of scope. 
        It's responsible for releasing any resources allocated by the object. 
--------------------------------------------------------------------------------------------------------------------------------------------*/

class Fixed {
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    ~Fixed();
    Fixed& operator=(const Fixed &other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();      
    Fixed operator++(int);    
    Fixed& operator--();      
    Fixed operator--(int);

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
private:
    int fixedNumberValue;
    static const int numberOfFractionalBits;
};

//overload the insertion operator (<<) for the Fixed class. 
    //Overloading this operator enables you to define how objects of your class are 
        //represented when they are inserted into an output stream, like std::cout.
            //Basicly if u print the object in std::cout it should print what u define here
std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif