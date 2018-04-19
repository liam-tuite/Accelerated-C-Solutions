#pragma once

#include <algorithm>		// to get the declaration of sort
#include <stdexcept>		// to get the declaration of domain_error
#include <vector>			// to get the declaration of vector
#include "grade.h"
#include "Student_info.h"

double median(std::vector<double>);
double optimistic_median(const Student_info&);