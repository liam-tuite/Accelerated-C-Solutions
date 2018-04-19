#include "Student_info.h"

using std::istream;		using std::vector;
using std::string;

istream& Student_info::read(istream& in)
{
	double midterm, final;
	in >> n >> midterm >> final;
	read_hw(in, homework);
	if (valid())
		final_grade = ::grade(midterm, final, homework);
	else
		final_grade = ::grade(midterm, final, 0);

	g = letter_grade((midterm + final) / 2);

	return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

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

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}