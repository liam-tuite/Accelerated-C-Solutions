// a program to discern between students who have passed and students who have failed

#include <stdexcept>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;				using std::endl;
using std::cout;			using std::vector;
using std::domain_error;

bool fgrade(const Student_info& s)
{
	return s.grade < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();

	int numPasses = 0;

	while(iter != students.end()){
		if(fgrade(*iter))
			fail.push_back(*iter);
		else{
			numPasses++;
			students.insert(students.begin(), iter, iter);
		}

		iter++;
	}

	students.resize(numPasses);

	return fail;
}

int main()
{
	// read in a vector of students
	vector<Student_info> pass;
	cout << "Enter a vector of students, followed by end-of-file: ";

	Student_info s;
	try{
		while(read(cin, s))
			pass.push_back(s);
	}catch(domain_error e){
		e.what();
	}

	// separate input from output
	cout << endl;

	// split into two vectors (pass and fail)
	vector<Student_info> fail = extract_fails(pass);

	// print both vectors
	cout << "Pass:" << endl
		 << "----"	<< endl;

	typedef vector<Student_info>::iterator iterator;

	for(iterator it = pass.begin(); it != pass.end(); ++it)
		cout << it->name << endl;

	cout << endl
		 << "Fail:" << endl
		 << "----"	<< endl;

	for(iterator it = fail.begin(); it != fail.end(); ++it)
		cout << it->name << endl;

	return 0;
}