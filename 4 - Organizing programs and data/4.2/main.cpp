// a program to calculate and print the squares of int values up to 100
#include <iomanip>
#include <iostream>
#include <string>

using std::cin;		using std::setw;
using std::cout;	using std::string;
using std::endl;

int main()
{
	// print the heading of the output
	cout << endl << setw(3) << "i"
				 << setw(6) << "i^2" << endl
				 << string(11, '-') << endl;

	// print the square of each int in the range [1, 100]
	for (int i = 1; i <= 100; ++i)
		cout << setw(3) << i << setw(6) << i * i << endl;

	return 0;
}
