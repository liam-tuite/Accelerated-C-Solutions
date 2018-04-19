// a program to discern between students who have passed and students who have failed

#include <list>
#include <stdexcept>
#include "grade.h"
#include "Student_info.h"

using std::cin;				using std::endl;
using std::cout;			using std::list;
using std::domain_error;

bool fgrade(const Student_info& s)
{
	return s.grade < 60;
}

list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

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
	// read in a list of students
	list<Student_info> pass;
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

	// split into two lists (pass and fail)
	list<Student_info> fail = extract_fails(pass);

	// print both lists
	cout << "Pass:" << endl
		 << "----"	<< endl;

	typedef list<Student_info>::iterator iterator;

	for(iterator it = pass.begin(); it != pass.end(); ++it)
		cout << it->name << endl;

	cout << endl
		 << "Fail:" << endl
		 << "----"	<< endl;

	for(iterator it = fail.begin(); it != fail.end(); ++it)
		cout << it->name << endl;

	return 0;
}
