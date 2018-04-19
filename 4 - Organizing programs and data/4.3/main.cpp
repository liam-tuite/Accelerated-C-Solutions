// a program to calculate and print the squares of int values up to a user defined maximum
#include <iomanip>
#include <iostream>
#include <string>

using std::cin;		using std::setw;
using std::cout;	using std::streamsize;
using std::endl;	using std::string;

// computes and returns the number of digits/characters needed to express the given number
streamsize num_digits(int n)
{
	streamsize w = 0;

	while (n > 0) {
		n /= 10;
		++w;
	}

	return w;
}

int main()
{
	// ask the user for the max int
	int max;
	cout << "Enter the largest integer to square: ";
	cin >> max;

	streamsize w1 = num_digits(max);
	streamsize w2 = num_digits(max * max);

	// print the heading of the output
	cout << endl << setw(w1) << "i"
				 << setw(w2 + 2) << "i^2" << endl
				 << string(w1 + w2 + 3, '-') << endl;

	// print the square of each int in the range [1, max]
	for (int i = 1; i <= max; ++i)
		cout << setw(w1) << i << setw(w2 + 1) << i * i << endl;

	return 0;
}