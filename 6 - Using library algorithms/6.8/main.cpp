#include <iostream>
#include <vector>
#include "Student_info.h"

using std::cin;		using std::endl;
using std::cout;	using std::vector;

vector<Student_info> extract_failed_criteria(vector<Student_info>& students, bool meets_criteria(const Student_info&)) {

	vector<Student_info> didnt;
	vector<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (!meets_criteria(*iter)) {
			didnt.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return didnt;
}

vector<Student_info> extract_didnt_do_all_hw(vector<Student_info>& students) {
	return extract_failed_criteria(students, did_all_hw);
}

bool begins_with_F(const Student_info& student) {
	return student.name[0] == 'F';
}

int main()
{
	cout << "Enter a list of student records, "
			"followed by end-of-file: " << endl;

	Student_info student;
	vector<Student_info> f_names;
	while (read(cin, student))
		f_names.push_back(student);

	vector<Student_info> other_names = extract_failed_criteria(f_names, begins_with_F);

	cout << "Students whose names begin with 'F': " << endl;
	cout << "------------------------------------" << endl;

	typedef vector<Student_info>::const_iterator iter;
	for (iter it = f_names.begin(); it != f_names.end(); ++it)
		cout << it->name << endl;

	cout << endl
		<< "Students whose names do not begin with 'F': " << endl
		<< "-------------------------------------------" << endl;

	for (iter it = other_names.begin(); it != other_names.end(); ++it)
		cout << it->name << endl;

	return 0;
}