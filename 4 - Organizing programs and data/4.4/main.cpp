// a program to calculate and print the squares of int values (as doubles) up to a user defined maximum
#include <iomanip>
#include <iostream>
#include <string>

using std::cin;				using std::setw;
using std::cout;			using std::streamsize;
using std::endl;			using std::string;
using std::setprecision;

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
	// this is the number of decimal places to be used when printing the output
	const int precision = 1;

	// ask the user for the max int
	double max;
	cout << "Enter the largest integer to square: ";
	cin >> max;

	streamsize w1 = num_digits(max);
	streamsize w2 = num_digits(max * max) + precision;

	// print the heading of the output
	cout << endl << setw(w1 + 2) << "i"
				 << setw(w2 + 4) << "i^2" << endl
				 << string(w1 + w2 + 7, '-') << endl;


	/*	std::fixed is needed to see the decimal points with trailing zeroes. A double with a value of 1.0 will be printed to
		std::cout as "1", even after setting the precision of cout, unless
		std::fixed is used.
	*/
	streamsize prec = cout.precision();
	cout << std::fixed << setprecision(precision);

	// print the square of each int in the range [1, 100]
	for (double i = 1; i <= max; i += 1)
		cout << setw(w1 + 2) << i << setw(w2 + 3) << i * i << endl;

	cout << setprecision(prec);

	return 0;
}