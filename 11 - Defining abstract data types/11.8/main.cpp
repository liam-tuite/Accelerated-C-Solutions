#include <iostream>
#include "List.h"

using std::cout;	using std::endl;

int main()
{
	List<int> l;
	// add the numbers 0-5 to the list, but in jumbled order
	l.push_back(2);
	l.push_back(1);
	l.push_back(5);
	l.push_back(3);
	l.push_back(0);
	l.push_back(4);

	// output the list (should be in increasing order)
	for (List<int>::const_iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << endl;

	return 0;
}