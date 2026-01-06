#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		Dog dog1;
		dog1.getBrain()->setIdea(0, "[la3b]");
		Dog dog2 = dog1;
		dog2.getBrain()->setIdea(0, "[makla]");
		std::cout << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << dog2.getBrain()->getIdea(0) << std::endl;
	}
	{
		Animal* animals[4];

		for (int i = 0; i < 2; i++) animals[i] = new Dog();
		for (int i = 2; i < 4; i++) animals[i] = new Cat();
		for (int i = 0; i < 4; i++) animals[i]->makeSound();
		for (int i = 0; i < 4; i++) delete animals[i];
	}
	return 0;
}
