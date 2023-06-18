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
    	int		getRawBits(void) const;
    	void	setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

    private:
    	int 				_value;
    	static const int	_bits = 8;
};

std::ostream &  operator<<(std::ostream &o, Fixed const & rhs);

#endif