#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Student_info.h"

using std::cin;				using std::setprecision;
using std::cout;			using std::sort;
using std::domain_error;	using std::streamsize;
using std::endl;			using std::string;
using std::max;				using std::vector;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;	// the length of the longest name

	// try to read and store all the students' data.
	//		Invariant: students contains all the student records read so far
	//				   maxlen contains the length of the longest name in students
	try {
		while (read(cin, record)) {
			// find length of longest name
			maxlen = max(maxlen, record.name.size());
			students.push_back(record);
		}
	}
	catch (domain_error e) {
		e.what();
	}

	// alphabetise the student records
	sort(students.begin(), students.end(), compare);

	streamsize prec = cout.precision();
	cout << setprecision(3);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0; i < students.size(); ++i) {
		// write the name, padded on the right to maxlen + 1 characters
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		// write the grade
		cout << students[i].grade << endl;
	}

	cout << setprecision(prec);

	return 0;
}