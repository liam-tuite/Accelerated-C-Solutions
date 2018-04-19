#include <iostream>
#include <string>
#include <vector>

using std::cin;		using std::string;
using std::cout;	using std::vector;
using std::endl;

// a program that counts how many times each distinct word appears in its input
int main()
{
	// ask the user to input words
	vector<string> words;
	string word;
	cout << "Enter some words, "
			"followed by end-of-file: " << endl;
	while (cin >> word)
		words.push_back(word);

	// make sure at least 1 word was entered
	if (words.size() < 1) {
		cout << "Error: "
				"Please enter at least 1 word." << endl;
		return 1;
	}

	// counts will store the number of times each word in words appears
	vector<int> counts;

	/*
	for each word:
		set count to 1
		compare with preceding words
		if there is a match:
			increment count, and also increment the count of the matched occurrence
		add the final count to counts vector
	*/
	typedef vector<string>::size_type vec_sz;
	for (vec_sz i = 0; i < words.size(); ++i) {
		int count = 1;

		for (vec_sz j = 0; j < i; ++j) {
			if (words[i] == words[j]) {
				count++;
				counts[j]++;
			}
		}

		counts.push_back(count);
	}

	// output the number of times each word occurred
	cout << endl;

	for (vec_sz i = 0; i < words.size(); ++i)
		cout << words[i] << " occurred " << counts[i] << " times." << endl;

	return 0;
}