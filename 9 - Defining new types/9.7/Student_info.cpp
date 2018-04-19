#include "Student_info.h"

using std::istream;		using std::vector;

istream& Student_info::read(istream& in)
{
	double midterm, final;
	in >> n >> midterm >> final;
	read_hw(in, homework);
	if (valid())
		final_grade = ::grade(midterm, final, homework);
	else
		final_grade = ::grade(midterm, final, 0);
	return in;
}

// read homework grades from an input stream into a vector<double>
// This is now a private member of Student_info, so it cannot be accessed publicly
istream& Student_info::read_hw(istream& in, vector<double>& hw)
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

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}