#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include "grade.h"
#include "median.h"

void write_analysis(std::ostream&, const std::string&, const std::vector<Student_info>&, const std::vector<Student_info>&);

template <class Func>
double analysis(const std::vector<Student_info>& students, Func function)
{
	std::vector<double> grades;

	transform(students.begin(), students.end(), std::back_inserter(grades), function);
	return median(grades);
}