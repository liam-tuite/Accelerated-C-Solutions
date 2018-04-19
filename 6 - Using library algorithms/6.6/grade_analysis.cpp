#include "grade_analysis.h"

using std::string;
using std::vector;

void write_analysis(std::ostream& out, const string& name, double analysis(const Student_info&), const vector<Student_info>& did,
	const vector<Student_info>& didnt){

	vector<double> did_grades;
	transform(did.begin(), did.end(), back_inserter(did_grades), analysis);

	vector<double> didnt_grades;
	transform(didnt.begin(), didnt.end(), back_inserter(didnt_grades), analysis);

	out << name << ": " << name << "(did) = " << median(did_grades) <<
				   ", " << name << "(didnt) = " << median(didnt_grades) << std::endl;
}

void write_analysis(std::ostream& out, const string& name, const vector<Student_info>& did, const vector<Student_info>& didnt) {

	if (name == "average") {
		write_analysis(out, name, average_grade, did, didnt);
	}
	else if (name == "median") {
		write_analysis(out, name, grade_aux, did, didnt);
	}
	else {
		write_analysis(out, name, optimistic_median, did, didnt);
	}
}
