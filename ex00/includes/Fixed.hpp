#ifndef FIXED_HPP
# define FIXED_HPP

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
    Fixed(int value);
    Fixed(const Fixed &other);
    ~Fixed();
    Fixed& operator=(const Fixed &other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
private:
    int fixedNumberValue;
    static const int numberOfFractionalBits;
};
#endif