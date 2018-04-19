#include<iostream>

int main()
{
	int product = 1;

	for (int i = 2; i < 10; ++i)
		product *= i;

	std::cout << product << std::endl;

	return 0;
}