#include <iostream>
#include <string>
#include <vector>
#include "grade_analysis.h"
#include "Student_info.h"

using std::cin;		using std::ostream;
using std::cout;	using std::string;
using std::endl;	using std::vector;

int main()
{
	// students who did and didn't do all their homework
	vector<Student_info> did, didnt;

	// read the student records and partition them
	cout << "Enter a list of students and their grades, followed by end-of-file:" << endl;
	Student_info student;
	while(read(cin, student)){
		if(did_all_hw(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}

	// verify that the analyses will show us something
	if(did.empty()){
		cout << "No students did all the homework!" << endl;
		return 1;
	}
	if(didnt.empty()){
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	// do the analyses
	write_analysis(cout, "median", did, didnt);
	write_analysis(cout, "average", did, didnt);
	write_analysis(cout, "median of homework turned in", did, didnt);

	return 0;
}