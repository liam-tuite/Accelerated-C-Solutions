#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;				using std::sort;
using std::cout;			using std::string;
using std::endl;			using std::streamsize;
using std::setprecision;	using std::vector;

// Compute and print the quartiles of a set of integers
int main()
{
	// ask the user for the integers
	cout << "Please enter a set of integers, "
			"followed by end-of-file: " << endl;
	typedef vector<double> vec; // use double instead of int for precision when calculating quartiles
	vec ints;
	int i;
	while (cin >> i)
		ints.push_back(i);

	// check that at least 4 ints were given
	typedef vec::size_type vec_sz;
	vec_sz size = ints.size();
	if (size < 4) {
		cout << endl << "Error: "
				"Need at least 4 ints to produce 4 quarters";
		return 1;
	}

	// sort the vector
	sort(ints.begin(), ints.end());

	// get the second quartile, which is also the median
	vec_sz mid = size / 2;
	bool even = size % 2 == 0;
	double q2;
	q2 = even ? (ints[mid] + ints[mid - 1]) / 2
					: ints[mid];

	// split the data into two halves
	vec lower, upper;
	for (vec_sz i = 0; i < mid; ++i)
		lower.push_back(ints[i]);
	for (vec_sz i = even ? mid : mid + 1; i < size; ++i)
		upper.push_back(ints[i]);

	// compute the lower and upper quartiles
	vec_sz half_size = lower.size();
	even = half_size % 2 == 0;
	vec_sz half_mid = half_size / 2;
	double q1;
	q1 = even ? (lower[half_mid] + lower[half_mid - 1]) / 2
					: lower[half_mid];
	double q3;
	q3 = even ? (upper[half_mid] + upper[half_mid - 1]) / 2
					: upper[half_mid];

	// print the quartiles
	streamsize prec = cout.precision();
	cout << endl << "The 3 quartiles are: " << endl << setprecision(3)
		<< "Q1: " << q1 << endl
		<< "Q2: " << q2 << endl
		<< "Q3: " << q3 << setprecision(prec) << endl;

	// print the data divided into 4 quarters
	cout << "The data is divided into 4 quarters like so:" << endl;
	string separator = "---";

	for (int i = 0; i < half_mid; ++i)
		cout << lower[i] << endl;
	cout << separator << endl;
	for (int i = half_mid; i < mid; ++i)
		cout << lower[i] << endl;
	cout << separator << endl;
	for (int i = 0; i < half_mid; ++i)
		cout << upper[i] << endl;
	cout << separator << endl;
	for (int i = half_mid; i < half_size; ++i)
		cout << upper[i] << endl;

	return 0;
}