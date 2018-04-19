#include <iostream>
#include <string>

using std::cout;	using std::string;
using std::endl;

int main()
{
	/* NOTE: since the spacing is different between lines than it is between columns (at least in my console view), in order to make
		the shapes look decent I've accounted for the difference. Because of this they may look weird in your view */

	// draw a square
	cout << "* * *" << endl
		 << "*   *" << endl
		 << "* * *" << endl;

	cout << endl;

	// draw a rectangle
	cout << "* * * *" << endl
		 << "*     *" << endl
		 << "* * * *" << endl;

	cout << endl;

	// draw a triangle
	cout << "  *" << endl
		 << " * *" << endl
		 << "* * *" << endl;

	return 0;
}