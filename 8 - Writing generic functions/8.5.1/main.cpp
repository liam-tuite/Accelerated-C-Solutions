#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
#include "split.h"

using std::cin;			using std::map;
using std::cout;		using std::ostream_iterator;
using std::copy;		using std::istream;
using std::endl;		using std::string;
using std::inserter;	using std::vector;

template <class Out>
Out xref(Out out, istream& in, vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int> > m;

	// read the next line
	while (getline(in, line)) {
		++line_number;

		// break the input line into words
		vector<string> words = find_words(line);

		// remember that each word occurs on the current line
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
			m[*it].push_back(line_number);
	}

	for (map<string, vector<int> >::const_iterator it = m.begin(); it != m.end(); ++it) {
		*out = *it;
	}
	return out;
}

int main()
{
	// store results in a map
	map<string, vector<int> > m;
	xref(inserter(m, m.begin()), cin);

	// write the results
	for(map<string, vector<int> >::const_iterator it = m.begin(); it != m.end(); ++it){
		// write the word
		cout << it->first << " occurs on line(s): ";

		// followed by one ore more line numbers
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it;	// write the first line number

		++line_it;
		// write the rest of the line numbers, if any
		while(line_it != it->second.end()){
			cout << ", " << *line_it;
			++line_it;
		}
		// write a new line to separate each word from the next
		cout << endl;
	}

	return 0;
}