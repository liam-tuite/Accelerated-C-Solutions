#pragma once

// permuted_index.h
#include <string>
#include <vector>

bool compare(const std::string&, const std::string&);
int get_rotations(const std::string&, std::vector<std::string>&,
		std::vector<std::string>&);
int sort(std::vector<std::string>&, std::vector<std::string>&);