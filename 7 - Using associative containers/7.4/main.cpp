#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "split.h"

using std::cin;			using std::map;
using std::cout;		using std::string;
using std::endl;		using std::vector;
using std::istream;

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	// read the next line
	while (getline(in, line)) {
		++line_number;

		// break the input line into words
		vector<string> words = find_words(line);

		// remember that each word occurs on the current line
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {

			vector<int>& v = ret[*it];
			// if we haven't already listed the current line, do so
			if (find(v.begin(), v.end(), line_number) == v.end())
				v.push_back(line_number);
		}
	}
	return ret;
}

int main()
{
	// call xref using split by default
	map<string, vector<int> > ret = xref(cin);

	// write the results
	// the output is divided among each letter of the alphabet
	char c = '\\';
	for(map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it){

		string word = it->first;

		// check if the word starts with a different letter
		char c2 = word[0];
		if (c != c2) {
			c = c2;
			cout << endl << c << ":" << endl;
			cout << string(3, '-') << endl;
		}

		// write the word
		cout << word << " occurs on line(s): ";

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