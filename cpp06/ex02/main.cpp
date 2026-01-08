#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		default:
			break;
	}
	return (new C);
}

void identify(Base* p)
{
	if (!p)
		return ;
	Base *flag[3] = {dynamic_cast<A*>(p), dynamic_cast<B*>(p), dynamic_cast<C*>(p)};
	std::string msg[3] = {"A", "B", "C"};

	int i = 0;
	while (i < 3)
	{
		if (flag[i])
		{
			std::cout << "The type of the object pointed to by p is " << msg[i] << std::endl;
			return ;
		}
		i++;
	}

}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "The type of the object referenced by p is A" << std::endl;
		return ;
	}
	catch (const std::exception&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "The type of the object referenced by p is B" << std::endl;
		return ;
	}
	catch (const std::exception&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "The type of the object referenced by p is C" << std::endl;
		return ;
	}
	catch (const std::exception&) {}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
}