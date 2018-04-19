#include <iostream>
#include <string>
#include <vector>
#include "grade_analysis.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<Student_info> extract_didnt_do_all_hw(vector<Student_info>& students) {

	vector<Student_info> didnt;
	vector<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (!iter->did_all_hw()) {
			didnt.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return didnt;
}

int test(int func(), string name)
{
	cout << "Testing " << name << ":" << endl;
	cout << string(25, '-') << endl;

	int ret = func();
	Student_info::print_counters(cout);
	Student_info::reset_counters();

	return ret;
}

int test_analyses()
{
	// students who did and didn't do all their homework
	vector<Student_info> did, didnt;

	// read the student records and partition them
	cout << "Enter a list of students and their grades, followed by end-of-file:" << endl;
	Student_info student;
	while (read(cin, student)) {
		if (student.did_all_hw())
			did.push_back(student);
		else
			didnt.push_back(student);
	}

	// verify that the analyses will show us something
	if (did.empty()) {
		cout << "No students did all the homework!" << endl;
		return 1;
	}
	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	// do the analyses
	write_analysis(cout, "median", did, didnt);
	write_analysis(cout, "average", did, didnt);
	write_analysis(cout, "median of homework turned in", did, didnt);

	return 0;
}

int test_extract()
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
		cout << it->name() << endl;

	cout << endl
		<< "Students who did not do all of their homework: " << endl
		<< "----------------------------------------------" << endl;

	for (iter it = didnt.begin(); it != didnt.end(); ++it)
		cout << it->name() << endl;

	return 0;
}

int main()
{
	int ret;

	ret = test(test_analyses, "grade analysis");

	if (ret != 0)
		return ret;

	ret = test(test_extract, "extract no homework");

	return ret;
}