#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Student_info.h"

using std::cin;		using std::stable_partition;
using std::cout;	using std::string;
using std::endl;	using std::vector;
using std::max;

bool p_grade(const Student_info& s)
{
	return s.grade() == 'P';
}

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

	// sort the students alphabetically. The stable_partition will maintain the students in this order, grouped by their grade
	sort(students.begin(), students.end(), compare);

	// partition the students so that those who passed are at the front of the vector, and save an iterator that points to the first fail
	typedef vector<Student_info>::const_iterator student_iter;
	student_iter fail_begin = stable_partition(students.begin(), students.end(), p_grade);

	// output the students that passed
	cout << "The following students passed: " << endl;
	for (student_iter it = students.begin(); it != fail_begin; ++it)
		cout << it->name()
		<< string(maxlen + 1 - it->name().size(), ' ') << endl;

	// output the students that failed
	cout << endl << "The following students failed: " << endl;
	for (student_iter it = fail_begin; it != students.end(); ++it)
		cout << it->name()
		<< string(maxlen + 1 - it->name().size(), ' ') << endl;
	return 0;
}