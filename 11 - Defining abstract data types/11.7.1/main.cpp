// a program to combine two character pictures both horizontally and vertically
#include <iostream>
#include <string>
#include "character_picture.h"
#include "Vec.h"

using std::cin;		using std::endl;
using std::cout;	using std::string;

int main()
{
	Vec<string> pic1;
	pic1.push_back("this is an");
	pic1.push_back("example");
	pic1.push_back("to");
	pic1.push_back("illustrate");
	pic1.push_back("framing");

	Vec<string> pic2;
	pic2.push_back("this is yet");
	pic2.push_back("another");
	pic2.push_back("example");

	// frame both pictures
	Vec<string> frame1 = frame(pic1);
	Vec<string> frame2 = frame(pic2);

	// print horizontal concatenation
	cout << "Horizontal concatenation:" << endl
		 <<	"-------------------------" << endl;

	Vec<string> concat = hcat(frame1, frame2);
	Vec<string>::size_type i;

	for(i = 0; i < concat.size(); ++i)
		cout << concat[i] << endl;

	cout << endl;

	// print vertical concatenation
	cout << "Vertical concatenation:" << endl
		 <<	"-----------------------" << endl;

	concat = vcat(frame1, frame2);

	for(i = 0; i < concat.size(); ++i)
		cout << concat[i] << endl;

	return 0;
}
