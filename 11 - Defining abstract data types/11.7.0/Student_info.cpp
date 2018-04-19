// Student_info.cpp
#include "Student_info.h"

using std::istream;

istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

double Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, Vec<double>& hw)
{
	if(in){
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while(in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}