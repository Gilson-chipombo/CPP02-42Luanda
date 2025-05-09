#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int fixedPointValue;
    static const int fractionalBits = 8;

public:
    Fixed();                              // Default constructor
    Fixed(const int value);              // Int constructor
    Fixed(const float value);            // Float constructor
    Fixed(const Fixed& other);           // Copy constructor
    Fixed& operator=(const Fixed& other);// Copy assignment
    ~Fixed();                             // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
