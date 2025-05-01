#include "Fixed.hpp"
#include <cmath>

// Canonical
Fixed::Fixed() : _fixedPointValue(0) {}
Fixed::Fixed(const int value) { _fixedPointValue = value << _fractionalBits; }
Fixed::Fixed(const float value) { _fixedPointValue = roundf(value * (1 << _fractionalBits)); }
Fixed::Fixed(const Fixed& other) { *this = other; }
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return *this;
}
Fixed::~Fixed() {}

// Accessors
int Fixed::getRawBits(void) const { return _fixedPointValue; }
void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }
float Fixed::toFloat(void) const { return (float)_fixedPointValue / (1 << _fractionalBits); }
int Fixed::toInt(void) const { return _fixedPointValue >> _fractionalBits; }

// Comparison
bool Fixed::operator>(const Fixed& other) const { return _fixedPointValue > other._fixedPointValue; }
bool Fixed::operator<(const Fixed& other) const { return _fixedPointValue < other._fixedPointValue; }
bool Fixed::operator>=(const Fixed& other) const { return _fixedPointValue >= other._fixedPointValue; }
bool Fixed::operator<=(const Fixed& other) const { return _fixedPointValue <= other._fixedPointValue; }
bool Fixed::operator==(const Fixed& other) const { return _fixedPointValue == other._fixedPointValue; }
bool Fixed::operator!=(const Fixed& other) const { return _fixedPointValue != other._fixedPointValue; }

// Arithmetic
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment/Decrement
Fixed& Fixed::operator++() {
    ++_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++_fixedPointValue;
    return temp;
}

Fixed& Fixed::operator--() {
    --_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --_fixedPointValue;
    return temp;
}

// Min / Max
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

// Insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
