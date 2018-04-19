// a program to determine whether a word has any ascenders or descenders
#include <iostream>
#include <string>
#include <vector>

using std::cin;		using std::string;
using std::cout;	using std::vector;
using std::endl;

vector<char> ascenders, descenders;

bool contains(const vector<char>& vec, const char& c)
{
	for (vector<char>::size_type i = 0; i < vec.size(); ++i)
		if (vec[i] == c)
			return true;

	return false;
}

bool isascender(const char& c)
{
	return contains(ascenders, c);
}

bool isdescender(const char& c)
{
	return contains(descenders, c);
}

bool hasascender(const string& str)
{
	for (string::size_type i = 0; i < str.size(); ++i)
		if (isascender(str[i]))
			return true;

	return false;
}


bool hasdescender(const string& str)
{
	for (string::size_type i = 0; i < str.size(); ++i)
		if (isdescender(str[i]))
			return true;

	return false;
}

int main()
{
	// add ascenders and descenders to global vector
	ascenders.push_back('b');	ascenders.push_back('d');
	ascenders.push_back('f');	ascenders.push_back('h');
	ascenders.push_back('k');	ascenders.push_back('l');
	ascenders.push_back('t');

	descenders.push_back('g');	descenders.push_back('j');
	descenders.push_back('p');	descenders.push_back('q');
	descenders.push_back('y');

	// get the input
	cout << "Enter a word:" << endl;
	string word;
	cin >> word;

	// separate input from output
	cout << endl;

	// tell the user if the word has any ascenders or descenders
	if(hasascender(word))
		cout << "This word has ascenders. ";

	if(hasdescender(word))
		cout << "This word has descenders.";

	cout << endl;

	return 0;
}