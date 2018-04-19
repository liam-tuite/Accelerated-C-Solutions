#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include "grade.h"
#include "median.h"

void write_analysis(std::ostream&, const std::string&, double analysis(const std::vector<Student_info>&), const std::vector<Student_info>&,
	const std::vector<Student_info>&);

double average_analysis(const std::vector<Student_info>&);
double median_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);