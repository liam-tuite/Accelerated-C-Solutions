// a program to test the new split function (using iterators rather than indices)
#include <iostream>
#include <string>
#include <vector>
#include "split.h"

using std::cin;		using std::string;
using std::cout;	using std::vector;
using std::endl;

int main(){

	// get the input sentence
	cout << "Enter a sentence:" << endl;
	string str;
	getline(cin, str);

	// get the words in the sentence
	vector<string> words = split(str);

	// separate input from output
	cout << endl;

	// output the words
	for(vector<string>::size_type i = 0; i < words.size(); ++i){
		cout << words[i] << endl;
	}

	return 0;
}
