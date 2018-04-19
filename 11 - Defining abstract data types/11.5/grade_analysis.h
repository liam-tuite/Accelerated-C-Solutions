#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include "grade.h"
#include "median.h"

void write_analysis(std::ostream&, const std::string&, double analysis(const Student_info&), const std::vector<Student_info>&,
	const std::vector<Student_info>&);
void write_analysis(std::ostream&, const std::string&, const std::vector<Student_info>&, const std::vector<Student_info>&);