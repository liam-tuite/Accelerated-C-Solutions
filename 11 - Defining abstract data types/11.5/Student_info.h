#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "average.h"
#include "grade.h"

class Student_info{
public:
	Student_info() : midterm(0), final(0) { ++noargs_calls; }
	Student_info(const Student_info&);
	Student_info(std::istream& is) { read(is); }
	Student_info& operator=(const Student_info&);
	~Student_info() { ++destroy_calls; }

	std::string name() const {return n;}
	double get_midterm() const { return midterm; }
	double get_final() const { return final; }
	std::vector<double> get_homework() const { return homework; }

	bool valid() const {return !homework.empty();}
	bool did_all_hw();
	double grade() const;

	std::istream& read(std::istream&);
	static void reset_counters();
	static std::ostream& print_counters(std::ostream&);
private:
	static int noargs_calls;
	static int copy_calls;
	static int assign_calls;
	static int destroy_calls;

	std::string n;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
double grade(const Student_info&);
double grade_aux(const Student_info&);
double average_grade(const Student_info&);
double optimistic_median(const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);