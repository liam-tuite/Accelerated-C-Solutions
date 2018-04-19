#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;		using std::string;
using std::cout;	using std::vector;
using std::endl;

// a program that reports the length of the longest and shortest strings in its input
int main()
{
	// read the input words
	cout << "Enter a list of words, "
			"followed by end-of-file: " << endl;
	vector<string> words;
	string word;
	while (cin >> word)
		words.push_back(word);

	// check that at least 1 word was entered
	if (words.size() < 1) {
		cout << "Error: "
				"Please enter at least 1 word." << endl;
		return 1;
	}

	// initialise longest and shortest variables
	string longest = words[0];
	string shortest = longest;
	typedef string::size_type string_sz;
	string_sz longest_size = longest.size();
	string_sz shortest_size = shortest.size();

	// iterate through the words and maintain the shortest and longest words found
	for (vector<string>::size_type i = 1; i < words.size(); ++i) {
		string_sz word_size = words[i].size();

		if (word_size < shortest_size) {
			shortest = words[i];
			shortest_size = shortest.size();
		}
		else if (word_size > longest_size) {
			longest = words[i];
			longest_size = longest.size();
		}
	}

	// output the results
	cout << "The shortest word was \"" << shortest << "\"." << endl;
	cout << "The longest word was \"" << longest << "\"." << endl;
	
	return 0;
}