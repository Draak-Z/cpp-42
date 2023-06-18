#include "Data.hpp"

Data::Data(void) : _value(42) {}

Data::Data(int value) : _value(value) {}

Data::Data(Data const &data) { this->_value = data.getValue(); }

Data::~Data(void) {}

Data	&Data::operator=(Data const &data)
{
	if (this != &data)
		this->_value = data.getValue();
	return (*this);
}

int	Data::getValue(void) const { return (this->_value); }