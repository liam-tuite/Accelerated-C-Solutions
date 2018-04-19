// a program to calculate the average of numbers in a vector<double>
#include <iostream>
#include <vector>
#include "average.h"

using std::vector;		using std::cin;		using std::cout;
using std::endl;

int main()
{
	// ask the user to input a list of doubles
	vector<double> nums;
	double x;

	cout << "Enter a list of doubles, followed by end-of-file: ";
	while (cin >> x)
		nums.push_back(x);

	// separate input from output
	cout << endl;

	// calculate and print the average
	cout << "The average of the entered values is: " << average(nums);

	return 0;
}