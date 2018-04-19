#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;				using std::max;
using std::cout;			using std::setprecision;
using std::domain_error;	using std::streamsize;
using std::endl;			using std::string;
using std::map;				using std::vector;

char grade_letter(const double& grade) {

	if (grade < 60)
		return 'F';
	else if (grade < 70)
		return 'D';
	else if (grade < 80)
		return 'C';
	else if (grade < 90)
		return 'B';
	else
		return 'A';
}

int main(){

	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store all the records, and find the length of the longest name
	while(read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// alphabetize the records
	sort(students.begin(), students.end(), compare);
	map<char, vector<Student_info> > grade_letters;

	typedef vector<Student_info>::const_iterator const_student_iter;

	for(const_student_iter it = students.begin(); it != students.end(); ++it){
		grade_letters[grade_letter(grade(*it))].push_back(*it);
	}

	// iterate through each letter grade
	for(map<char, vector<Student_info> >::const_iterator i = grade_letters.begin(); i != grade_letters.end(); ++i){

		// output the number of students in the group
		vector<Student_info> group = i->second;
		cout << group.size() << " students received a grade " << i->first << ":" << endl;
		cout << string(20, '-') << endl;

		// output the name of each student in this grade group
		for (const_student_iter j = group.begin(); j != group.end(); ++j)
			cout << j->name << endl;

		// end this group of students
		cout << endl;
	}

	return 0;
}