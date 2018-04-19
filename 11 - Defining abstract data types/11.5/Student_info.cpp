// Student_info.cpp
#include "Student_info.h"

using std::back_inserter;	using std::ostream;
using std::endl;			using std::remove_copy;
using std::istream;			using std::vector;

int Student_info::noargs_calls;
int Student_info::copy_calls;
int Student_info::assign_calls;
int Student_info::destroy_calls;

Student_info::Student_info(const Student_info& s)
{
	++copy_calls;

	n = s.n;
	midterm = s.midterm;
	final = s.final;
	homework = s.homework;
}

Student_info& Student_info::operator=(const Student_info& rhs)
{
	++assign_calls;

	if (&rhs != this) {
		n = rhs.n;
		midterm = rhs.midterm;
		final = rhs.final;
		homework = rhs.homework;
	}
	return *this;
}

void Student_info::reset_counters()
{
	noargs_calls = 0;
	copy_calls = 0;
	assign_calls = 0;
	destroy_calls = 0;
}

ostream& Student_info::print_counters(ostream& os)
{
	os << "noargs calls: " << noargs_calls << endl;
	os << "copy calls: " << copy_calls << endl;
	os << "assign calls: " << assign_calls << endl;
	os << "destroy calls: " << destroy_calls << endl;

	return os;
}

istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

istream& read(istream& is, Student_info& s)
{
	// read and store the student's name and midterm and final exam grades
	s.read(is);
	return is;
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

bool Student_info::did_all_hw()
{
	return ((find(homework.begin(), homework.end(), 0)) == homework.end());
}

double Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

double grade(const Student_info& s)
{
	return grade(s.get_midterm(), s.get_final(), s.get_homework());
}

double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	}
	catch (std::domain_error) {
		return grade(s.get_midterm(), s.get_final(), 0);
	}
}

double average_grade(const Student_info& s)
{
	return grade(s.get_midterm(), s.get_final(), average(s.get_homework()));
}

double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	vector<double> hw = s.get_homework();
	remove_copy(hw.begin(), hw.end(), back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(s.get_midterm(), s.get_final(), 0);
	else
		return grade(s.get_midterm(), s.get_final(), median(nonzero));
}

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw)
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