#include <iostream>
#include <string>

using std::cin;		using std::endl;
using std::cout;	using std::string;

string letter_grade(double grade)
{
	// range posts for numeric grades
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};

	// names for the letter grades
	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	// computes the number of grades given the size of the array and the size of a single element
	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

	for (size_t i = 0; i < ngrades; ++i) {
		if (grade >= numbers[i])
			return letters[i];
	}

	return "?\?\?";
}

int main()
{
	double d;
	cout << "Enter a number: ";
	cin >> d;

	cout << "The grade for " << d << " is: " << letter_grade(d) << endl;
	return 0;
}