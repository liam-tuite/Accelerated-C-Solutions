#include <fstream>
#include <iostream>
#include <string>

using std::endl;		using std::ofstream;
using std::ifstream;	using std::string;

int main()
{
	ifstream infile("in");
	ofstream outfile("out");

	string s;

	while (getline(infile, s))
		outfile << s << endl;
	return 0;
}