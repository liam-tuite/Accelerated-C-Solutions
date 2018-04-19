#include "grade_analysis.h"

using std::string;
using std::vector;

void write_analysis(std::ostream& out, const string& name, double analysis(const vector<Student_info>&), const vector<Student_info>& did,
	const vector<Student_info>& didnt){

	out << name << ": " << name << "(did) = " << analysis(did) <<
				   ", " << name << "(didnt) = " << analysis(didnt) << std::endl;
}

double average_analysis(const vector<Student_info>& students){

	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades),
			average_grade);
	return median(grades);
}

double median_analysis(const vector<Student_info>& students){

	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades),
			grade_aux);
	return median(grades);
}

double optimistic_median_analysis(const vector<Student_info>& students){

	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades),
			optimistic_median);
	return median(grades);
}
