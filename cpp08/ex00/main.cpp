#include "easyfind.hpp"

int main(){
	{
		int c[] = {1, 2, 3, 4, 5};
		std::vector<int> arr(c, c+5);
		int a = 3;
		int b = 13;

		try
		{
			easyfind(arr, a);
			easyfind(arr, b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::deque<int> arr;

		arr.push_back(2);
		arr.push_front(3);
		arr.push_back(1);

		int a = 3;
		int b = 13;

		try
		{
			easyfind(arr, a);
			easyfind(arr, b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}