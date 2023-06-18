#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template<typename T>
class Array
{
	public:
		Array(void) : _array(NULL), _size(0) {}
		Array(const unsigned int n) : _array(new T[n]), _size(n) {}
        Array(Array<T> const &array)
        {
            this->_size = array.size();
            this->_array = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; i++)
                this->_array[i] = array._array[i];
        }
		virtual ~Array() { if (this->_array) delete [] _array; }

		Array<T>    &operator=(Array<T> const &array)
		{
			if (this != &array)
			{
				if (this->_size > 0)
					delete [] this->_array;
				this->_size = array.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = array._array[i];
			}
			return (*this);
		}

		T	&operator[](unsigned int const &index)
		{
			if (index >= this->_size)
				throw OutOfRange();
			return (this->_array[index]);
		}

		T const	&operator[](unsigned int const &index) const
		{
			if (index >= this->_size)
				throw OutOfRange();
			return (this->_array[index]);
		}

		unsigned int	size(void) const { return (this->_size); }

		class OutOfRange : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The index is out of range");
				}
		};

	private:
		T				*_array;
		unsigned int    _size;
};

#endif