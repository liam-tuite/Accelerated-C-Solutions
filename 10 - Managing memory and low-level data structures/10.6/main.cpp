#pragma once

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include "String_list.h"

using std::cin;			using std::getline;
using std::cout;		using std::isspace;
using std::endl;		using std::string;
using std::find_if;

// true if the argument is whitespace, false otherwise
bool space(char c)
{
	return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c)
{
	return !isspace(c);
}

String_list split(const string& str)
{
	String_list ret;
	typedef string::const_iterator iter;

	iter i = str.begin();
	while (i != str.end()) {
		// ignore leading blanks
		i = find_if(i, str.end(), not_space);

		// find end of next word
		iter j = find_if(i, str.end(), space);

		// copy the characters in [i, j)
		if (i != str.end())
			ret.push_back(string(i, j));

		i = j;
	}
	return ret;
}

int main()
{
	string s;
	String_list sl;
	while (getline(cin, s)) {
		sl = split(s);
		String_list::const_iterator it = sl.begin();
		cout << *it;
		while (++it != sl.end())
			cout << ", " << *it;
		cout << endl;
	}
	return 0;
}