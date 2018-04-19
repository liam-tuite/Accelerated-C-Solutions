#pragma once

#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);