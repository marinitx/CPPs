#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    ~Fixed();

    Fixed& operator=(const Fixed &other);

    float toFloat() const;
    int toInt() const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
