#include <iostream>
#include <string>
#include <vector>

using std::cin;		using std::string;
using std::cout;	using std::vector;
using std::endl;

string::size_type maxlength(const vector<string>& vec)
{
	string::size_type maxlength = 0;

	for (vector<string>::size_type i = 0; i < vec.size(); ++i)
		if (vec[i].size() > maxlength)
			maxlength = vec[i].size();

	return maxlength;
}

vector<string> center(const vector<string>& message)
{
	/*
	Return a picture in which all the lines of the message are padded out to their full width, and the padding is as evenly
	divided as possible between the left and right sides of the picture.
	*/
	vector<string> ret;

	string::size_type longest = maxlength(message);

	string asterisks = string(longest + 4, '*');
	ret.push_back(asterisks);

	for (vector<string>::size_type i = 0; i < message.size(); ++i) {

		string line = message[i];
		string str = "* ";

		int spaces = longest - line.size();

		str += string(spaces / 2, ' ');
		str += line;
		str += string(longest + 2 - str.size(), ' ');
		str += " *";

		ret.push_back(str);
	}

	ret.push_back(asterisks);

	return ret;
}

int main()
{
	vector<string> message;
	message.push_back("this");
	message.push_back("is");
	message.push_back("a");
	message.push_back("sample");
	message.push_back("message");

	// get the picture
	vector<string> picture = center(message);

	// separate input from output
	cout << endl;

	// output the picture
	for(vector<string>::size_type i = 0; i < picture.size(); ++i)
		cout << picture[i] << endl;

	return 0;
}