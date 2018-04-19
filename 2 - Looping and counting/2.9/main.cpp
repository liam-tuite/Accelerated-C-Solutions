#include <iostream>

using std::cin;		using std::endl;
using std::cout;

int main()
{
	int a, b;

	// ask the user for two numbers
	cout << "Enter two numbers: " << endl;

	// read the numbers
	cin >> a >> b;

	if (a == b)
		cout << a << " = " << b << endl;
	else
		a < b ? cout << a << " < " << b : cout << a << " > " << b;

	return 0;
}