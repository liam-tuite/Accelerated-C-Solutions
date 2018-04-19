#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Student_info.h"

using std::cin;				using std::setprecision;
using std::cout;			using std::streamsize;
using std::domain_error;	using std::string;
using std::endl;			using std::vector;
using std::max;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store the data
	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

		cout << students[i].name()
			<< string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}