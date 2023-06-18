#include "Fixed.hpp"

# include <iostream>

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    a = 2;
    bool  bo = a > b;
    std::cout << bo << std::endl;
    bo = a < b;
    std::cout << bo << std::endl;
    bo = a >= b;
    std::cout << bo << std::endl;
    bo = a <= b;
    std::cout << bo << std::endl;
    bo = a != b;
    std::cout << bo << std::endl;
    Fixed c = a + b;
    std::cout << c << std::endl;
    c = a - b;
    std::cout << c << std::endl;
    c = a * b;
    std::cout << c << std::endl;
    c = a / b;
    std::cout << c << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << Fixed::min(a, c) << std::endl;
    return 0;
}