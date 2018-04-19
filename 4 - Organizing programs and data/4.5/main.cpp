/* 	a program to count the number of words in the input and how many times each
word appears
*/
#include <iostream>
#include <string>
#include <vector>

using std::cin;		using std::istream;
using std::cout;	using std::string;
using std::endl;	using std::vector;

// read words from an input stream and store them in given vector
istream& read(istream& is, vector<string>& vec)
{
	if (is) {

		vec.clear();
		string word;

		while (is >> word)
			vec.push_back(word);

		is.clear();
	}

	return is;
}

// count the number of words in a vector
int num_words(const vector<string>& vec)
{
	int count = 0;

	for (vector<string>::size_type i = 0; i < vec.size(); ++i)
		++count;

	return count;
}

// get the number of occurrences of each word in a vector
vector<int> occurrences(const vector<string>& vec)
{
	typedef vector<string>::size_type vec_sz;

	vector<int> occurrences;

	for (vec_sz i = 0; i < vec.size(); ++i) {

		string word = vec[i];
		int count = 0;

		for (vec_sz j = 0; j < vec.size(); ++j) {
			if (word == vec[j])
				++count;
		}

		occurrences.push_back(count);
	}

	return occurrences;
}

int main()
{
	// first, read the words into a vector
	cout << "Enter a list of words, followed by end-of-file: " << endl;
	vector<string> words;
	read(cin, words);

	// now count the occurrences of each word
	vector<int> counts = occurrences(words);

	// output the number of words entered, followed by the number of occurrences of each word
	cout << endl << num_words(words) << " words entered." << endl;

	for (vector<string>::size_type i = 0; i < words.size(); ++i)
		cout << "\""<< words[i] << "\" occurred " << counts[i] << " times." << endl;

	return 0;
}