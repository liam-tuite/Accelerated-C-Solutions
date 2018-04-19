// a program to print the palindromes in an input
#include <iostream>
#include <string>
#include <vector>

using std::cout;	using std::string;
using std::cin;		using std::vector;
using std::endl;

bool ispalindrome(const string& str)
{
	int lastindex = str.size() - 1;

	for (string::size_type i = 0; i < str.size() / 2 + 1; ++i)
		if (str[i] != str[lastindex - i])
			return false;

	return true;
}

string longest(const vector<string>& vec)
{
	// return the longest string in the vector
	string::size_type maxlength = 0;
	string longest;

	for (vector<string>::size_type i = 0; i < vec.size(); ++i) {

		if (vec[i].size() > maxlength) {
			longest = vec[i];
			maxlength = longest.size();
		}
	}

	return longest;
}

int main()
{
	// read the input
	cout << "Enter some words, followed by end-of-file:" << endl;
	string word;
	vector<string> words;
	while(cin >> word)
		words.push_back(word);

	typedef vector<string>::size_type vec_size;

	// find all the palindromes
	vector<string> palindromes;
	for(vec_size i = 0; i < words.size(); ++i)
		if(ispalindrome(words[i]))
			palindromes.push_back(words[i]);

	// separate input from output
	cout << endl;

	// output the palindromes
	cout << "The following words are palindromes:" << endl;
	for(vec_size i = 0; i < palindromes.size(); ++i)
		cout << palindromes[i] << endl;

	cout << endl;

	// output the longest palindrome
	cout << "The longest palindrome entered was " + longest(palindromes) + "."
		 << endl;

	return 0;
}