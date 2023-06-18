#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{

}

Fixed::Fixed(const int n)
{
    this->_value = n << this->_bits;
}

Fixed::Fixed(const float f)
{
    this->_value = roundf(f * (1 << this->_bits));
}

Fixed::Fixed(Fixed const & rhs)
{
    this->_value = rhs.getRawBits();
}

Fixed::~Fixed()
{

}

Fixed & Fixed::operator=(Fixed const &f)
{
    this->_value = f.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_value / (1 << this->_bits));
}

int Fixed::toInt(void) const
{
    return (this->_value >> this->_bits);
}

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}

bool    Fixed::operator>(Fixed const &rhs) const
{
    return (this->_value > rhs._value);
}

bool    Fixed::operator<(Fixed const &rhs) const
{
    return (this->_value < rhs._value);
}

bool    Fixed::operator>=(Fixed const &rhs) const
{
    return (this->_value >= rhs._value);
}

bool    Fixed::operator<=(Fixed const &rhs) const
{
    return (this->_value <= rhs._value);
}

bool    Fixed::operator==(Fixed const &rhs) const
{
    return (this->_value == rhs._value);
}

bool    Fixed::operator!=(Fixed const &rhs) const
{
    return (this->_value != rhs._value);
}

Fixed   Fixed::operator+(Fixed const &rhs) const
{
    Fixed ret = (this->toFloat() + rhs.toFloat());
    return (ret);
}

Fixed   Fixed::operator-(Fixed const &rhs) const
{
    Fixed ret = (this->toFloat() - rhs.toFloat());
    return (ret);
}

Fixed   Fixed::operator*(Fixed const &rhs) const
{
    Fixed ret = (this->toFloat() * rhs.toFloat());
    return (ret);
}

Fixed   Fixed::operator/(Fixed const &rhs) const
{
    Fixed ret = (this->toFloat() / rhs.toFloat());
    return (ret);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp;
	tmp.setRawBits(this->_value++);
	return(tmp);
}

Fixed& Fixed::operator++(void)
{
	this->_value++;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp;
	tmp.setRawBits(this->_value--);
	return(tmp);
}

Fixed& Fixed::operator--(void)
{
	this->_value--;
	return(*this);
}

Fixed const &   Fixed::min(Fixed const & f1, Fixed const & f2)
{
    if (f1 < f2)
        return (f1);
    else
        return (f2);
}

Fixed const &   Fixed::max(Fixed const & f1, Fixed const & f2)
{
    if (f1 > f2)
        return (f1);
    else
        return (f2);
}

Fixed & Fixed::min(Fixed & f1, Fixed & f2)
{
    if (f1 < f2)
        return (f1);
    else
        return (f2);
}

Fixed & Fixed::max(Fixed & f1, Fixed & f2)
{
    if (f1 > f2)
        return (f1);
    else
        return (f2);
}