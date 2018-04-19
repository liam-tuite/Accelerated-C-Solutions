#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;		using std::map;
using std::cout;	using std::string;
using std::endl;	using std::vector;

int main(){

	string s;
	map<string, int> counters;	// store each word and an associated counter
	map<int, vector<string> > groups;

	// read the input, keeping track of each word and how often we see it
	while(cin >> s)
		++counters[s];

	// write the words and associated counts
	for(map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it)
		groups[it->second].push_back(it->first);

	// separate input from output
	cout << endl;

	for(map<int, vector<string> >::const_iterator i = groups.begin(); i != groups.end(); ++i){

		cout << "Words that occurred " << i->first << " times:" << endl;
		cout << string(10, '-') << endl;

		for(vector<string>::const_iterator j = i->second.begin(); j != i->second.end(); ++j)
			cout << *j << endl;

		cout << endl;
	}

	return 0;
}