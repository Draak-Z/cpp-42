#include <stdint.h>
#include <iostream>
#include "Data.hpp"

uintptr_t   serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data        *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data		*data;
	uintptr_t	serialized;
	Data		*deserialized;

	data = new Data(42);
	std::cout << "Data addr : " << data << std::endl;
	std::cout << "Data value : " << data->getValue() << std::endl;
	serialized = serialize(data);
	std::cout << "serialized (value in uintptr_t) : " << serialized << std::endl;
	deserialized = deserialize(serialized);
	std::cout << "deserialized (data addr) : " << deserialized << std::endl;
	std::cout << "deserialized value = " << deserialized->getValue() << std::endl;

	delete data;
	return (0);
}