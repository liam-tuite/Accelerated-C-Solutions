#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;				using std::sort;
using std::cout;			using std::streamsize;
using std::endl;			using std::string;
using std::setprecision;	using std::vector;

// a program to calculate grades of multiple students
int main()
{
	typedef vector<double>::size_type vec_sz;
	const vec_sz num_homework_grades = 6; // this is the number of homework grades each student has
	vector<string> names;
	vector<double> grades;

	// ask for and read a student's name 
	cout << "Please enter the name of a student: ";
	string name;

	while (cin >> name) {
		// add the student's name to the names vector
		names.push_back(name);

		// ask for and read the midterm and final grades
		cout << "Please enter your midterm and final exam grades: ";
		double midterm, final;
		cin >> midterm >> final;

		// ask for and read all homework grades
		cout << "Enter all " << num_homework_grades << " homework grades, "
				"followed by end-of-file: ";
		vector<double> homework;
		double x;
		// invariant: homework contains all the homework grades read so far
		for (int i = 0; i < num_homework_grades; ++i) {
			cin >> x;
			homework.push_back(x);
		}

		// check that the student entered the right amount of homework grades
		if (homework.size() < num_homework_grades) {
			cout << endl << "You must enter " << num_homework_grades << " grades. "
							"Please try again." << endl;
			return 1;
		}

		// sort the grades
		sort(homework.begin(), homework.end());

		// compute the median homework grade
		vec_sz mid = num_homework_grades / 2;
		double median;
		median = num_homework_grades % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
												: homework[mid];

		// compute the student's final grade and add to the grades vector
		double grade;
		grade = 0.2 * midterm + 0.4 * final + 0.4 * median;
		grades.push_back(grade);

		// ask if the user wants to add another student
		cout << endl << "Do you wish to add another student record? "
						"Enter end-of-file for no." << endl;

		// ask for another student's name, or end-of-file to stop the program
		cout << "Please enter the name of a student, "
				"or end-of-file to print the results of current students: ";
	}

	// print the grades of each student
	streamsize prec = cout.precision();
	cout << endl << setprecision(3);
	for (vec_sz i = 0; i < names.size(); ++i) {
		cout << names[i] << ": " << grades[i] << endl;
	}
	cout << setprecision(prec);

	return 0;
}