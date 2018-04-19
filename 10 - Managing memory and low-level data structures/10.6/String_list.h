#pragma once

#include <list>
#include <string>

class String_list {
public:
	typedef std::list<std::string>::const_iterator const_iterator;
	typedef std::list<std::string>::iterator iterator;

	const_iterator begin() const { return strings.begin(); }
	const_iterator end() const { return strings.end(); }

	iterator begin() { return strings.begin(); }
	iterator end() { return strings.end(); }

	void push_back(std::string s) { strings.push_back(s); }
private:
	std::list<std::string> strings;
};