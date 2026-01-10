#include "Array.hpp"

int main()
{
    std::cout << "=== Test 1: default constructor ===\n";
    Array<int> a;
    std::cout << "size: " << a.size() << "\n";

    std::cout << "\n=== Test 2: constructor with size ===\n";
    Array<int> b(5);
    std::cout << "size: " << b.size() << "\n";
    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i * 10;

    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << "b[" << i << "] = " << b[i] << "\n";

    std::cout << "\n=== Test 3: copy constructor (deep copy) ===\n";
    Array<int> c(b);
    c[0] = 999;

    std::cout << "b[0] = " << b[0] << " (should be 0)\n";
    std::cout << "c[0] = " << c[0] << " (should be 999)\n";

    std::cout << "\n=== Test 4: assignment operator (deep copy) ===\n";
    Array<int> d;
    d = b;
    d[1] = 777;

    std::cout << "b[1] = " << b[1] << " (should be 10)\n";
    std::cout << "d[1] = " << d[1] << " (should be 777)\n";

    std::cout << "\n=== Test 5: out of bounds exception ===\n";
    try {
        std::cout << b[100] << "\n";
    }
    catch (std::exception &e) {
        std::cout << "Caught exception ✅ (out of bounds)\n";
    }

    std::cout << "\n=== Test 6: works with strings ===\n";
    Array<std::string> s(3);
    s[0] = "hello";
    s[1] = "world";
    s[2] = "!";
    for (unsigned int i = 0; i < s.size(); i++)
        std::cout << s[i] << " ";
    std::cout << "\n";
	
    return 0;
}
