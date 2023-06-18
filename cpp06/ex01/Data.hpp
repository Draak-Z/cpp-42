#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	public:
		Data(void);
        Data(int value);
		virtual ~Data(void);

		int	getValue(void) const;

	private:
		Data(const Data &data);
		Data    &operator=(const Data &data);

        int	_value;
};

# endif