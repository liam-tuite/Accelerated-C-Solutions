#include <iostream>
#include "Vec.h"

using std::cout;	 using std::endl;

// output the elements of a Vec on a line, separated by commas
template <class T>
void output_vec(const Vec<T>& v)
{
	typename Vec<T>::const_iterator it = v.begin();
	if (it == v.end()) {
		cout << "Vec is empty." << endl;
		return;
	}

	cout << *it;
	while (++it != v.end())
		cout << ", " << *it;
	cout << endl;
}

int main()
{
	Vec<int> v;
	// add the numbers 0-5 to the Vec
	for (int i = 0; i < 6; ++i)
		v.push_back(i);
	// output initial Vec
	output_vec(v);

	// remove the third element (which is 2) from the Vec
	Vec<int>::iterator i = v.erase(v.begin() + 2);
	// output the result (should be 0, 1, 3, 4, 5)
	output_vec(v);
	// output the value immediately after the erasure (should be 3)
	cout << *i << endl;

	// clear the Vec
	v.clear();
	// output the empty Vec
	output_vec(v);

	return 0;
}