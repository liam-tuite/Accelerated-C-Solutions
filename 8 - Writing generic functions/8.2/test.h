#pragma once

#include <ostream>
#include <string>
#include <vector>
#include "my_templates.h"

bool isnegative(const int&);
int square(const int&);

void setup_accumulate_vecs(std::vector<int>&, std::vector<double>&);
void setup_copy_vecs(std::vector<int>&, std::vector<int>&);
void setup_equal_vecs(std::vector<int>&, std::vector<int>&);
void setup_find_vec(std::vector<int>&);
void setup_find_if_vec(std::vector<int>&);
void setup_partition_vec(std::vector<int>&);
void setup_remove_vec(std::vector<int>&);
void setup_remove_copy_vecs(std::vector<int>&, std::vector<int>&);
void setup_remove_copy_if_vecs(std::vector<int>&, std::vector<int>&);
void setup_search_vecs(std::vector<int>&, std::vector<int>&);
void setup_transform_vecs(std::vector<int>&, std::vector<int>&);

bool test_accumulate();
bool test_copy();
bool test_equal();
bool test_find();
bool test_find_if();
bool test_partition();
bool test_remove();
bool test_remove_copy();
bool test_remove_copy_if();
bool test_search();
bool test_transform();

void test(std::ostream&, const std::string&, bool());
void test_all(std::ostream&);