#include "Serializer.hpp"

int main()
{
	Data data;

	uintptr_t raw = Serializer::serialize(&data);
	Data *return_value = Serializer::deserialize(raw);
	std::cout << "Data's address:          " << &data << std::endl;
	std::cout << "deserialize return value:" << return_value << std::endl;
}