#include "grade_analysis.h"

using std::endl;
using std::string;
using std::vector;

void write_analysis(std::ostream& out, const string& name, const vector<Student_info>& did, const vector<Student_info>& didnt)
{
	double analysis_did, analysis_didnt;
	if (name == "median") {
		analysis_did = analysis(did, grade_aux);
		analysis_didnt = analysis(didnt, grade_aux);
	}
	else if (name == "average") {
		analysis_did = analysis(did, average_grade);
		analysis_didnt = analysis(didnt, average_grade);
	}
	else {
		analysis_did = analysis(did, optimistic_median);
		analysis_didnt = analysis(didnt, optimistic_median);
	}

	out << name << ": " << name << "(did) = " << analysis_did
				<< ", " << name << "(didnt) = " << analysis_didnt << endl;
}