// a program to test the find_urls function
#include <iostream>
#include <string>
#include <vector>
#include "urls.h"

using std::cin;		using std::cout;
using std::endl;	using std::string;
using std::vector;

int main(){

	// read input
	cout << "Enter some text:" << endl;
	string text;
	getline(cin, text);

	// get the URLs
	vector<string> urls = find_urls(text);

	// separate input from output
	cout << endl;

	// output the URLs
	for(vector<string>::size_type i = 0; i < urls.size(); i++){
		cout << urls[i] << endl;
	}

	return 0;
}