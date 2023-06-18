#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    public:
    	Fixed(void);
        Fixed(const int n);
        Fixed(const float f);
    	Fixed(Fixed const & rhs);
    	~Fixed(void);

    	Fixed & operator=(Fixed const &f);
    	int     getRawBits(void) const;
    	void    setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;

        bool    operator>(Fixed const &rhs) const;
        bool    operator<(Fixed const & rhs) const;
        bool    operator>=(Fixed const & rhs) const;
        bool    operator<=(Fixed const & rhs) const;
        bool    operator==(Fixed const & rhs) const;
        bool    operator!=(Fixed const & rhs) const;

        Fixed   operator+(Fixed const & rhs) const;
        Fixed   operator-(Fixed const & rhs) const;
        Fixed   operator*(Fixed const & rhs) const;
        Fixed   operator/(Fixed const & rhs) const;

        Fixed   operator++(int);
        Fixed&  operator++(void);
        Fixed   operator--(int);
        Fixed&  operator--(void);

        static Fixed const &    min(Fixed const & f1, Fixed const & f2);
        static Fixed const &    max(Fixed const & f1, Fixed const & f2);
        static Fixed &  min(Fixed & f1, Fixed & f2);
        static Fixed &  max(Fixed & f1, Fixed & f2);

    private:
    	int 				_value;
    	static const int	_bits = 8;
};

std::ostream &  operator<<(std::ostream &o, Fixed const & rhs);

#endif