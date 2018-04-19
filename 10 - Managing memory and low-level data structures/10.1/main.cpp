#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Student_info.h"

using std::cin;			using std::setprecision;
using std::cout;		using std::streamsize;
using std::endl;		using std::string;
using std::max;			using std::vector;

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

	// write the names and whether each student passed or failed
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i){

		cout << students[i].name()
			<< string(maxlen + 1 - students[i].name().size(), ' ');

		cout << students[i].grade() << endl;
	}
	return 0;
}