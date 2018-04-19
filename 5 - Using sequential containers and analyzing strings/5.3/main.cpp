/*	A program to discern between students who have passed and students who have failed.
	This program uses a typedef to define the type of container used to hold student records. This program works when changing the
	typedef between list<Student_info> and vector<Student_info>.
 */
#include <list>
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;				using std::endl;
using std::cout;			using std::list;
using std::domain_error;	using std::vector;

typedef list<Student_info> student_container;
//typedef vector<Student_info> student_container;

bool fgrade(const Student_info& s)
{
	return s.grade < 60;
}

student_container extract_fails(student_container& students)
{
	student_container fail;
	student_container::iterator iter = students.begin();

	while(iter != students.end()){
		if(fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}

int main()
{
	// read in a container of students
	student_container pass;
	cout << "Enter a list of students, followed by end-of-file: ";

	Student_info s;
	try{
		while(read(cin, s))
			pass.push_back(s);
	}catch(domain_error e){
		e.what();
	}

	// separate input from output
	cout << endl;

	// split into two containers (pass and fail)
	student_container fail = extract_fails(pass);

	// print both containers
	cout << "Pass:" << endl
		 << "----"	<< endl;

	typedef student_container::iterator iterator;

	for(iterator it = pass.begin(); it != pass.end(); ++it)
		cout << it->name << endl;

	cout << endl
		 << "Fail:" << endl
		 << "----"	<< endl;

	for(iterator it = fail.begin(); it != fail.end(); ++it)
		cout << it->name << endl;

	return 0;
}
