#pragma once

#include <algorithm>
#include <string>
#include "Vec.h"

// character_picture.h (contains utilities for producing character pictures)

std::string::size_type width(const Vec<std::string>&);
Vec<std::string> frame(const Vec<std::string>&);

Vec<std::string> hcat(const Vec<std::string>&,
		const Vec<std::string>&);
Vec<std::string> vcat(const Vec<std::string>&,
		const Vec<std::string>&);