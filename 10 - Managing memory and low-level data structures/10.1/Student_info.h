#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "grade.h"

class Student_info {
public:
	Student_info() : g("F"), final_grade(0) {}
	Student_info(std::istream& is) { read(is); }
	std::string name() const { return n; }
	bool valid() const { return !homework.empty(); }
	std::istream& read(std::istream&);
	std::string grade() const { return g; }
private:
	std::string n;
	std::string g;
	double final_grade;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::string letter_grade(double);
std::istream& read_hw(std::istream&, std::vector<double>&);