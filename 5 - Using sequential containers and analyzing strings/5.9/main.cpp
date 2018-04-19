/*	Write the words in the input that do not contain any uppercase letters followed by the words that contain one or more uppercase
	letters
 */
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;		using std::string;
using std::cout;	using std::vector;
using std::endl;

bool hasupper(const string& str)
{
	for (string::size_type i = 0; i < str.size(); ++i)
		if (isupper(str[i]))
			return true;

	return false;
}

int main()
{
	// read the input
	cout << "Enter some words, followed by end-of-file:" << endl;
	vector<string> words;
	string word;
	while(cin >> word)
		words.push_back(word);

	typedef vector<string>::size_type vec_size;

	// separate words containing uppercase letters from those that don't
	vector<string> lower, upper;
	for(vec_size i = 0; i < words.size(); ++i){

		word = words[i];

		if(hasupper(word))
			upper.push_back(word);
		else
			lower.push_back(word);
	}

	// separate input from output
	cout << endl;

	// print words that don't contain uppercase letters
	cout << "The following words do not contain uppercase letters:" << endl;
	for(vec_size i = 0; i < lower.size(); ++i)
		cout << lower[i] << endl;

	cout << endl;

	// print words that contain uppercase letters
	cout << "The following words contain uppercase letters:" << endl;
	for(vec_size i = 0; i < upper.size(); ++i)
		cout << upper[i] << endl;

	return 0;
}