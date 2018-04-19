#include <iostream>
#include <vector>
#include "Student_info.h"

using std::cin;		using std::endl;
using std::cout;	using std::vector;

vector<Student_info> extract_didnt_do_all_hw(vector<Student_info>& students) {

	vector<Student_info> didnt;
	vector<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (!did_all_hw(*iter)) {
			didnt.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return didnt;
}

int main()
{
	cout << "Enter a list of student records, "
			"followed by end-of-file: " << endl;

	Student_info student;
	vector<Student_info> did;
	while (read(cin, student))
		did.push_back(student);

	vector<Student_info> didnt = extract_didnt_do_all_hw(did);

	cout << "Students who did all of their homework: " << endl;
	cout << "---------------------------------------" << endl;

	typedef vector<Student_info>::const_iterator iter;
	for (iter it = did.begin(); it != did.end(); ++it)
		cout << it->name << endl;

	cout << endl
		<< "Students who did not do all of their homework: " << endl
		<< "----------------------------------------------" << endl;

	for (iter it = didnt.begin(); it != didnt.end(); ++it)
		cout << it->name << endl;

	return 0;
}